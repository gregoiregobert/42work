import sys


def slice_me(family: list, start: int, end: int) -> list:
	
	D1 = len(family)
	D2 = len(family[0])

	try:
		assert isinstance(family, list), "AssertionError: first argument must be a list"
		assert isinstance(start, int), "AssertionError: second argument must be an int"
		assert isinstance(end, int), "AssertionError: first argument must be an int"
	except AssertionError as m:
		print(m)

	shape = (D1, D2)
	print(f"My shape is : {shape}")

	# if (start < 0):
			

if __name__ == '__main__':
	list2 = [[1, 2],
			 [3 ,4]]
	
	my_list =[1, 2, 3, 4, 5]
	print(my_list[-1])
	# slice_me(list2, 0, 0)


