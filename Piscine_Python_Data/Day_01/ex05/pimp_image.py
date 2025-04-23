import numpy as np
import matplotlib.pyplot as plt


def ft_invert(image) -> 'np.ndarray':

    """
Inverts the color of the image received.
    """

    print(image)
    invert = 255 - image
    plt.imshow(invert)
    plt.show()


def ft_red(image) -> 'np.ndarray':

    """
Turn in red the color of the image received.
    """

    red = np.copy(image)
    red[:, :, 1:] = 0
    plt.imshow(red)
    plt.show()


def ft_green(image) -> 'np.ndarray':

    """
Turn in green the color of the image received.
    """

    green = np.copy(image)
    green[:, :, 0::2] = 0
    plt.imshow(green)
    plt.show()


def ft_blue(image) -> 'np.ndarray':

    """
Turn in blue the color of the image received.
    """

    blue = np.copy(image)
    blue[:, :, :2] = 0
    plt.imshow(blue)
    plt.show()
    print(blue.shape)


def ft_grey(image) -> 'np.ndarray':

    """
Turn in grey the color of the image received.
    """
    gray = np.sum(image, axis=2) / 3.0
    plt.imshow(gray, cmap='gray')
    plt.show()
