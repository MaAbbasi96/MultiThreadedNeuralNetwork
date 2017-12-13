#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

long double fRand(long double fMin, long double fMax)
{
    srand(clock());
    long double f = (long double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int main(){
    ofstream file;
    file.open("InputFile2.txt");
    file << setprecision(15) << fixed;
    for(int i = 0; i < 25; i++)
        file << fRand(0, 50) << " " << fRand(0, 50) << " " << fRand(0, 50) << endl;
    file.close();
}