# include<iostream>
using namespace std;
class CComplex{
private:
    float real;
    float imag;
    friend CComplex operator+(CComplex &obj1,CComplex &obj2);
    friend CComplex& operator--(CComplex &obj);
    friend CComplex& operator--(CComplex &obj,int);
    friend CComplex& operator++(CComplex &obj);
    friend CComplex& operator++(CComplex &obj,int);
public:
    CComplex(){
        new (this)CComplex(0.0,0.0);
    }
    CComplex(float x,float y){
        real=x;
        imag=y;
    }
    CComplex(CComplex &other){
        real=other.real;
        imag=other.imag;
    }
    void print(){
        cout<<real<<"+"<<imag<<"i"<<endl;
    }
};
CComplex operator+(CComplex &obj1,CComplex &obj2){
    CComplex obj(obj1.real+obj2.real,obj1.imag+obj2.imag);
    return obj;
}
CComplex& operator--(CComplex &obj){
    obj.real-=1;
    obj.imag-=1;
    return obj;
}
CComplex& operator--(CComplex &obj,int){
    CComplex temp=obj;
    --obj;
    return temp;
}
CComplex& operator++(CComplex &obj){
    obj.real+=1;
    obj.imag+=1;
    return obj;
}
CComplex& operator++(CComplex &obj,int){
    CComplex temp=obj;
    ++obj;
    return temp;
}
int main(){
    CComplex obj1(2.5,5.2);
    CComplex obj2(5.2,2.5);
    CComplex obj3;
    obj3=obj1+obj2;
    obj3.print();
    obj3++;
    obj3.print();
    ++obj3;
    obj3.print();
    obj3--;
    obj3.print();
    --obj3;
    obj3.print();
    return 0;
}
