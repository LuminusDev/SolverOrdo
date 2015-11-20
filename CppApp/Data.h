#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include<string>
using namespace std;
class Data
{
private :
    unsigned int N ;
    unsigned int M ;
    unsigned int T ;
    int **C;
    int *P;
public :
    Data(const string namefile);
    Data(unsigned int N, unsigned int M, unsigned int T, int** C, int* P);

    int getN() const ;
    int getM() const ;
    int getT() const ;
    int** getC() const ;
    int* getLineC(int i) const ;
    int* getColumnC(int i) const ;
    int getValueC(int i, int j) const ;
    int* getP() const ;
    int getValueP(int i) const ;

    void setN(unsigned int n);
    void setM(unsigned int m);
    void setT(unsigned int t);
    void setValueC(unsigned int i, unsigned int j, unsigned value);
    void setValueP(unsigned int i, int value);

    string toString();

    ~Data()
    {
        for(int i=0 ; i<N ; ++i){
			delete[] C[i];
		}
		delete[] C;
		delete[] P;
    }

};

#endif // DATA_H_INCLUDED
