import sys
import string


def main():
    noSpecialChar = \
        (lambda str: all(char not in string.punctuation for char in str))

    try:
        assert len(sys.argv) == 3, "AssertionError:\
 the arguments are bad"
        assert sys.argv[2].isdigit(), "AssertionError:\
 the arguments are bad"
        assert noSpecialChar(sys.argv[1]), "AssertionError:\
 the arguments are bad"
    except AssertionError as msg:
        print(msg)
        sys.exit(1)

    list_of_words = sys.argv[1].split()

    ret = [word for word in list_of_words if len(word) >= int(sys.argv[2])]
    print(ret)


if __name__ == "__main__":
    main()
