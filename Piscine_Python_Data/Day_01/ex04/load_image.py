from PIL import Image
import sys
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

def ft_load(path: str) -> list:

	try:
		assert path.endswith(".jpg") or path.endswith(".jpeg"), "AssertionError: File type is not supported"
	except AssertionError as m:
		print(m)
		sys.exit(1)

	image = Image.open(path)
	width, height = image.size

	image_rgb = [[[0, 0, 0] for _ in range(width)] for _ in range(height)]

	for y in range(height):
		for x in range(width):
			r, g, b = image.getpixel((x, y))
			image_rgb[y][x] = [r, g, b]

	shape = (width, height, len(image_rgb[0][0]))
	print(f"The shape of image is: {shape}")

	return image_rgb