import numpy as np
from sklearn.feature_extraction.text import ENGLISH_STOP_WORDS
import matplotlib.pyplot as plt

class NaiveBayesClassifier:
    @staticmethod
    def preprocess(sentences: list, categories: list) -> tuple:
        """
        Preprocess the dataset to remove missing or incorrect labels and balance the dataset.

        Args:
            sentences (list): List of sentences to be processed.
            categories (list): List of corresponding labels.

        Returns:
            tuple: A tuple of two lists - (niceSentense, niceCat).
        """

        niceSentence = []
        niceCat = []

        for sentence, category in zip(sentences, categories):
            if category is not None and category != "wrong_label":
                filterSentence = ' '.join(filter(lambda word: word.lower() not in ENGLISH_STOP_WORDS, sentence.split()))
                niceSentence.append(filterSentence)
                niceCat.append(category)

        return niceSentence, niceCat

    @staticmethod
    def fit(X: np.ndarray, y: np.ndarray) -> tuple:
        """
        Trains the Naive Bayes Classifier using the provided training data.
        
        Args:
            X (numpy.ndarray): The training data matrix where each row represents a document
                              and each column represents the presence (1) or absence (0) of a word.
            y (numpy.ndarray): The corresponding labels for the training documents.

        Returns:
            tuple: A tuple containing two dictionaries:
                - class_probs (dict): Prior probabilities of each class in the training set.
                - word_probs (dict): Conditional probabilities of words given each class.
        """
        
        classes, class_counts = np.unique(y, return_counts=True)
        class_probs = {cls: count / len(y) for cls, count in zip(classes, class_counts)}

        word_probs = {c: np.ones(X.shape[1]) for c in classes}

        for i, c in enumerate(y):
            word_probs[c] += X[i]

        for c in classes:
            total_words_in_class = np.sum(word_probs[c])
            word_probs[c] /= total_words_in_class

        return class_probs, word_probs


    @staticmethod
    def predict(X: np.ndarray, class_probs: dict, word_probs: dict, classes: np.ndarray) -> list:
        """
        Predicts the classes for the given test data using the trained classifier.
        
        Args:
            X (numpy.ndarray): The test data matrix where each row represents a document
                              and each column represents the presence (1) or absence (0) of a word.
            class_probs (dict): Prior probabilities of each class in the training set.
            word_probs (dict): Conditional probabilities of words given each class.
            classes (numpy.ndarray): Array of unique class labels.

        Returns:
            list: Predicted class labels for each document in the test data.
        """
        # TO DO
        predictions = []

        for doc in X:
            log_probs = {}
            for cls in classes:
                log_prob = np.log(class_probs[cls])
                word_prob = word_probs[cls]
                log_prob += np.sum(doc * np.log(word_prob) + (1 - doc) * np.log(1 - word_prob))
                log_probs[cls] = log_prob

            predicted_class = max(log_probs, key=log_probs.get)
            predictions.append(predicted_class)

        return predictions

    @staticmethod
    def wordFreq(sentences: list):
        """
        Plots a bar graph of word frequencies in the training dataset.

        Args:
            sentences (list): List of processed sentences.
        """
        
        word_freq = {}
        
        for sentence in sentences:
            for word in sentence.split():
                word = word.lower() 
                if word not in ENGLISH_STOP_WORDS: 
                    if word in word_freq:
                        word_freq[word] += 1
                    else:
                        word_freq[word] = 1
        
        common_words = sorted(word_freq.items(), key=lambda x: x[1], reverse=True)
        words, frequencies = zip(*common_words)

        plt.figure(figsize=(10, 6))
        plt.bar(words, frequencies)
        plt.xlabel('Words')
        plt.ylabel('Frequency')
        plt.title('Word Frequencies in Training Dataset')
        plt.xticks(rotation=45)
        plt.show()


    



