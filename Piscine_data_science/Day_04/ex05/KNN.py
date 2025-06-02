import sys
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import f1_score
import matplotlib.pyplot as plt
from sklearn.preprocessing import StandardScaler

def loadData():
    train_df = pd.read_csv('../ex04/Train_knight.csv')
    test_df = pd.read_csv('../ex04/Test_knight.csv')

    train_df['knight'] = train_df['knight'].map({'Sith': 0, 'Jedi': 1})

    X = train_df.drop(columns='knight')
    y = train_df['knight']

    scaler = StandardScaler()
    X_scaled = scaler.fit_transform(X)
    test_df_scaled = scaler.fit_transform(test_df)

    print()

    return X_scaled, y, test_df_scaled

def findBestK(X, y):
    X_train, X_val, y_train, y_val = train_test_split(X, y, test_size=0.2, random_state=5)

    k_value = range(1, 20)
    f1_scores = []

    for k in k_value:
        knn = KNeighborsClassifier(n_neighbors=k)
        knn.fit(X_train, y_train)
        y_val_pred = knn.predict(X_val)
        f1 = f1_score(y_val, y_val_pred)
        f1_scores.append(f1)

    plt.plot(k_value, f1_scores)
    plt.xlabel("K Value")
    plt.ylabel("f1 Score")
    plt.title("F1 Score for each K value")
    plt.show()

    best_k = k_value[np.argmax(f1_scores)]
    print(f"best k_value is {best_k} with f1_score {max(f1_scores) * 100:.2f}%")

    return best_k

def predict(X, y, test_df, best_K):
    knn = KNeighborsClassifier(n_neighbors=best_K)
    knn.fit(X, y)

    predictions = knn.predict(test_df)
    return predictions

def writePrediction(predictions):
    predictions = ['Jedi' if pred == 1 else 'Sith' for pred in predictions]
    with open("KNN.txt", 'w') as f:
        for pred in predictions:
            f.write(f"{pred}\n")

def main():
    X, y, test_df = loadData()
    bestK = findBestK(X, y)
    predictions = predict(X, y, test_df, bestK)
    writePrediction(predictions)

if __name__ == "__main__":
    main()

# Le knn va dans le predict rechercher les voisins les plus proches
# et determiner sa classe en fonction d'eux, s'il a plus de voisins
# rouge que bleu le point sera determiner comme rouge.