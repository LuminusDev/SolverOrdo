#ifndef INSTANCETYPE1_H_INCLUDED
#define INSTANCETYPE1_H_INCLUDED
#include"Generator.h"
using namespace std;
class InstanceType1 : public virtual GeneratorCadre
{
public :
    InstanceType1(unsigned int n, unsigned int m):GeneratorCadre(n,m){}
    void virtual Generator();
};

#endif // INSTANCETYPE1_H_INCLUDED
