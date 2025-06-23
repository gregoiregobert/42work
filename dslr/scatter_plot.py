from itertools import combinations
import math
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Load data
folder = "/home/ggobert/Downloads"
df = pd.read_csv(folder + "/datasets/dataset_train.csv")

# Colonnes numériques
num_col = [c for c in df.columns if df[c].dtype == float]
pairs = list(combinations(num_col, 2))

# Graph
page_size = 4
n_pages = math.ceil(len(pairs) / page_size)

for page in range(n_pages):
    chunk = pairs[page*page_size : (page+1)*page_size]
    
    fig, axes = plt.subplots(2, 2, figsize=(12, 10))
    axes = axes.flatten()
    fig.suptitle(f"Page {page+1} / {n_pages}", fontsize=16)
    
    for ax, (x_feat, y_feat) in zip(axes, chunk):
        sns.scatterplot(
            data=df, x=x_feat, y=y_feat,
            hue='Hogwarts House', ax=ax, legend=False
        )
        ax.set_title(f"{x_feat} vs {y_feat}")
        ax.grid(True)
    
    # Supprime les sous-plots vides
    for ax in axes[len(chunk):]:
        fig.delaxes(ax)
    
    plt.tight_layout(rect=[0, 0, 1, 0.95])
    plt.show()
