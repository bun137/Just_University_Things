import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC, SVR
from sklearn.metrics import accuracy_score, mean_absolute_percentage_error
import matplotlib.pyplot as plt
from sklearn.model_selection import GridSearchCV


# SVM classification class
class SVM_Classification:
    def _init_(self) -> None:
        self.mdl = None

    def dataset_read(self, dataset_path):

        d = pd.read_json(dataset_path)

        X = d.iloc[:, :-1]
        y = d.iloc[:, -1]

        return X, y

    def preprocess(self, X, y):

        X.fillna(X.mean(), inplace=True)

        sc = StandardScaler()
        X_scali = sc.fit_transform(X)

        return X_scali, y

    def train_classification_model(self, X_train, y_train):

        self.mdl = SVC()
        self.mdl.fit(X_train, y_train)

    def predict_accuracy(self, X_test, y_test):
        y_pred = self.mdl.predict(X_test)
        acc = accuracy_score(y_test, y_pred)
        return acc


# SVM regression class
class SVM_Regression:
    def _init_(self) -> None:
        self.mdl = None

    def dataset_read(self, dataset_path):

        d = pd.read_json(dataset_path)
    
        X = d.iloc[:, :-1]
        y = d.iloc[:, -1]
        
        return X, y

    def preprocess(self, X, y):

        X.fillna(X.mean(), inplace=True)

        sc = StandardScaler()
        X_scali = sc.fit_transform(X)

        return X_scali, y

    def train_regression_model(self, X_train, y_train):

        self.mdl = SVR()
        self.mdl.fit(X_train, y_train)

    def predict_accuracy(self, X_test, y_test):

        y_pred = self.mdl.predict(X_test)
        err = mean_absolute_percentage_error(y_test, y_pred)

        return 1 - err

    def visualize(self, X_test, y_test, y_pred):

        plt.figure(figsize=(10, 6))

        plt.scatter(X_test, y_test, color='blue', alpha=0.6, edgecolor='k', label='Actual Target')
        plt.scatter(X_test, y_pred, color='red', alpha=0.6, edgecolor='k', label='Predicted Target')

        plt.title('X vs Target')
        plt.xlabel('X')
        plt.ylabel('Target')
        plt.legend()
        plt.grid(True)

        plt.show()


# SVM Spiral Classification class
class SVM_Spiral:
    def _init_(self) -> None:
        self.mdl = None

    def dataset_read(self, dataset_path):

        df = pd.read_json(dataset_path)

        X = df.iloc[:, :-1]
        y = df.iloc[:, -1]

        return X, y

    def preprocess(self, X, y):

        X = X.fillna(X.mean())

        sc = StandardScaler()
        X_scali = sc.fit_transform(X)

        return X_scali, y

    def train_spiral_model(self, X_train, y_train):

        param_grid = {
            'kernel': ['rbf', 'sigmoid', 'linear'],
            'C': [0.1, 1, 10, 100],
            'gamma': ['scale', 'auto', 0.1, 1, 10]
        }
        gs = GridSearchCV(SVC(), param_grid, cv=5, scoring='accuracy', verbose=0)

        gs.fit(X_train, y_train)

        self.mdl = gs.best_estimator_

    def predict_accuracy(self, X_test, y_test):

        y_pred = self.mdl.predict(X_test)
        acc = accuracy_score(y_test, y_pred)

        return acc
