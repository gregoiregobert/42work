import sys


class calculator:

    def __init__(self, vector):
        """Constructor ft_calculator"""
        try:
            for i in vector:
                assert isinstance(i, (int, float)), \
                    "Must be a int or a float"
        except AssertionError as m:
            print(m)
            sys.exit(0)
        self.vector = vector

    def __add__(self, object) -> None:
        """Add operation"""
        self.vector = [elem + object for elem in self.vector]
        print(self.vector)

    def __mul__(self, object) -> None:
        """Multiply operator"""
        self.vector = [elem * object for elem in self.vector]
        print(self.vector)

    def __sub__(self, object) -> None:
        """Substraction operator"""
        self.vector = [elem - object for elem in self.vector]
        print(self.vector)

    def __truediv__(self, object) -> None:
        """Division operator"""
        try:
            assert object != 0, "Cannot be divided by zero"
        except AssertionError as m:
            print(m)
            sys.exit(0)
        self.vector = [elem / object for elem in self.vector]
        print(self.vector)
