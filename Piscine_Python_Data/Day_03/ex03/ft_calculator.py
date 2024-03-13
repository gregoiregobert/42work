import sys

class calculator:
	
	def __init__(self, vector):
		try:
			for i in vector:
				assert isinstance(i, (int, float)), "Must be a int or a float"
		except AssertionError as m:
			print(m)
			sys.exit(0)
		self.vector = vector

	def __add__(self, object) -> None:
		print([elem + object for elem in self.vector])

	def __mul__(self, object) -> None:
		print([elem * object for elem in self.vector])
	
	def __sub__(self, object) -> None:
		print([elem - object for elem in self.vector])
	
	def __truediv__(self, object) -> None:
		try:
			assert object != 0, "Cannot divided by zero"
		except AssertionError as m:
			print(m)
			sys.exit(0)
		print([elem / object for elem in self.vector])