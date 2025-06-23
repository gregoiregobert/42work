from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import pickle


def encode_house(df):
    classes = sorted(df['Hogwarts House'].unique())

    # Encodage : texte → entier
    label_to_int = {label: idx for idx, label in enumerate(classes)}

    # Décodage : entier → texte
    int_to_label = {idx: label for label, idx in label_to_int.items()}

    # Encodage
    df['House_encoded'] = df['Hogwarts House'].map(label_to_int)
    
    return df

def load_clean_df():
    folder = "/Users/gregoiregobert/Downloads/42" #mac perso
    folder = "/home/ggobert/Downloads" #42
    df = pd.read_csv(folder + "/datasets/dataset_train.csv")

    # Maison -> gryffondor = 0, serpentard = 1 ... etc
    df = encode_house(df)

    # Supression des nulls
    df_clean = df[(df['Herbology'].notna()) & (df['Astronomy'].notna())].copy()

    y = df_clean['House_encoded'].to_numpy()
    X = df_clean[['Herbology', 'Astronomy']].to_numpy()

    X_train, X_test, y_train, y_test = train_test_split(
        X, y,
        test_size=0.2,
        random_state=42,
        stratify=y  # Garde la même répartition des classes
    )
    return X_train, X_test, y_train, y_test 


def normalize(X_train, X_test):
    scaler = StandardScaler()
    X_train_scaled = scaler.fit_transform(X_train)
    X_test_scaled = scaler.transform(X_test)

    return X_train_scaled, X_test_scaled


def sigmoid(z):
    return 1 / (1 + np.exp(-z))


def loss_and_gradient(X, y, w):
    m = X.shape[0]
    z = X @ w
    h = sigmoid(z)
    loss = -np.mean(y * np.log(h + 1e-8) + (1 - y) * np.log(1 - h + 1e-8))
    gradient = (1 / m) * X.T @ (h - y)
    return loss, gradient


def train_logistic_one_vs_all(X, y, lr, epochs):
    n_samples, n_features = X.shape
    n_classes_to_predict = 4
    weights = np.zeros((n_classes_to_predict, n_features + 1))  # +1 pour le biais
    losses_per_class = []

    # Ajoute la colonne de biais (1)
    X_bias = np.c_[np.ones((n_samples, 1)), X]

    for c in range(n_classes_to_predict):
        y_binary = (y == c).astype(int)
        w = np.zeros(n_features + 1)
        losses = []

        for epoch in range(epochs):
            z = np.dot(X_bias, w)
            pred = 1 / (1 + np.exp(-z))
            epsilon = 1e-15  # pour éviter log(0)
            pred = np.clip(pred, epsilon, 1 - epsilon)

            loss, gradient = loss_and_gradient(X_bias, y_binary, w)
            losses.append(loss)
            w -= lr * gradient

        weights[c] = w
        losses_per_class.append(losses)

    return weights, losses_per_class


def print_log_loss(losses_per_class):
    for i, losses in enumerate(losses_per_class):
        plt.plot(losses, label=f"Classe {i}")

    plt.xlabel("Époque")
    plt.ylabel("Perte (loss)")
    plt.title("Courbe de coût par classe")
    plt.legend()
    plt.grid(True)
    plt.show()

def main():
    X_train, X_test, y_train, y_test  = load_clean_df()
    X_train_scaled, X_test_scaled = normalize(X_train, X_test)
    weights, losses_per_class = train_logistic_one_vs_all(X_train_scaled, y_train, lr=10, epochs=20)
    print_log_loss(losses_per_class)
    with open("weights.pkl", "wb") as f:
        pickle.dump({"weights": weights, "X_test_scaled":X_test_scaled, "y_test":y_test}, f)

if __name__ == '__main__':
    main()
