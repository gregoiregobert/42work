from abc import ABC, abstractmethod


class Character(ABC):

    def __init__(self, first_name, is_alive=True):
        self.first_name = first_name
        self.is_alive = is_alive

    @abstractmethod
    def die(self):
        pass


class Stark(Character):
    """Class representing a Stark character."""

    def __init__(self, first_name, is_alive=True):
        """Constructor of Stark Character"""
        super().__init__(first_name, is_alive)

    def die(self):
        """Change the health state of the character."""
        self.is_alive = False
