from sklearn.feature_extraction.text import CountVectorizer
import numpy as np
import argparse
import importlib
from os import path
import sys


def run_tests(test_cases):

    # Defining the training sentences and categories
    sentences = [
        "The new smartphone has a stunning display and battery life.",  # Technology
        "Traveling to Japan was a dream come true.",  # Travel
        "The latest movie has been a box office hit.",  # Entertainment
        "AI is transforming the future of work.",  # Technology
        "Exploring the ancient ruins was a memorable experience.",  # Travel
        "The concert was an unforgettable experience.",  # Entertainment
        "5G networks are rolling out across the globe.",  # Technology
        "Hiking in the Alps offers breathtaking views.",  # Travel
        "The streaming platform has released new shows.",  # Entertainment
        "Electric cars are the future of transportation.",  # Technology
        "Traveling to tropical islands is a fantastic getaway.",  # Travel
        "Missing label",  # Missing label (noise)
        "Virtual reality is reshaping gaming.",  # Technology
        "Incorrect label"  # Incorrect label (noise)
    ]

    categories = [
        "technology", "travel", "entertainment", "technology", "travel", "entertainment", 
        "technology", "travel", "entertainment", "technology", "travel", None, 
        "technology", "wrong_label"
    ]
    
    try:
        # Preprocessing step
        sentences, categories = NaiveBayesClassifier.preprocess(sentences, categories)
    except Exception as e:
        print(f'\nError in preprocess function:\n{e}')
        sys.exit(1)

    try:
        # Vectorizing the text data using CountVectorizer
        vectorizer = CountVectorizer()
        X_train_vec = vectorizer.fit_transform(sentences)
    except Exception as e:
        print(f'\nError in vectorizing output of preprocess fucntion:\n{e}')
        sys.exit(1)

    try:
        # Fitting the Naive Bayes model
        class_probs, word_probs = NaiveBayesClassifier.fit(X_train_vec.toarray(), categories)
    except Exception as e:
        print(f'\nError in fit function:\n{e}')
        sys.exit(1)
    try:
       NaiveBayesClassifier.wordFreq(sentences)
    except Exception as e:
       print(f'\nError in plotting word frequencies:\n{e}')
       sys.exit(1)

    num_passed = 0

    try:
        print()
        for test_sentence, correct_category in test_cases:
            test_vector = vectorizer.transform([test_sentence]).toarray()
            prediction = NaiveBayesClassifier.predict(test_vector, class_probs, word_probs, np.unique(categories))[0]

            if prediction == correct_category:
                print(f"Test Passed: '{test_sentence}' - Predicted: {prediction} | Correct: {correct_category}")
                num_passed += 1
            else:
                print(f"Test Failed: '{test_sentence}' - Predicted: {prediction} | Correct: {correct_category}")
    except Exception as e:
        print(f'\nError in counting checking test cases:\n{e}')
        sys.exit(1)

    return num_passed


if __name__ == "__main__":

    parser = argparse.ArgumentParser(usage=f"python {path.basename(__file__)} --id CAMPUS_SECTION_SRN_Lab6.py")
    parser.add_argument("--id", required=True, help="where ID is CAMPUS_SECTION_SRN_Lab6.py")
    args = parser.parse_args()
    module = importlib.import_module(args.id.rstrip(".py"))
    NaiveBayesClassifier = module.NaiveBayesClassifier

    test_cases = [
        ("The smartphone has amazing battery life.", "technology"),
        ("Exploring the ancient temples in Angkor Wat is a breathtaking experience.", "travel"),
        ("The movie was a box office hit.", "entertainment"),
        ("AI will shape the future of transportation.", "technology"),
        ("Traveling through Europe has been a life-changing experience.", "travel"),
        ("The concert was mind-blowing.", "entertainment"),
        ("The latest advancements in electric cars are impressive.", "technology"),
        ("A road trip across the country offers countless adventures.", "travel"),
        ("The latest blockbuster movie kept everyone on the edge of their seats.", "entertainment"),
        ("The impact of technology on our daily lives is profound.", "technology")
    ]

    num_passed = run_tests(test_cases)
    print(f"\nNumber of Test Cases Passed: {num_passed} out of {len(test_cases)}")
    
    
