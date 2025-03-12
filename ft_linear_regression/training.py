import numpy as np
import pickle

def loadData(fichier):
    """Charge le fichier de données contenant les kilométrages et les prix."""
    data = np.loadtxt(fichier, delimiter=',', skiprows=1)
    kilometrage = data[:, 0]
    prix = data[:, 1]
    return kilometrage, prix

def trainModel(kilometrage, prix, taux_apprentissage, iterations):
    """Effectue la régression linéaire pour ajuster theta0 et theta1."""
    m = len(kilometrage)
    theta0 = 0
    theta1 = 0

    for _ in range(iterations):
        prediction = theta0 + theta1 * kilometrage
        erreur = prediction - prix
        tmp_theta0 = theta0 - taux_apprentissage * (1 / m) * np.sum(erreur)
        tmp_theta1 = theta1 - taux_apprentissage * (1 / m) * np.sum(erreur * kilometrage)
        
        # Mise à jour des paramètres
        theta0, theta1 = tmp_theta0, tmp_theta1
    
    return theta0, theta1

def saveModel(theta0, theta1):
    """Sauvegarde les paramètres theta0 et theta1 dans un fichier."""
    with open("model_parameters.pkl", "wb") as f:
        pickle.dump((theta0, theta1), f)

def programme_principal():
    """Exécute l'entraînement du modèle et enregistre les paramètres."""
    kilometrage, prix = loadData("data.csv")
    taux_apprentissage = 0.01  # Taux d'apprentissage
    iterations = 1000  # Nombre d'itérations pour l'entraînement
    
    theta0, theta1 = trainModel(kilometrage, prix, taux_apprentissage, iterations)
    saveModel(theta0, theta1)
    print(f"Entraînement terminé : theta0 = {theta0}, theta1 = {theta1}")

if __name__ == "__main__":
    programme_principal()
