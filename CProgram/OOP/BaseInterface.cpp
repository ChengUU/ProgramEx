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
    //接口类只提供接口方法，不提供实现
    //　BaseInterface base;// error
    //通过接口可以动态指定实例对象
    BaseInterface* base=new Person();
    base->eat();
    base=new Dog();
    base->eat();
    return 0;
}
