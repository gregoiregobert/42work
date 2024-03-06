import sys
import matplotlib.pyplot as plt
from load_image import ft_load

def zoom(image):
		
	height, width = image.size

	left = width / 4
	top = height / 4
	bottom = top * 3
	right = left * 3

	roi = image[int(top):int(bottom), int(left):int(right)]

	height_r, width_r = roi.size
	shape = (height_r, width_r, len(roi[0][0]))
	print(f"New shape after slicing: {shape}")
	print(roi)

	plt.imshow(roi)
	plt.show()

def main():

	try:
		assert len(sys.argv) == 1, "AssertionError: wrong number of arguments"
	except AssertionError as m:
		print(m)
		sys.exit(1)

	zoom( ft_load("../ex02/landscape.jpg") )

if __name__ == "__main__":
	main()