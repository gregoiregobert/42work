import sys
import pandas as pd
import matplotlib.pyplot as plt
from load_csv import load


def graphic(data):

	countries = ['France','Armneia']

	plt.figure(figsize=(8, 6))

	for country_name in countries:
		country_data = data[data['country'] == country_name]
		years = country_data.columns[1:]
		print(country_data)
		population_total = country_data.values.tolist()[0][1:]
		plt.plot(years, population_total, label=country_name)


	plt.title('{} Population Projections'.format(country_name))
	plt.xlabel('Year')
	plt.ylabel('Population')
	plt.yticks(range(0, len(population_total), int(len(population_total) / 4)))
	plt.xticks(range(0, len(years), 40))
	plt.legend
	plt.show()

def main():
	try:
		graphic( load("../ex02/population_total.csv") )
	except KeyboardInterrupt:
		print("\nProgam terminate by Ctrl + D signal\nThank you for using")
		sys.exit(0)


if __name__ == "__main__":
	main()