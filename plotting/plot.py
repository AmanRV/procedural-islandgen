import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap, BoundaryNorm
import os





def generate_plot(seed, color_array, selected_color):
    current_dir = os.getcwd();
    current_dir = os.path.dirname(current_dir)
    filepath = os.path.join(current_dir, "noise", "output.txt")

    array = np.loadtxt(filepath)

    colors = color_array
    thresholds = [0, 80, 100, 150, 220, 254, 255]

    custom_cmap = ListedColormap(colors)
    norm = BoundaryNorm(thresholds, custom_cmap.N)


    # Plot the data with custom colormap and normalization
    plt.title(selected_color + " Island seed: " + str(seed))
    plt.imshow(array, cmap=custom_cmap, norm=norm)
    plt.colorbar()
    plt.axis('off')
    plt.show()
