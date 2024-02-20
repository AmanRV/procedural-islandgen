#include <iostream>
#include <cstdlib>
#include <cmath>    
using namespace std;

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

typedef struct{
    float i;
    float j;
} vector;

class perlinNoise{
    private:
        int resX;
        int resY;
        int freq;

        float freqX; 
        float freqY;

        int numGradients; 
        int seed;
        vector* gradients;


    public:

        perlinNoise(int resolution_x, int resolution_y, int frequency){
            seed = 237469;
            srand(seed);

            resX = resolution_x;
            resY = resolution_y;
            freq = frequency;

            freqX = (float)resX / (float)freq;
            freqY = (float)resY / (float)freq;

            numGradients = (freqX -1) * (freqY - 1) + (freqX-1)*2 + (freqY -1)*2 + 4;
            gradients = new vector[numGradients];

            for(int i=0;i<numGradients;i++){
                gradients[i].i = (float)rand() / (RAND_MAX);
                gradients[i].j = (float)rand() / (RAND_MAX);
            }
             
            cout << "Initialized object. " << endl << "freqx and freqy:" << freqX << " " << freqY <<". Num gradients: " << numGradients << endl;
            cout << "SEED: " << seed << endl;
            for(int i=0;i<11;i++){
                for(int j=0;j<6;j++){
                    cout.precision(2);
                    cout << "[" << gradients[j+i].i << "," << gradients[j+1].j << "] ";
                }
                cout << endl;
            }
            
        }

        int noise(float x, float y){

            //find 4 verticies of the square containing given point
            int x0 = (int)x;
            int y0 = (int)y;
            int x1 = x0+1;
            int y1 = y0+1;

            //distance from corner
            float dx = x-(float)x0;
            float dy = y-(float)y0;
            return 0;

        }
};

int main(){
    
    //output should be 500x500 pixels
    const int resolution_x = 100;
    const int resolution_y = 50;

    int frequency = 10; //increase to get more detail. please use multiples of 10.
    int octaves = 10;

    int perlinMap[resolution_x][resolution_y];

    perlinNoise a(resolution_x, resolution_y, frequency);


    return 0;
}