from itertools import combinations
import math
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

folder = "/home/ggobert/Downloads" #42
folder = "/Users/gregoiregobert/Downloads/42" #mac perso
df = pd.read_csv(folder + "/datasets/dataset_train.csv")

num_col = []

for column in df.columns:
    if df[f'{column}'].apply(type).eq(float).all():
        num_col.append(column)

combinations_of_features = list(combinations(num_col, 2))
n_pairs = len(combinations_of_features)

# 4. Déterminer la taille de la grille (carrée ou quasi-carrée)
n_cols = 3  
n_rows = math.ceil(n_pairs / n_cols)

# 5. Créer la figure et les subplots
fig, axes = plt.subplots(n_rows, n_cols, figsize=(5 * n_cols, 4 * n_rows))
axes = axes.flatten()  # pour itérer

for i, (x_feat, y_feat) in enumerate(combinations_of_features):
    ax = axes[i]
    sns.scatterplot(data=df, x=x_feat, y=y_feat, ax=ax)
    ax.set_title(f"{x_feat} vs {y_feat}")
    ax.set_xlabel(x_feat)
    ax.set_ylabel(y_feat)
    ax.grid(True)

# 7. Supprimer les axes inutilisés (si la grille n'est pas pleine)
for j in range(i + 1, len(axes)):
    fig.delaxes(axes[j])

plt.tight_layout()
plt.show()