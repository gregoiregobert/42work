import pickle
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

def normalize(x):
    return (x - np.mean(x)) / np.std(x)

def loadData(fichier):
    """Charge le fichier de données contenant les kilométrages et les price."""
    data = np.loadtxt(fichier, delimiter=',', skiprows=1)
    mileage = data[:, 0]
    kilometrage_norm = normalize(mileage)
    price = data[:, 1]
    prix_norm = normalize(price)
    return kilometrage_norm, mileage, prix_norm, price

def compute_cost(mileage, price, theta0, theta1):
    m = len(mileage)
    prediction = theta0 + theta1 * mileage
    return (1 / (2 * m)) * np.sum((prediction - price) ** 2)

def trainModel(mileage, price, learning_rate, iterations):
    """Effectue la régression linéaire pour ajuster theta0 et theta1."""
    m = len(mileage)
    theta0 = 0
    theta1 = 0
    history = []

    for _ in range(iterations):
        prediction = theta0 + theta1 * mileage
        erreur = prediction - price
        tmp_theta0 = theta0 - learning_rate * (1 / m) * np.sum(erreur)
        tmp_theta1 = theta1 - learning_rate * (1 / m) * np.sum(erreur * mileage)
       
        theta0, theta1 = tmp_theta0, tmp_theta1 # Update parameters

        cost = compute_cost(mileage, price, theta0, theta1)
        history.append(cost)
    
    return theta0, theta1, history

def saveModel(theta0, theta1, prix_mean, prix_std, kilometrage_mean, kilometrage_std):
    """Sauvegarde les paramètres theta0 et theta1 dans un fichier."""
    with open("model_parameters.pkl", "wb") as f:
        pickle.dump((theta0, theta1, prix_mean, prix_std, kilometrage_mean, kilometrage_std), f)

def std_mean(price):
    x_mean = np.mean(price)
    x_std = np.std(price)
    return x_mean, x_std

def animate_cost(history):
    fig, ax = plt.subplots()
    ax.set_xlim(0, len(history))
    ax.set_ylim(0, max(history) * 1.1)
    line, = ax.plot([], [], lw=2)
    ax.set_title("Évolution de la fonction de coût")
    ax.set_xlabel("Itérations")
    ax.set_ylabel("Coût (MSE)")

    def update(frame):
        x = np.arange(frame)
        y = history[:frame]
        line.set_data(x, y)
        return line,

    ani = FuncAnimation(fig, update, frames=len(history), interval=100, blit=True)
    plt.show()

def plot_data_and_model(mileage, price, theta0, theta1):
    """Affiche les données du CSV et la droite de régression linéaire."""
    plt.figure(figsize=(10, 6))
    plt.scatter(mileage, price, color='blue', label='Données')
    
    # Générer des valeurs x pour tracer la droite
    x_vals = np.linspace(min(mileage), max(mileage), 100)
    y_vals = theta0 + theta1 * x_vals
    plt.plot(x_vals, y_vals, color='red', label='Régression linéaire')

    plt.title("Prix en fonction du kilométrage")
    plt.xlabel("Kilométrage")
    plt.ylabel("Prix")
    plt.legend()
    plt.grid(True)
    plt.show()

def main():
    kilometrage_norm, mileage, prix_norm, price = loadData("data.csv")
    learning_rate = 0.3
    iterations = 15

    theta0, theta1, history = trainModel(kilometrage_norm, prix_norm, learning_rate, iterations)
    prix_mean, prix_std = std_mean(price)
    kilometrage_mean, kilometrage_std = std_mean(mileage)
    saveModel(theta0, theta1, prix_mean, prix_std, kilometrage_mean, kilometrage_std)
    print(f"Entraînement terminé : theta0 = {theta0}, theta1 = {theta1}")
    plot_data_and_model(kilometrage_norm, prix_norm, theta0, theta1)
    animate_cost(history)

if __name__ == "__main__":
    main()
