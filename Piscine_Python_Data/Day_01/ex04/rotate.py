import matplotlib.pyplot as plt
import numpy as np
from load_image import ft_load


def zoom(image):

    print(image)
    height, width, channels = image.shape

    left = width / 4
    top = height / 4
    bottom = top * 3
    right = left * 3

    zoomed = image[int(top):int(bottom), int(left):int(right)]

    return zoomed


def rotate(zoomed):

    height, width, channels = zoomed.shape

    rotate = np.zeros((width, height, channels), dtype=zoomed.dtype)

    for i in range(height):
        for j in range(width):
            rotate[width - j - 1, i] = zoomed[i, j]

    print(f"New shape after Transpose: {zoomed.shape}")
    print(rotate)
    plt.imshow(rotate)
    plt.show()


def main():

    rotate(zoom(ft_load("../ex02/animal.jpeg")))


if __name__ == "__main__":
    main()
