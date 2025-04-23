import sys


class calculator:

    def validator(V1: list[float], V2: list[float]):
        """Checker"""
        try:
            assert isinstance(V1, list), \
                "Parameters must be a list of int or float"
            assert isinstance(V2, list), \
                "Parameters must be a list of int or float"
            assert len(V1) == len(V2), \
                "Array must be the same size"
            for i in V1:
                assert isinstance(i, (int, float)), \
                    "Element must be int or float"
            for i in V2:
                assert isinstance(i, (int, float)), \
                    "Element must be int or float"
        except AssertionError as m:
            print(m)
            sys.exit(0)

    def dotproduct(V1: list[float], V2: list[float]) -> None:
        """Multiply the elements of the lists\
 and then add the results together"""
        calculator.validator(V1, V2)
        products = [x * y for x, y in zip(V1, V2)]
        print("Dot product is:", sum(products))

    def add_vec(V1: list[float], V2: list[float]) -> None:
        """Add lists' elements by each other"""
        calculator.validator(V1, V2)
        print("Add Vector is : ", [float(x + y) for x, y in zip(V1, V2)])

    def sous_vec(V1: list[float], V2: list[float]) -> None:
        """Substract lists' elements by each other"""
        calculator.validator(V1, V2)
        print("Sous Vector is: ", [float(x - y) for x, y in zip(V1, V2)])
