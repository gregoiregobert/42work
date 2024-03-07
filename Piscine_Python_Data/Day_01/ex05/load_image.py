import sys
import numpy
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

def ft_load(path: str) -> 'numpy.ndarray':

	"""
    Load an image from the specified path.

    Parameters:
    - path (str): The path to the image file.

    Returns:
    - image (numpy.ndarray): The image data as a NumPy array.
	"""

	try:
		assert path.endswith(".jpg") or path.endswith(".jpeg"), "AssertionError: File type is not supported"
	except AssertionError as m:
		print(m)
		sys.exit(1)

	try:
		image = mpimg.imread(path)
	except FileNotFoundError:
		print("Error: File not found")
		sys.exit(1)

	print(f"The shape of image is: {image.shape}")

	return image