from PIL import Image
import sys
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

def ft_load(path: str) -> list:

	try:
		image = Image.open(path)
		image2 = mpimg.imread(path)
	except:
		print("error")

	width, height = image.size

	image_rgb = [[[0, 0, 0] for _ in range(width)] for _ in range(height)]

	for y in range(height):
		for x in range(width):
			r, g, b = image.getpixel((x, y))
			image_rgb[y][x] = [r, g, b]

	shape = (width, height, len(image_rgb[0][0]))
	print(f"The shape of image is: {shape}")

	return image_rgb

def main():
	ft_load(sys.argv[1])
	# print(ft_load(sys.argv[1]))

if __name__== "__main__":
	main()