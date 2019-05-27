import numpy as np
import PIL
from PIL import Image

import sys

filename = sys.argv[1]

print(sys.argv)

print(sys.argv)

img = Image.open(filename)
#img.show()
img_arr = np.array(img)

print(img_arr.shape)

np.savetxt(filename[:-4] + '.txt', img_arr, delimiter = ' ')