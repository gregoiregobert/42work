import sys
import numpy
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
        assert path.endswith(".jpg") or path.endswith(".jpeg"), \
            "Error: File type is not supported"
    except AssertionError as m:
        print(m)
        sys.exit(1)

    try:
        image = mpimg.imread(path)
    except Exception:
        print("Error: File cannot be open")
        sys.exit(1)

    print(f"The shape of image is: {image.shape}")

    return image
