# include<iostream>
using namespace std;
class CComplex{
private:
    double real;
    double imag;
public:
    CComplex(double real=0,double imag=0){
        cout<<"Constructor Function is Called......"<<endl;
        this->real=real;
        this->imag=imag;
        this->display();
    }
    CComplex(CComplex& other){
        cout<<"Copy Constructor Function is Called......"<<endl;
        real=other.real;
        imag=other.imag;
        this->display();
    }
    operator int(){
        return (int)real;
    }
    void display(){
        cout<<"("<<real<<","<<imag<<")"<<endl;
    }
};
class CVector{
public:
    CVector(CComplex &obj1,CComplex &obj2,CComplex &obj3,CComplex &obj4){
        objArray[0]=obj1;
        objArray[1]=obj2;
        objArray[2]=obj3;
        objArray[3]=obj4;
    }
    CComplex& operator[] (int n);
private:
    CComplex objArray[4];
};
CComplex& CVector::operator[](int n){
    if(n<0||n>3){
       cout<<"Out of range!"<<endl;
       throw "Out of Index Range......";
    }
    return objArray[n];
}
int main(){
    CComplex obj1(1.1,1.1);
    CComplex obj2(2.1,2.1);
    CComplex obj3(3.1,3.1);
    CComplex obj4(4.1,4.1);

    CVector v(obj1,obj2,obj3,obj4);

    v[0].display();
    v[1].display();
    v[2].display();
    v[3].display();

    v[0]=5.5;//1
    v[0].display();
    v[1]=CComplex(6.1,6.1);//2
     v[1].display();
    CComplex test=v[1];
    v[2]=(int)(CComplex(7.1));//3
    v[2].display();
    v[3]=(int)(CComplex(8.1,8.1));//4
    v[3].display();
    return 0;
}
