import sys
import matplotlib.pyplot as plt
from load_csv import load


def graphic(data):

    country_name = 'Belgium'

    country_data = data[data['country'] == country_name]
    country_data = country_data._append(data[data['country'] == 'Armenia'])

    years = country_data.columns[1:]
    life_expectancy = country_data.values[0][1:]

    plt.figure(figsize=(8, 6))
    plt.plot(years, life_expectancy)
    plt.title('{} Life Expectancy Projections'.format(country_name))
    plt.xlabel('Year')
    plt.ylabel('Life Expectancy')
    plt.xticks(range(0, len(years), 40))
    plt.show()


def main():
    try:
        graphic(load("../ex00/life_expectancy_years.csv"))
    except KeyboardInterrupt:
        print("\nProgam terminate by Ctrl + D signal\nThank you for using")
        sys.exit(0)


if __name__ == "__main__":
    main()
