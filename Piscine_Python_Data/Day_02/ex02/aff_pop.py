import sys
import matplotlib.pyplot as plt
from load_csv import load


def format_with_notation(number):
    if abs(number) >= 1e9:
        return '{:.1f}B'.format(number / 1e9)
    elif abs(number) >= 1e6:
        return '{:.1f}M'.format(number / 1e6)
    elif abs(number) >= 1e3:
        return '{:.1f}k'.format(number / 1e3)
    else:
        return str(number)


def convert_to_num(value):
    if value[-1] == 'k':
        return round(float(value[:-1]) * 1_000)
    if value[-1] == 'M':
        return round(float(value[:-1]) * 1_000_000)
    if value[-1] == 'B':
        return round(float(value[:-1]) * 1_000_000_000)
    else:
        return float(value)


def graphic(data):

    countries = ['Andorra', 'Luxembourg']

    plt.figure(figsize=(8, 6))

    years = data.columns[1:]

    max_pop = 0

    for country_name in countries:
        population_totale = data[data['country'] == country_name].values[0][1:]
        population_totale = \
            [convert_to_num(value) for value in population_totale]
        max_pop = max(max_pop, max(population_totale))
        plt.plot(years, population_totale, label=country_name)

    yticks_values = range(0, int(max_pop), int(max_pop / 3))
    yticks_labels = [format_with_notation(value) for value in yticks_values]

    plt.title('Population Projections')
    plt.xlabel('Year')
    plt.ylabel('Population')
    plt.yticks(yticks_values, yticks_labels)
    plt.xticks(range(0, len(years), 40))
    plt.ylim(bottom=-1, top=max_pop + (max_pop * 0.05))
    plt.xlim(left=-4, right=len(years) + 4)
    plt.legend()
    plt.show()
    sys.exit(0)


def main():
    try:
        graphic(load("../ex02/population_total.csv"))
    except KeyboardInterrupt:
        print("\nProgam terminate by Ctrl + D signal\nThank you for using")
        sys.exit(0)


if __name__ == "__main__":
    main()
