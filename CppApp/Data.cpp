#include"Data.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

Data::Data(const string namefile){
    ifstream file(namefile.c_str(),ios::in);
    if(file)
    {
        char c;

        file >> c >> c >> N >> c;  // Read N
        file >> c >> c >> M >> c;  // Read M
        file >> c >> c >> T >> c;  // Read T
        P = new int[N];            // allocation of P
        file >> c >> c >> c;
        for(int i = 0 ; i < N ; i++)
            file >> P[i] >> c ;
        file >> c;

        C = new int*[N];            // allocation of C
        for(int i = 0 ; i < N ; i++)
            C[i] = new int[T];

        file >> c >> c >> c;
        for(int i = 0 ; i < N ; i++)
        {
            file >> c;
            for(int t = 0 ; t < T ; t++)
                file >> C[i][t] >> c;
            file >> c;
        }
        file >> c >> c;

        file.close();
    }
    else
        cout << "file cannot be open" ;
}
Data::Data(unsigned int n, unsigned int m, unsigned int t, int** c, int* p){
    this->N = n;
    this->M = m;
    this->T = t;
    this->C = new int*[N];
    for(int i = 0 ; i < N ; i++)
        this->C[i] = new int[T];
    for(int i = 0 ; i < N ; i++)
        for(int t = 0 ; t < T ; t++)
            this->C[i][t] = c[i][t];
    this->P = new int[N];
    for(int i = 0 ; i < N ; i++)
        this->P[i] = p[i];
}

int Data::getN() const {
    return N;
}
int Data::getM() const {
    return M;
}
int Data::getT() const {
    return T;
}
int** Data::getC() const {
    return C;
}
int* Data::getLineC(int i) const {
    return C[i];
}
int* Data::getColumnC(int i) const {
    int T[N];
    for(int j = 0 ; j < N ; j++)
        T[i] = C[j][i];
}
int Data::getValueC(int i, int j) const {
    return C[i][j];
}
int* Data::getP() const {
    return P;
}
int Data::getValueP(int i) const {
    return P[i];
}

void Data::setN(unsigned int n){
    this->N = n;
}
void Data::setM(unsigned int m){
    this->M = m;
}
void Data::setT(unsigned int t){
    this->T = t;
}
void Data::setValueC(unsigned int i, unsigned int j, unsigned value){
    this->C[i][j] = value;
}
void Data::setValueP(unsigned int i, int value){
    this->P[i] = value;
}
string Data::toString(){
    stringstream information;
    information << "N="; information << this->getN(); information << ";\n";
    information << "M="; information << this->M; information << ";\n";
    information << "T="; information << this->T; information << ";\n";
    information << "P=[";
    for(int i = 0 ; i < N ; i++)
    {
        information <<P[i];
        if(i == N-1)
            information << "];\n";
        else
            information << ",";
    }

    information << "C=[ \n";
    for(int j = 0 ; j < N ; j++)
    {
        information << "[" ;
        for(int t = 0 ; t < T-1 ; t++)
        {
            information << C[j][t]; information << ",";
        }
        information << C[j][T-1];
        information << "]";
        if(j == N-1)
            information << " ];";
        else
            information << ", \n";
    }
    return information.str();
}
