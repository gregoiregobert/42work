import sys
import string

def main():
	try:
		assert len(sys.argv) == 3, "AssertionError: the arguments are bad"
		assert sys.argv[2].isdigit() , "AssertionError: 2 must be an int"
	except AssertionError as msg:
		print(msg)


if __name__ == "__main__":
	main()