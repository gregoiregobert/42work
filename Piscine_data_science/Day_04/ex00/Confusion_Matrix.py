import os
import sys
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
import pandas as pd

list = {
     0 : 'Prediction',
     1 : 'Truth'
}

for i in range(len(sys.argv) - 1):
    with open(f"{os.getcwd()}/{sys.argv[i + 1]}", 'r') as file:
        list[i] = [line.strip() for line in file.readlines()]

tp = sum(1 for t, p in zip(list[0], list[1]) if p == 'Jedi' and t == 'Jedi')
fp = sum(1 for t, p in zip(list[0], list[1]) if p == 'Jedi' and t == 'Sith')
tn = sum(1 for t, p in zip(list[0], list[1]) if p == 'Sith' and t == 'Sith')
fn = sum(1 for t, p in zip(list[0], list[1]) if p == 'Sith' and t == 'Jedi')

total_jedi = sum(1 for t in list[1] if t == 'Jedi')
total_sith = sum(1 for t in list[1] if t == 'Sith')

# Parmi les éléments classés comme Jedi/Sith, combien sont corrects ?
precision_jedi = round(tp / (tp + fp), 2)
precision_sith = round(tn / (tn + fn), 2)

# Pourcentage de bonne prediction
accuracy = sum(1 for t, p in zip(list[0], list[1]) if t == p) / len(list[1])

# Combien ai-je trouvé de Jedi juste/Sith juste
recall_jedi = round(tp / (tp + fn), 2)
recall_sith =  round(tn / (tn + fp), 2)

# Moyenne entre précision et rappel
f1_score_jedi = round(((2 * precision_jedi * recall_jedi) / (precision_jedi + recall_jedi)), 2)
f1_score_sith  = round(((2 * precision_sith * recall_sith) / (precision_sith + recall_sith)), 2)

cm = [[tp, fp],
    [fn, tn]]

colonnes = ['precision', 'recall', 'f1_score', 'total']

df = pd.DataFrame(columns=colonnes)

df.loc['Jedi'] = [precision_jedi, recall_jedi, f1_score_jedi, total_jedi]
df.loc['Sith'] = [precision_sith, recall_sith, f1_score_sith, total_sith]
df.loc['Accuracy'] = [accuracy, None, None, 100]

print(df)
sns.heatmap(cm, annot=True, fmt='d', cmap='Blues')
plt.xlabel('Prédiction')
plt.ylabel('Vérité')
plt.title('Matrice de Confusion')
plt.show()
