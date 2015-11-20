#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include"Generator.h"
#include"InstanceType1.h"
#include"Data.h"

using namespace std;

GeneratorCadre::GeneratorCadre(unsigned int n, unsigned  int m)
{
    N = n;
    M = m;
    T = 0;

    P = new int[N];
    for(int i = 0 ; i < N ; i++)
        P[i] = 0 ;

}
void GeneratorCadre::setData(string filename)
{
    Data matrix(N,M,T,C,P);
    ofstream f(filename.c_str(),ios::out);
    if(f.fail())
        cout<<"file cannot open"<<endl;
    else
        f << matrix.toString();
    f.close();
}
void InstanceType1 :: Generator()
{
    srand(time(NULL)); /* initialize random seed: */
    int somme =0;
    for(int j = 0 ; j < N ; j++)
    {
        P[j] = rand()%10;
        somme += P[j];
    }
    T = somme;
    C = new int*[N];
    for(int i = 0 ; i < N ; i++)
        C[i] = new int[T];

    for(int j = 0 ; j < N ; j++)
        C[j][0] = rand()%50 + 1;             /* generate secret number between 1 and 50 (fist cost of each job 'j' ) */
    for(int j = 0 ; j < N ; j++)
        for(int t = 1 ; t < T ; t++)
            C[j][t] = C[j][t-1] + rand()%50; /* generate secret cost such as it increases over time */
}
