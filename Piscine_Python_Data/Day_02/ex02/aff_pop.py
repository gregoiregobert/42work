import sys
from time import sleep
import matplotlib.pyplot as plt
from load_csv import load

def convert_to_Mega(value):
	if value[-1:] == 'k':
		return round(float(value[:-1]) / 1_000)
	if value[-1:] == 'M':
		return float(value[:-1])
	else:
		return round(float(value[:-1]) / 1_000_000)

def graphic(data):

	countries = ['France','Spain']

	plt.figure(figsize=(8, 6))

	years = data.columns[1:]

	max_pop = 0

	for country_name in countries:
		population_totale = data[data['country'] == country_name].values[0][1:]
		population_totale = [convert_to_Mega(value) for value in population_totale]
		max_pop = max(max_pop, max(population_totale))
		plt.plot(years, population_totale, label=country_name)

	plt.title('Population Projections')
	plt.xlabel('Year')
	plt.ylabel('Population (by M)')
	plt.yticks(range(0, int(max_pop), int(max_pop / 3)))
	plt.xticks(range(0, len(years), 40))
	plt.ylim(bottom=-1, top=max_pop + 1)
	plt.xlim(left=-4, right=len(years) + 4)
	plt.legend()
	plt.show()
	sys.exit(0)

def main():
	try:
		graphic( load("../ex02/population_total.csv") )
	except KeyboardInterrupt:
		print("\nProgam terminate by Ctrl + D signal\nThank you for using")
		sys.exit(0)


if __name__ == "__main__":
	main()