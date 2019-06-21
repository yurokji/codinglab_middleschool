import numpy as numpy
import matplotlib.pyplot as plt
from skimage import io

photo = io.imread('cat.jpg')
size = 1
for i in range(100):
    for j in range(8):
        if i % 2 == 0:
            size *= 2
        else:
            size //= 2
        plt.imshow(photo[::size, ::size])
        plt.draw()
        plt.pause(0.05)
        plt.clf()
