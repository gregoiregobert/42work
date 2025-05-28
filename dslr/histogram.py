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

df_course = df[num_col].copy()
df_course['Hogwarts House'] = df['Hogwarts House']

# Colonnes matières : toutes sauf 'Hogwarts House'
cols_a_tracer = [col for col in df_course.columns if col != 'Hogwarts House']

n = len(cols_a_tracer)
ncols = 3
nrows = math.ceil(n / ncols)

fig, axes = plt.subplots(nrows=nrows, ncols=ncols, figsize=(5 * ncols, 4 * nrows))
axes = axes.flatten()  # Pour pouvoir boucler facilement

for i, col in enumerate(cols_a_tracer):
    sns.histplot(
        data=df_course,
        x=col,
        hue='Hogwarts House',
        multiple='dodge',
        bins='auto',
        ax=axes[i]
    )
    axes[i].set_title(f'{col}')
    axes[i].set_xlabel('')
    axes[i].set_ylabel('')

# Supprimer les axes inutilisés si nombre de matières pas multiple de 3
for j in range(i + 1, len(axes)):
    fig.delaxes(axes[j])

plt.tight_layout()
plt.show()
