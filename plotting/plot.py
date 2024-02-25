import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap
import os

current_dir = os.getcwd();
current_dir = os.path.dirname(current_dir)
filepath = os.path.join(current_dir, "noise", "output.txt")

array = np.loadtxt(filepath)

colors = ['#071eed', '#4479e1', '#f2d2a9', '#41980a', '#373737']  
custom_cmap = ListedColormap(colors)

plt.imshow(array, cmap=custom_cmap, vmin=0, vmax=255)
plt.colorbar()  
plt.axis('off')  
plt.show()