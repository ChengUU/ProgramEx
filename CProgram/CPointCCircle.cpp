# include<iostream>
using namespace std;
class CCircle;
class CPoint{
public:
    unsigned x;
    unsigned y;
    bool isInCircle(CCircle *circle){
        return (((x-circle->center.x)*(x-circle->center.x)+(y-circlr->center.y)*(y-circlr->center.y))<=circle->radius*circle->radius);
    }
};
class CCircle{
public:
    unsigned radius;
    CPoint center;
};
