#include <iostream>

//General steps to perlin noise generation
//1. define frequency of noise and resolution of output
//2. define 2d noise map array, size resolution
//2. calculate perlin noise for each frequency/resolution point
//This is done by...
//3. calculate the distance to the 4 corners as weighting
//4. generate gradient vectors for each corner
//5. calculate dot product between gradient and point for each corner
//6. cubic interpolate
//7. scale value to be 0 to 255 (or a custom scale)
//8. output and store this value inside noise map
//9. perform this for every pixel
//Future goal: implement marching squares algorithm