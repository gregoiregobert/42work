from S1E9 import Character
import numpy as np

class Baratheon(Character):
	"""Representing the Baratheon family."""

	def __init__(self, first_name, is_alive=True):
		super().__init__(first_name, is_alive)
		self.familiy_name = 'Baratheon'
		self.eyes = 'brown'
		self.hairs = 'dark'

	def die(self):
		self.is_alive = False

	def __str__(self):
		Vector = (self.familiy_name, self.eyes, self.hairs)
		return f"<Vector: {Vector}>"
	
	def __repr__(self):
		return self.__str__()


class Lannister(Character):

	def __init__(self, first_name, is_alive=True):
		super().__init__(first_name, is_alive)
		self.familiy_name = 'Lannister'
		self.eyes = 'blue'
		self.hairs = 'light'

	def create_lannister(first_name, is_alive):
		return Lannister(first_name, is_alive)

	def die(self):
		self.is_alive = False


	def __str__(self):
		Vector = (self.familiy_name, self.eyes, self.hairs)
		return f"<Vector: {Vector}>"

	def __repr__(self):
		return self.__str__()