import sys

if len(sys.argv) == 1:
    sys.exit(0)


try:
    assert len(sys.argv) == 2, \
        "AssertionError: more than one argument is provided"
except AssertionError as msg:
    print(msg)
    sys.exit(1)

try:
    num = int(sys.argv[1])
except ValueError:
    print("AssertionError: argument is not an integer")
    sys.exit(1)

if num % 2 == 0:
    print("I'm Even.")
else:
    print("I'm Odd.")
