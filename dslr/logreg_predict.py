
import pickle
import numpy as np
from sklearn.metrics import accuracy_score


def sigmoid(z):
    return 1 / (1 + np.exp(-z))

def predict_one_vs_all(X, all_weights):
    m = X.shape[0]
    X_bias = np.hstack([np.ones((m, 1)), X])
    probs = sigmoid(X_bias @ all_weights.T)  # shape (m, num_classes)
    return np.argmax(probs, axis=1)

def main():
    with open("weights.pkl", "rb") as f:
        data = pickle.load(f)
        weights = data["weights"]
        X_test_scaled = data["X_test_scaled"]
        y_test = data["y_test"]

    y_pred = predict_one_vs_all(X_test_scaled, weights)
    accuracy = accuracy_score(y_test, y_pred)
    print(f"Précision : {accuracy:.2f}")

if __name__ == "__main__":
    main()
