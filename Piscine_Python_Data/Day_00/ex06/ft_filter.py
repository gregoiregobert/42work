# import sys
# import string

def ft_filter(func, iterable):

    """
ft_filter(function or None, iterable) --> filter object

Return an iterator yielding those items of iterable for which function(item)
is true. If function is None, return the items that are true.
    """

    if (func):
        return (item for item in iterable if func(item))
    else:
        return (item for item in iterable)


# def is_multiple_of_3(x):
# 	return x % 3 == 0


# list_numb = (1, 2, 3, 4)

# ret = filter(None, list_numb)
# ft_ret = ft_filter(None, list_numb)
# print(ret, ft_ret)
# print(list(ret), list(ft_ret))

# ret = filter(is_multiple_of_3, list_numb)
# ft_ret = ft_filter(is_multiple_of_3, list_numb)
# print(list(ret), list(ft_ret))

# print(ft_filter.__doc__)
