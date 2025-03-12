import pickle

def charger_modele():
    """Charge les paramètres theta0 et theta1 pré-entraînés depuis un fichier."""
    with open("model_parameters.pkl", "rb") as f:
        theta0, theta1 = pickle.load(f)
    return theta0, theta1

def estimer_prix(kilometrage, theta0, theta1):
    """Calcule le prix estimé en fonction du kilométrage en utilisant la régression linéaire."""
    return theta0 + (theta1 * kilometrage)

def programme_principal():
    """Demande le kilométrage à l'utilisateur et affiche le prix estimé."""
    theta0, theta1 = charger_modele()
    kilometrage = float(input("Veuillez entrer le kilométrage de la voiture : "))
    prix_estime = estimer_prix(kilometrage, theta0, theta1)
    print(f"Le prix estimé pour un kilométrage de {kilometrage} km est : {prix_estime} euros.")

if __name__ == "__main__":
    programme_principal()
