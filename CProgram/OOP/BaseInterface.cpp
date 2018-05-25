# include<iostream>
using namespace std;
class BaseInterface{
public:
    virtual void eat()=0;
    ~BaseInterface(){}
};
class Person:public BaseInterface{
public:
    void eat(){
        cout<<"Person eat()......"<<endl;
    }
};
class Dog:public BaseInterface{
public:
    void eat(){
        cout<<"Dog eat()......"<<endl;
    }
};
int main(){
    BaseInterface* base=new Person();
    base->eat();
    return 0;
}
