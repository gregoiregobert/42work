
import sys
import string

NESTED_MORSE = {
    " ": "/",
    'A': '.-',
    'B': '-...',
    'C': '-.-.',
    'D': '-..',
    'E': '.',
    'F': '..-.',
    'G': '--.',
    'H': '....',
    'I': '..',
    'J': '.---',
    'K': '-.-',
    'L': '.-..',
    'M': '--',
    'N': '-.',
    'O': '---',
    'P': '.--.',
    'Q': '--.-',
    'R': '.-.',
    'S': '...',
    'T': '-',
    'U': '..-',
    'V': '...-',
    'W': '.--',
    'X': '-..-',
    'Y': '-.--',
    'Z': '--..',
    '0': '-----', '1': '.----', '2': '..---',
    '3': '...--', '4': '....-', '5': '.....', '6': '-....',
    '7': '--...', '8': '---..', '9': '----.',
}


def main():

    try:
        assert len(sys.argv) == 2, "AssertionError: the arguments are bad"
        assert all(char not in string.punctuation for char in sys.argv[1]), \
            "AssertionError: the arguments are bad"
    except AssertionError as msg:
        print(msg)
        sys.exit(1)

    morse_text = ''
    for char in sys.argv[1].upper():
        if char in NESTED_MORSE:
            morse_text += NESTED_MORSE[char] + ' '
    print(morse_text.strip())


if __name__ == "__main__":
    main()
