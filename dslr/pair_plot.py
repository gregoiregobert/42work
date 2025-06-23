import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt


def load_data():
    folder = "/Users/gregoiregobert/Downloads/42" #mac perso
    folder = "/home/ggobert/Downloads" #42
    df = pd.read_csv(folder + "/datasets/dataset_train.csv")

    return df

def pair_plot_show(df):
    sns.pairplot(df, hue="Hogwarts House")
    plt.suptitle("", y=1.02)
    plt.show()

def main():
    df = load_data()

    num_cols = [c for c in df.columns if df[c].dtype == float]
    df_subset = df[num_cols + ["Hogwarts House"]]

    pair_plot_show(df_subset)

if __name__ == "__main__":
    main()