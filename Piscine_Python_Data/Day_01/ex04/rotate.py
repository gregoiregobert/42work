import sys
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np
from load_image import ft_load

def rotate(path: str):

	try:
		image = mpimg.imread(path)
	except:
		print("Error")

	height, width, channels = image.shape

	left = width / 4
	top = height / 4
	bottom = top * 3
	right = left * 3

	zoomed = image[int(top):int(bottom), int(left):int(right)]

	height, width, channels = zoomed.shape

	rotate = np.zeros((width, height, channels), dtype=zoomed.dtype)

	for i in range(height):
		for j in range(width):
			rotate[width - j - 1, i] = zoomed[i, j]

	plt.imshow(zoomed)
	plt.show()
	plt.imshow(rotate)
	plt.show()

def main():

	try:
		assert len(sys.argv) == 2, "AssertionError: wrong number of arguments"
	except AssertionError as m:
		print(m)
		sys.exit(1)

	ft_load( sys.argv[1] )
	rotate( sys.argv[1] )

if __name__ == "__main__":
	main()