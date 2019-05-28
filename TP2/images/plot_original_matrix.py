import numpy as np
import matplotlib.pyplot as plt

matr = np.loadtxt("hombre_sin_header.txt", delimiter =' ')

plt.imshow(matr);
plt.colorbar()
plt.show()

