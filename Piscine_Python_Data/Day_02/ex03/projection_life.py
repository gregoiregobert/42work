import sys
import pandas as pd
import matplotlib.pyplot as plt
from load_csv import load


def convert_to_Mega(value):
    if value[-1:] == 'k':
        return round(float(value[:-1]) / 1_000)
    if value[-1:] == 'M':
        return float(value[:-1])
    else:
        return round(float(value[:-1]) / 1_000_000)


def graphic(data_gross, data_life_expect):

    plt.figure(figsize=(8, 6))

    data_gross.set_index('country', inplace=True)
    data_life_expect.set_index('country', inplace=True)

    data_1900_gdp = data_gross.loc[:, '1900']
    data_1900_le = data_life_expect.loc[:, '1900']

    merged_data_1900 = pd.merge(data_1900_gdp, data_1900_le,
                                left_index=True, right_index=True)

    plt.scatter(merged_data_1900['1900_x'], merged_data_1900['1900_y'])
    plt.title('1900')
    plt.xlabel('Gross domestic product')
    plt.ylabel('Life Expectancy')
    plt.show()


def main():
    try:
        graphic(
            load("income_per_person_gdppercapita_ppp_inflation_adjusted.csv"),
            load("../ex00/life_expectancy_years.csv"))
    except KeyboardInterrupt:
        print("\nProgam terminate by Ctrl + D signal\nThank you for using")
        sys.exit(0)


if __name__ == "__main__":
    main()
