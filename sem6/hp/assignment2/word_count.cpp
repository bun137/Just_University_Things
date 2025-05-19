#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <omp.h>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

std::string readFile(const std::string &filename) {
  std::ifstream file(filename, std::ios::binary);
  if (!file) {
    throw std::runtime_error("Cannot open file: " + filename);
  }

  file.seekg(0, std::ios::end);
  size_t size = file.tellg();
  std::string content(size, ' ');
  file.seekg(0);
  file.read(&content[0], size);

  return content;
}

std::vector<std::string> splitIntoChunks(const std::string &content,
                                         int num_chunks) {
  std::vector<std::string> chunks;
  size_t chunk_size = content.size() / num_chunks;
  size_t pos = 0;

  for (int i = 0; i < num_chunks - 1; ++i) {
    size_t end = pos + chunk_size;

    while (end < content.size() && !std::isspace(content[end])) {
      end++;
    }

    chunks.push_back(content.substr(pos, end - pos));
    pos = end;
  }

  chunks.push_back(content.substr(pos));
  return chunks;
}

std::unordered_map<std::string, int> countWords(const std::string &text) {
  std::unordered_map<std::string, int> word_count;
  std::istringstream iss(text);
  std::string word;

  while (iss >> word) {
    word.erase(std::remove_if(word.begin(), word.end(),
                              [](char c) { return std::ispunct(c); }),
               word.end());

    std::transform(word.begin(), word.end(), word.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    if (!word.empty()) {
      word_count[word]++;
    }
  }

  return word_count;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
    return 1;
  }

  double start_time = omp_get_wtime();

  try {
    std::string filename = argv[1];
    std::string content = readFile(filename);

    int num_threads = omp_get_max_threads();
    std::cout << "Processing with " << num_threads << " threads" << std::endl;

    std::vector<std::string> chunks = splitIntoChunks(content, num_threads);
    std::vector<std::unordered_map<std::string, int>> thread_results(
        num_threads);

// Process chunks in parallel
#pragma omp parallel num_threads(num_threads)
    {
      int tid = omp_get_thread_num();
      if (tid < chunks.size()) {
        thread_results[tid] = countWords(chunks[tid]);
#pragma omp critical
        {
          std::cout << "Thread " << tid << " processed " << chunks[tid].size()
                    << " bytes" << std::endl;
        }
      }
    }

    std::unordered_map<std::string, int> global_count;
    for (const auto &local_count : thread_results) {
      for (const auto &[word, count] : local_count) {
        global_count[word] += count;
      }
    }

    std::vector<std::pair<std::string, int>> sorted_words(global_count.begin(),
                                                          global_count.end());
    std::sort(sorted_words.begin(), sorted_words.end(),
              [](const auto &a, const auto &b) { return a.second > b.second; });

    std::cout << "\nTop 10 words by frequency:" << std::endl;
    for (int i = 0; i < std::min(10, (int)sorted_words.size()); ++i) {
      std::cout << sorted_words[i].first << ": " << sorted_words[i].second
                << std::endl;
    }

    size_t total_words = 0;
    for (const auto &pair : global_count) {
      total_words += pair.second;
    }

    double end_time = omp_get_wtime();
    std::cout << "\nTotal words: " << total_words << std::endl;
    std::cout << "Unique words: " << global_count.size() << std::endl;
    std::cout << "Processing time: " << (end_time - start_time) << " seconds"
              << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
