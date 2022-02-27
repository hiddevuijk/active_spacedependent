import numpy as np
import matplotlib.pyplot as plt
from sys import exit

rho = np.loadtxt("rho.dat")

plt.scatter(rho[0,:], rho[1,:])
plt.show()
