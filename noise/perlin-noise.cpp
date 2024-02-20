#include <iostream>
#include <cstdlib>
#include <cmath>    
using namespace std;

//2d vector struct with i and j dimensions, mainly used for gradients
typedef struct{
    float i;
    float j;
} vector;

class perlinNoise{
    private:

        //resolution of output
        int resX;
        int resY;
        int freq;

        //size of grid
        float freqX; 
        float freqY;

        //use pointer to dynamically allocate number of gradients
        int numGradients; 
        vector* gradients;

        int seed;

        //function to generate unit gradients
        void generateGradients(int numGradients, vector* gradients, int seed){

            //gradients have random i and j vectors between -0.5 and 0.5
            for(int i=0;i<numGradients;i++){
                gradients[i].i = ((float)rand() / (RAND_MAX))-0.5;
                gradients[i].j = ((float)rand() / (RAND_MAX))-0.5;

                //normalizes vector size, ensuring they are all size 1
                double mag = sqrt(gradients[i].i * gradients[i].i + gradients[i].j * gradients[i].j);
                gradients[i].i /= mag;
                gradients[i].j /= mag;

            }

            //testing purposes: printing gradients list
            cout << "Initialized object. " << endl << "freqx and freqy:" << freqX << " " << freqY <<". Num gradients: " << numGradients << endl;
            cout << "SEED: " << seed << endl;
            int L = 0;
            for(int i=0;i<11;i++){
                for(int j=0;j<6;j++){
                    cout.precision(3);
                    cout << "[" << gradients[L].i << "," << gradients[L].j << "] ";
                    L++;
                }
                cout << endl;

            }
            
        }


    public:

        perlinNoise(int resolution_x, int resolution_y, int frequency, int islandSeed){

            //use user-defined seed to get reproducable results
            seed = islandSeed;
            srand(seed);

            resX = resolution_x;
            resY = resolution_y;
            freq = frequency;

            freqX = (float)resX / (float)freq;
            freqY = (float)resY / (float)freq;

            //calculate number of gradients needed (one for each corner of every box)
            numGradients = (freqX -1) * (freqY - 1) + (freqX-1)*2 + (freqY -1)*2 + 4;

            //dynamically create array to store gradient values
            gradients = new vector[numGradients];

            //generate random gradients
            generateGradients(numGradients, gradients, seed);

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

    int islandSeed = 3;

    int perlinMap[resolution_x][resolution_y];

    perlinNoise a(resolution_x, resolution_y, frequency, islandSeed);


    return 0;
}