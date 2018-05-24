# include<iostream>
using namespace std ;
class CComplex{
private:
    float real;
    float imag;
public:
    CComplex(){
        new (this)CComplex(0.0,0.0);
    }
    CComplex(float x,float y){
        real=x,
        imag=y;
    }
    CComplex(CComplex &other){
        real=other.real;
        imag=other.imag;
    }
    float getReal(){
        return real;
    }
    float getImag(){
        return imag;
    }
    CComplex operator+(CComplex &obj1){
        CComplex obj3(obj1.real+real,obj1.imag+imag);
        return obj3;
    }
    //后置++
    CComplex& operator++(int){
        CComplex obj=*this;
        ++obj;
        return obj;
    }
    //前置++
    CComplex& operator++(){
        real+=1;
        imag+=1;
        return *this;
    }
    //后置--
    CComplex& operator--(int){
        CComplex temp=*this;
        --temp;
        return temp;
    }
    //后置--
    CComplex& operator--(){
        real-=1;
        imag-=1;
        return *this;
    }
    void print(){
        cout<<real<<"+"<<imag<<"i"<<endl;
    }
};
int main(){
    CComplex obj1(2.1,3.2);
    CComplex obj2(3.6,2.5);
    cout<<"obj1=";
    obj1.print();
    cout<<"obj2=";
    obj2.print();
    CComplex obj3;
    obj3=obj1+obj2;
    cout<<"obj3=";
    obj3.print();
    ++obj3;
    cout<<"after ++obj3,obj3=";
    obj3.print();
    --obj3;
    cout<<"after --obj3,obj3=";
    obj3.print();
    CComplex obj4=++obj3;
    cout<<"obj4=";
    obj4.print();
    return 0;
}
