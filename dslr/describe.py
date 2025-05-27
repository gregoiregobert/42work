import pandas as pd


def my_count(serie):
    n = 0
    serie = serie.dropna()
    for _ in serie:
        n += 1
    return n


def my_min(serie):
    min = serie[0]
    for i in serie:
        if i < min:
            min = i
    return min


def my_max(serie):
    max = serie[0]
    for i in serie:
        if i > max:
            max = i
    return max


def my_mean(serie):
    serie = serie.dropna()
    size = my_count(serie)

    add_all = 0
    for i in serie:
        add_all += i
    return add_all / size


def my_quantile(serie, percent):
    serie = serie.dropna()
    size = my_count(serie)
    quart = percent * (size - 1)
    serie = serie.sort_values().reset_index(drop=True)

    lower = int(quart)
    upper = lower + 1
    fraction = quart - lower

    if upper < size:
        # Interpolation lineaire : on va rajouter a la valeur en dessous du pourcentage la fraction manquante : (i[26%] - i[24%]) * (25% - 24%)
        return serie.iloc[lower] + (serie.iloc[upper] - serie.iloc[lower]) * fraction
    else:
        return serie.iloc[lower]


def my_std(serie):
    serie = serie.dropna()
    
    # Étape 1 : moyenne
    mean = sum(serie) / len(serie)

    # Étape 2 & 3 : somme des carrés des écarts à la moyenne
    squared_diffs = [(i - mean) ** 2 for i in serie]
    sum_squared_diffs = sum(squared_diffs)

    # Étape 4 : division par (n - 1)
    variance = sum_squared_diffs / (len(serie) - 1)

    # Étape 5 : racine carrée
    std_dev = variance ** 0.5

    return std_dev


def describe(df):
    # colonne de note numérique (des notes) uniquement
    num_col = []

    for column in df.columns:
        if df[f'{column}'].apply(type).eq(float).all():
            num_col.append(column)
    df_describe = pd.DataFrame(columns=num_col)

    df_describe.loc['count'] = [my_count(df[col]) for col in num_col]
    df_describe.loc['mean']  = [my_mean(df[col]) for col in num_col]
    df_describe.loc['std']   = [my_std(df[col]) for col in num_col]
    df_describe.loc['min']   = [my_min(df[col]) for col in num_col]
    df_describe.loc['25%']   = [my_quantile(df[col], 0.25) for col in num_col]
    df_describe.loc['50%']   = [my_quantile(df[col], 0.5) for col in num_col]
    df_describe.loc['75%']   = [my_quantile(df[col], 0.75) for col in num_col]
    df_describe.loc['max']   = [my_max(df[col]) for col in num_col]

    return df_describe


def main():
    folder = "/home/ggobert/Downloads" #42
    folder = "/Users/gregoiregobert/Downloads/42" #mac perso
    df = pd.read_csv(folder + "/datasets/dataset_train.csv")

    df_describe = describe(df)
    print(df_describe)

    
if __name__ == "__main__":
    main()