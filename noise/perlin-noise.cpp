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
        int freqX; 
        int freqY;

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

            // //testing purposes: printing gradients list
            // cout << "Initialized object. " << endl << "freqx and freqy:" << freqX << " " << freqY <<". Num gradients: " << numGradients << endl;
            // cout << "SEED: " << seed << endl;
            // int L = 0;
            // for(int i=0;i<6;i++){
            //     for(int j=0;j<11;j++){
            //         cout.precision(3);
            //         cout << "[" << gradients[L].i << "," << gradients[L].j << "] ";
            //         L++;
            //     }
            //     cout << endl;

            // }
            
        }

        float dotProd(float x, float y, int cornerX, int cornerY, vector* gradients){
            float dx = x - (float)cornerX;
            float dy = y - (float)cornerY;

            float gradI = gradients[(cornerY)*freqX + cornerX+cornerY].i;
            float gradJ = gradients[(cornerY)*freqX + cornerX+cornerY].j;
            //cout << (cornerY)*freqX + cornerX;
            //cout  << endl;
            //cout << "THE POINT IS " << cornerX << "," << cornerY << endl;
            //cout << "THE GRADIENT IS " << "[" << gradI << "," << gradJ << "]" << endl;

            return (dx * gradI + dy*gradJ);
        }

        float cubicInterpolate(float p1, float p2, float weight){
            return (p2-p1) * (3.0-weight*2.0)*weight*weight+p1;
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



        float noise(float x, float y){

            //find 4 verticies of the square containing given point
            int x0 = (int)x;
            int y0 = (int)y;
            int x1 = x0+1;
            int y1 = y0+1;

            //distance from corner
            float dx = x-(float)x0;
            float dy = y-(float)y0;

            float topLeft = dotProd(x,y,x0, y0, gradients);
            float topRight = dotProd(x,y,x1, y0, gradients);
            float r1 = cubicInterpolate(topLeft, topRight, dx);

            float bottomLeft = dotProd(x,y,x0, y1, gradients);
            float bottomRight = dotProd(x,y,x1, y1, gradients);
            float r2 = cubicInterpolate(bottomLeft, bottomRight, dx);

            float finalVal = cubicInterpolate(r1, r2, dy);
            //cout << "X,Y,Result = [" << x << "," << y << "," << finalVal << "]";
            return finalVal;

        }
};

int main(){
    
    //output should be 500x500 pixels
    const int resolution_x = 300;
    const int resolution_y = 300;

    int frequency = 100; //increase to get more detail. please use multiples of 10.
    int octaves = 10;

    int islandSeed = 134;

    float perlinMap[resolution_x][resolution_y];

    perlinNoise a(resolution_x, resolution_y, frequency, islandSeed);

    
    for(int i=0; i<resolution_y; i++){
        for(int j=0;j<resolution_x;j++){
            //cout << i/(float)frequency << " ";
            float aa = a.noise(j/(float)frequency, i/(float)frequency);
            //float scaledValue = ((aa + 0.1) / 0.2) * 255.0;
            //cout << j << "," << i << "," << aa << endl;
            perlinMap[j][i] = (aa+0.5)*255;
        }
    }

    cout << "[";
    for(int i=0; i<resolution_y; i++){
        for(int j=0;j<resolution_x;j++){
            cout.precision(5);
            cout << perlinMap[j][i] << ",";
        }
        cout << endl;
    }
    cout << "]";
    



    return 0;
}