import subprocess
import random
import plot
import os

island_seed = random.randint(1,99999999)
multipliers = [1,2,3,4,5,6,10,12,15]
multiplier = random.choice(multipliers)

def generate_data():
    subprocess.run(["g++", "perlin-noise.cpp", "-o", "noise"])
    subprocess.call(["./noise", str(island_seed), str(multiplier)])



def plot_island():
    names = ["Spring", "Fall", "Jungle", "Lava", "Dirtland"]
    colors = [['#071eed', '#4479e1', '#f2d2a9', '#41980a', '#2b6506', '#373737'],
               ['#28516d', '#366e93', '#f2d2a9', '#b05f0a', '#7d4307', '#373737'],
               ['#1c4d57', '#286e7d', '#c7ae7a', '#2d6225', '#517931', '#373737'],
               ['#1c4d57', '#286e7d', '#a39d81', '#782323', '#451414', '#201609'],
               ['#28516d', '#366e93', '#f2d2a9', '#8a6755', '#3d2d25', '#000000']]

    random_color = random.randint(0,4)
    selected_color = names[random_color]
    color_array = colors[random_color]

    plot.generate_plot(island_seed, color_array, selected_color, multiplier)

generate_data()
plot_island()