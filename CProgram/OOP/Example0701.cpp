# include<iostream>
using namespace std;
class CComplex{
public:
    CComplex(){
        real=0;
        imag=0;
    }
    CComplex(int x,int y){
           real=x;
           imag=y;
    }
    CComplex(CComplex &other){
        real=other.real;
        imag=other.imag;
    }
    int real;
    int imag;

    CComplex operator+(CComplex obj){
        CComplex obj2(real+obj.real,imag+obj.imag);
        return obj2;
    }
};
int main(){
        CComplex obj1(100,30);
        CComplex obj2(20,30);
        CComplex obj;
        obj=obj1+obj2;
        cout<<obj.real<<endl;
        cout<<obj.imag<<endl;
        return 0;
    }
