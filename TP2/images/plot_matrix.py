import numpy as np
import matplotlib.pyplot as plt

matr = np.loadtxt("../src/output.txt", delimiter =' ')

plt.imshow(matr);
plt.colorbar()
plt.show()

