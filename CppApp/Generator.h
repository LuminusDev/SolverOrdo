#ifndef GENERATOR_H_INCLUDED
#define GENERATOR_H_INCLUDED
#include<string>
#include<fstream>
using namespace std;
class GeneratorCadre
{

public :
    unsigned int N;
    unsigned int M;
    unsigned int T;
    int **C;
    int *P;

    GeneratorCadre(unsigned int n, unsigned  int m);
    void virtual Generator()=0;
    void setData(string filename);
};

#endif // GENERATOR_H_INCLUDED
