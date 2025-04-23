import sys


def give_bmi(height: list[int | float],
             weight: list[int | float]) -> list[int | float]:
    try:
        assert isinstance(height, list), \
            "AssertionError: parameters must be lists"
        assert isinstance(weight, list), \
            "AssertionError: parameters must be lists"
        assert len(height) == len(weight), \
            "AssertionError: lists aren't the same size"
        assert all(isinstance(x, (int, float)) for x in height), \
            "AssertionError: element in the list must be int or float"
        assert all(isinstance(x, (int, float)) for x in weight), \
            "AssertionError: element in the list must be int or float"
    except AssertionError as m:
        print(m)
        sys.exit(1)

    ret = []

    for i, y in zip(height, weight):
        ret.append(y / (i * i))

    return ret


def apply_limit(bmi: list[int | float], limit: int) -> list[bool]:
    try:
        assert isinstance(bmi, list), \
            "AssertionError: first parameter must be list[int | float]"
        assert isinstance(limit, int), \
            "AssertionError: second parameter must be an int"
        assert all(isinstance(x, (int, float)) for x in bmi), \
            "AssertionError: element in the list must be int or float"
    except AssertionError as m:
        print(m)
        sys.exit(1)

    ret = []

    for i in bmi:
        if (i <= limit):
            ret.append(False)
        else:
            ret.append(True)
    return ret

# def main():
# 	height = [1.60, 1.55, 2, 1.98]
# 	weight = [59, 80, 65, 88]
# 	print( apply_limit( give_bmi(height, weight), 25 ) )


# if __name__ == "__main__":
# 	main()
