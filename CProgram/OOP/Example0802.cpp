# include<iostream>
# include<string>
using namespace std;
class Motor{
private:
    int peoNum;
    int whlNum;
    int horsePower;
    string productCompany;
    string owner;
public:
    Motor(int peo_num=0,int whl_num=0,int horse_power=0,string pro_company="NULL",string owner="NULL"){
        peoNum=peo_num;
        whlNum=whl_num;
        horsePower=horse_power;
        productCompany=pro_company;
        this->owner=owner;
    }
    virtual  void display(){
        cout<<"peoNum:"<<peoNum<<endl;
        cout<<"whlNum:"<<whlNum<<endl;
        cout<<"horsePower:"<<horsePower<<endl;
        cout<<"productCompany:"<<productCompany<<endl;
        cout<<"owner:"<<owner<<endl;
    }
};
class Car:public Motor{
public:
    Car(int peo_num=0,int whl_num=0,int horse_power=0,string pro_company="NULL",
        string owner="NULL"):Motor(peo_num,whl_num,horse_power,pro_company,owner){}
    void display(){
        cout<<"----------Car--------"<<endl;
        Motor::display();
    }
};

class Bus:public Motor{
private:
    int number;
public:
    Bus(int number,int peo_num=0,int whl_num=0,int horse_power=0,string pro_company="NULL",
        string owner="NULL"):Motor(peo_num,whl_num,horse_power,pro_company,owner){
            this->number=number;
        }
     void display(){
        cout<<"--------Bus--------"<<endl;
        Motor::display();
        cout<<"number:"<<number<<endl;
    }
};

class Truck:public Motor{
private:
    float weight;
public:
    Truck(float weight,int peo_num=0,int whl_num=0,int horse_power=0,string pro_company="NULL",
        string owner="NULL"):Motor(peo_num,whl_num,horse_power,pro_company,owner){
            this->weight=weight;
        }
    virtual void display(){
        cout<<"--------Truck--------"<<endl;
        Motor::display();
        cout<<"weight:"<<weight<<endl;
    }
};

void showInfo(Motor& obj){
    obj.display();
}


int main(){
    Car car(4,4,8);
    Bus bus(2,100,10,12);
    Truck truck(35.0f,1,12,15);
    Motor *motors[]={&car,&bus,&truck};
    for(int i=0;i<3;i++){
        showInfo(*motors[i]);
    }
    return 0;
}
