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
    for i in serie:



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


def describe(df)
    df_describe = pd.DataFrame(columns=num_col)

    df_describe.loc['count'] = [my_count(df[col]) for col in num_col]
    df_describe.loc['min']   = [my_min(df[col]) for col in num_col]
    df_describe.loc['25%']   = [my_quantile(df[col], 0.25) for col in num_col]
    df_describe.loc['50%']   = [my_quantile(df[col], 0.5) for col in num_col]
    df_describe.loc['75%']   = [my_quantile(df[col], 0.75) for col in num_col]
    df_describe.loc['max']   = [my_max(df[col]) for col in num_col]

    return df_describe

def main():
    folder = "/home/ggobert/Downloads"
    df = pd.read_csv(folder + "/datasets/dataset_train.csv")

    num_col = []
    for column in df.columns:
        if df[f'{column}'].apply(type).eq(float).all():
            num_col.append(column)

    
