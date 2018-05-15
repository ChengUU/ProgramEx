# include<iostream>
using namespace std;
class CPerson{
public:
    //CPerson(int age,char *name);
    void Print();
private:
    CPerson();
private:
    int age;
    char *name;
};
CPerson::CPerson(){
}
CPerson::CPerson(int age,char *name){
    this->age=age;
    this->name=name;
}
void CPerson::Print(){
    cout<<"name="<<name<<",age="<<age<<endl;
}
int main(){
    CPerson ps(23,"Zhang San");
    ps.Print();
    return 0;
}
