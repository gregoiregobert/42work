
import sys
import pickle
import numpy as np
import pandas as pd
from sklearn.metrics import accuracy_score
from sklearn.preprocessing import StandardScaler


def load_df():
    folder = "/Users/gregoiregobert/Downloads/42" #mac perso
    folder = "/home/ggobert/Downloads" #42
    arg = sys.argv[1]
    df = pd.read_csv(folder + "/datasets/" + arg)

    return df

def sigmoid(z):
    return 1 / (1 + np.exp(-z))

def predict_one_vs_all(X, all_weights):
    m = X.shape[0]
    X_bias = np.hstack([np.ones((m, 1)), X])
    probs = sigmoid(X_bias @ all_weights.T)  # shape (m, num_classes)
    return np.argmax(probs, axis=1)

def normalize_data(df):
    X_test = df[['Herbology', 'Astronomy']].to_numpy()

    scaler = StandardScaler()
    X_train_scaled = scaler.fit_transform(X_test)
    
    return X_train_scaled

def main():
    with open("weights.pkl", "rb") as f:
        weights = pickle.load(f)
    df = load_df()
    X_test_scaled = normalize_data(df)
    y_pred = predict_one_vs_all(X_test_scaled, weights)


if __name__ == "__main__":
    main()
