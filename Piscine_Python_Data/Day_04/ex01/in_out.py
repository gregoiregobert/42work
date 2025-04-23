def square(x: int | float) -> int | float:
    return x ** 2


def pow(x: int | float) -> int | float:
    return x ** x


def outer(x: int | float, function):
    count = 0

    def inner() -> float:
        nonlocal x, count
        count += 1
        x = function(x)
        return x

    return inner
