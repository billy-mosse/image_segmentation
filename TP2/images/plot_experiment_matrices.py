import numpy as np
import matplotlib.pyplot as plt

for str in ["00", "01", "02", "10", "11", "12"]:
	filename = "../src/%s.txt" % str
	matr = np.loadtxt(filename, delimiter =' ')
	#matr *= 10

	#https://jakevdp.github.io/PythonDataScienceHandbook/04.07-customizing-colorbars.html
	M = np.sin(matr) + np.cos(matr)
	plt.imshow(matr, cmap='rainbow');
	plt.colorbar()
	plt.savefig("%s.png" % str)
	plt.clf()