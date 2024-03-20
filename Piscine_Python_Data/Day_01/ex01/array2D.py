import sys


def slice_me(family: list, start: int, end: int) -> list:

    D1 = len(family)
    D2 = len(family[0])

    try:
        assert family[start:end], "AssertionError: list index out of range"
        for n in family:
            assert len(n) == D2, \
                "AssertionError: lists are not the same size"
        assert isinstance(family, list), \
            "AssertionError: first argument must be a list"
        assert isinstance(start, int), \
            "AssertionError: second argument must be an int"
        assert isinstance(end, int), \
            "AssertionError: first argument must be an int"
    except AssertionError as m:
        print(m)
        sys.exit(1)

    shape = (D1, D2)
    print(f"My shape is : {shape}")

    new_shape = (len(family[start:end]), len(family[start:end][0]))
    print(f"My new shape is : {new_shape}")
    print(family[start:end])


if __name__ == '__main__':

    list2 = [[1.5, 2],
             [3, 4.88],
             [5, 6],
             [7.565, 8]]

    slice_me(list2, 2, 8)
    # slice_me(list2, 0, -4)
