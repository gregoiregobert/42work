import sys
from time import sleep
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
from load_image import ft_load

def zoom(path: str):
	try:
		image = mpimg.imread(path)
	except:
		print("Error")

	height, width, channels = image.shape

	left = width / 4
	top = height / 4
	bottom = top * 3
	right = left * 3

	roi = image[int(top):int(bottom), int(left):int(right)]

	plt.imshow(image)
	plt.show()
	plt.imshow(roi)
	plt.show()

def main():
	ft_load(sys.argv[1])
	zoom(sys.argv[1])

if __name__ == "__main__":
	main()