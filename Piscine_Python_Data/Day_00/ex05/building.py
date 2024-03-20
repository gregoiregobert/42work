import sys
import string


def count_type_of_character(text):

    """Display the number of each type of character"""

    upper_count = sum(1 for char in text if char.isupper())
    lower_count = sum(1 for char in text if char.islower())
    punct_count = sum(1 for char in text if char in string.punctuation)
    digit_count = sum(1 for char in text if char.isdigit())
    space_count = sum(1 for char in text if char.isspace())

    print(f"The text contains {len(text)} characters:")
    print(f"{upper_count} upper letters")
    print(f"{lower_count} lower letters")
    print(f"{punct_count} punctuation marks")
    print(f"{space_count} spaces")
    print(f"{digit_count} digits")


def main():

    if len(sys.argv) == 1:
        print("What is the text to count?")
        text = sys.stdin.readline()
        count_type_of_character(text)
    elif len(sys.argv) == 2:
        text = sys.argv[1]
        count_type_of_character(text)
    else:
        try:
            raise AssertionError("AssertionError:\
 more than one argument is provided")
        except AssertionError as msg:
            print(msg)


if __name__ == "__main__":
    main()
