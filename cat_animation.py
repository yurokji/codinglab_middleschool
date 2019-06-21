# simple image mosaic operation
# 2019/06/21
# by Yurok Ji, Hacker's Coding lab 

import numpy as numpy
import matplotlib.pyplot as plt
from skimage import io

#  read and image from file input
photo = io.imread('cat.jpg')
# begin with original image
size = 1
#repeat the process as 100 times as many 
for i in range(100):
    # mosaic levels set to 8
    for j in range(8):
        # slowly go into mozaic from the image
        if i % 2 == 0:
            size *= 2
        # slowly go back to the original image 
        else:
            size //= 2
        # apply the current mosaic level to the image
        plt.imshow(photo[::size, ::size])
        # draw the current image now keeping the predetermined frame rates.
        plt.draw()
        plt.pause(0.05)
        plt.clf()
