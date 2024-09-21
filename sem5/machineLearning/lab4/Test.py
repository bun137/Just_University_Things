import sys
import importlib
import argparse
import numpy as np
import pandas as pd
import warnings

warnings.filterwarnings("ignore")

# Parse command-line arguments
parser = argparse.ArgumentParser()
parser.add_argument("--ID", required=True, help="ID for the test (module name)")
parser.add_argument("--filepath", required=True, help="Path to the dataset file")
args = parser.parse_args()

subname = args.ID
filepath = args.filepath

# Attempt to import the user-provided module
try:
    mymodule = importlib.import_module(subname)
except Exception as e:
    print("Rename your written program as CAMPUS_SECTION_SRN_Lab4.py and run python Test.py --ID CAMPUS_SECTION_SRN_Lab4 --filepath <file_path>")
    sys.exit()

split_and_standardize = mymodule.split_and_standardize
create_model = mymodule.create_model
predict_and_evaluate = mymodule.predict_and_evaluate

def test_case():
    # Load the dataset from the provided filepath
    df = pd.read_csv(filepath)

    # Move 'garbage_column' after the second column
    cols = df.columns.tolist()
    garbage_index = cols.index('garbage_column')
    
    # Move it to the position after the second column
    cols.insert(2, cols.pop(garbage_index))
    df = df[cols]

    X = df.drop(columns='quality').values  # Assuming 'quality' is the label column
    y = df['quality'].values

    model1 = model2 = None
    X_train = X_test = y_train = y_test = None

    try:
        X_train, X_test, y_train, y_test = split_and_standardize(X, y)
        if ((X_train.shape[0] + X_test.shape[0]) == X.shape[0] and 
            X.shape[0] == (y_train.shape[0] + y_test.shape[0]) and 
            np.allclose(np.mean(X_train), 0, atol=1e-1) and 
            np.allclose(np.mean(X_test), 0, atol=1e-1)):
            print("Test Case 1 for the function split_and_standardize PASSED")
        else:
            print("Test Case 1 for the function split_and_standardize FAILED")
    except Exception as e:
        print(e)
        print("Test Case 1 for the function split_and_standardize FAILED [ERROR]")

    try:
        model1, model2 = create_model(X_train, y_train) 
        if (len(model1.get_params()['hidden_layer_sizes']) == 3 and 
            len(model2.get_params()['hidden_layer_sizes']) == 3):
            print("Test Case 2 for the function create_model PASSED")
        else:
            print("Test Case 2 for the function create_model FAILED")
    except Exception as e:
        print(e)
        print("Test Case 2 for the function create_model FAILED [ERROR]")

    try:
        accuracy, precision, recall, fscore, conf_matrix = predict_and_evaluate(model1, X_test, y_test)
        if (accuracy >= 0.60 ):
            print("Test Case 3 for the function predict_and_evaluate PASSED")
        else:
            print("Test Case 3 for the function predict_and_evaluate FAILED")
    except Exception as e:
        print(e)
        print("Test Case 3 for the function predict_and_evaluate FAILED [ERROR]")

    try:
        accuracy, precision, recall, fscore, conf_matrix = predict_and_evaluate(model2, X_test, y_test)
        if (0.5 <= accuracy <= 0.9):
            print("Test Case 4 for the function predict_and_evaluate PASSED")
        else:
            print("Test Case 4 for the function predict_and_evaluate FAILED")
    except Exception as e:
        print(e)
        print("Test Case 4 for the function predict_and_evaluate FAILED [ERROR]")

if __name__ == "__main__":
    test_case()
