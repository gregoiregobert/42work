import matplotlib.pyplot as plt
from load_image import ft_load


def zoom(image):

    print(image)
    height, width, channels = image.shape

    left = width / 4
    top = height / 4
    bottom = top * 3
    right = left * 3

    roi = image[int(top):int(bottom), int(left):int(right)]

    height_r, width_r, channels_r = roi.shape
    shape = (height_r, width_r, len(roi[0][0]))
    print(f"New shape after slicing: {shape}")
    print(roi)

    plt.imshow(roi)
    plt.show()


def main():

    zoom(ft_load("../ex02/animal.jpeg"))


if __name__ == "__main__":
    main()
