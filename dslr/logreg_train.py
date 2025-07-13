import sys
import pickle
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.metrics import accuracy_score
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split


def encode_house(df):
    houses = {
        'Gryffindor':0,
        'Hufflepuff':1,
        'Ravenclaw':2,
        'Slytherin':3
    }

    # Encodage
    df['House_encoded'] = df['Hogwarts House'].map(houses)
    
    return df


def load_clean_df():
    folder = "/home/ggobert/Downloads" #42
    folder = "/Users/gregoiregobert/Downloads/42" #mac perso
    try:
        arg = sys.argv[1]
    except:
        print('No arguments')
        exit()
    try:
        df = pd.read_csv(folder + "/datasets/" + arg)
    except:
        print("dataset not found")
        exit()

    # Maison -> gryffondor = 0, serpentard = 1 ... etc
    df = encode_house(df)

    # Supression des nulls
    df_clean = df[(df['Herbology'].notna()) & (df['Astronomy'].notna())].copy()

    y = df_clean['House_encoded'].to_numpy()
    X = df_clean[['Herbology', 'Astronomy']].to_numpy()

    X_train, X_test, y_train, y_test = train_test_split(
        X, y,
        test_size=0.2,
        stratify=y,  # Garde la même répartition des classes
        # random_state=1 # si on veut avoir un resultat optimal à chaque fois
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


def train_logistic_one_vs_all_stochastic(X, y, lr, epochs):
    n_samples, n_features = X.shape
    n_classes_to_predict = 4
    weights = np.zeros((n_classes_to_predict, n_features + 1))  # +1 pour le biais
    losses_per_class = []

    # Ajout du biais
    X_bias = np.c_[np.ones((n_samples, 1)), X]

    for c in range(n_classes_to_predict):
        y_binary = (y == c).astype(int)
        w = np.zeros(n_features + 1)
        losses = []

        for epoch in range(epochs):
            # Shuffle à chaque époque
            indices = np.random.permutation(n_samples)
            X_shuffled = X_bias[indices]
            y_shuffled = y_binary[indices]

            for i in range(n_samples):
                xi = X_shuffled[i].reshape(1, -1) 
                yi = y_shuffled[i]

                z = np.dot(xi, w)
                pred = 1 / (1 + np.exp(-z))
                error = pred - yi
                gradient = xi.T * error

                w -= lr * gradient.flatten()

            loss, _ = loss_and_gradient(X_bias, y_binary, w)
            losses.append(loss)

        weights[c] = w
        losses_per_class.append(losses)

    return weights, losses_per_class


def train_logistic_one_vs_all_minibatch(X, y, lr, epochs, batch_size=32):
    n_samples, n_features = X.shape
    n_classes_to_predict = 4
    weights = np.zeros((n_classes_to_predict, n_features + 1))  # +1 pour le biais
    losses_per_class = []

    # Ajout du biais
    X_bias = np.c_[np.ones((n_samples, 1)), X]

    for c in range(n_classes_to_predict):
        y_binary = (y == c).astype(int)
        w = np.zeros(n_features + 1)
        losses = []

        for epoch in range(epochs):
            # Shuffle chaque époque
            indices = np.random.permutation(n_samples)
            X_shuffled = X_bias[indices]
            y_shuffled = y_binary[indices]

            # Boucle par mini-batchs
            for start_idx in range(0, n_samples, batch_size):
                end_idx = min(start_idx + batch_size, n_samples)
                X_batch = X_shuffled[start_idx:end_idx]
                y_batch = y_shuffled[start_idx:end_idx]

                z = np.dot(X_batch, w)
                pred = 1 / (1 + np.exp(-z))
                error = pred - y_batch
                gradient = (X_batch.T @ error) / len(y_batch)

                w -= lr * gradient

            loss, _ = loss_and_gradient(X_bias, y_binary, w)
            losses.append(loss)

        weights[c] = w
        losses_per_class.append(losses)

    return weights, losses_per_class


def predict_one_vs_all(X, all_weights):
    m = X.shape[0]
    X_bias = np.hstack([np.ones((m, 1)), X])
    probs = sigmoid(X_bias @ all_weights.T)  # shape (m, num_classes)
    return np.argmax(probs, axis=1)


def print_log_loss(losses_per_class):
    for i, losses in enumerate(losses_per_class):
        plt.plot(losses, label=f"Classe {i}")

    plt.xlabel("Époque")
    plt.ylabel("Perte (loss)")
    plt.title("Courbe de coût par classe")
    plt.legend()
    plt.grid(True)
    plt.show()


def plot_decision_boundaries(X, y, weights):
    colors = ['red', 'green', 'blue', 'orange']
    labels = ['Gryffindor', 'Hufflepuff', 'Ravenclaw', 'Slytherin']

    # Scatter des données
    for class_idx in range(4):
        plt.scatter(
            X[y == class_idx][:, 0],
            X[y == class_idx][:, 1],
            c=colors[class_idx],
            label=labels[class_idx],
            alpha=0.6
        )

    # Génération des frontières de décision (une par classe)
    x_vals = np.linspace(X[:, 0].min(), X[:, 0].max(), 200)
    for class_idx, w in enumerate(weights):
        # w0 + w1 * x1 + w2 * x2 = 0 → x2 = -(w0 + w1 * x1) / w2
        if w[2] != 0:  # éviter la division par 0
            y_vals = -(w[0] + w[1] * x_vals) / w[2]
            plt.plot(x_vals, y_vals, linestyle='--')

    plt.xlabel("Herbology (normalisé)")
    plt.ylabel("Astronomy (normalisé)")
    plt.title("Frontières de décision One-vs-All")
    plt.legend()
    plt.grid(True)
    plt.show()


def main():
    # Charger les données
    X_train, X_test, y_train, y_test  = load_clean_df()

    # Entrainement
    X_train_scaled, X_test_scaled = normalize(X_train, X_test)
    # weights, losses_per_class = train_logistic_one_vs_all(X_train_scaled, y_train, lr=1, epochs=200)
    weights, losses_per_class = train_logistic_one_vs_all_stochastic(X_train_scaled, y_train, lr=0.01, epochs=50)
    print_log_loss(losses_per_class)
    plot_decision_boundaries(X_test_scaled, y_test, weights)

    # tester ave les 20% du test
    y_pred = predict_one_vs_all(X_test_scaled, weights)
    accuracy = accuracy_score(y_test, y_pred)
    print(f"Précision : {accuracy:.2f}")

    with open("weights.pkl", "wb") as f:
        pickle.dump(weights, f)

if __name__ == '__main__':
    main()
