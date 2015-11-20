#include <iostream>
#include"Data.h"
#include"InstanceType1.h"
#include"Generator.h"
using namespace std;

int main()
{
    InstanceType1 Ins(5,2);
    Ins.Generator();
    Ins.setData("Instance1.dat");

    Data data("Instance1.dat");

    cout << data.toString();

    return 0;
}
