#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
# include<iostream>
#include<stdlib.h>
//容错处理
enum ErrorType{
    invalidArraySize,memoryAllocationError,indexOutOfRange
};
//错误提示
char* errorMsg[]={
    "Invalid array size",
    "Memory allocation error",
    "Invalid index"
};
template<class T>
class Array{
private :
    T* alist;//顺序表指针
    int size;//表大小
    void Error(ErrorType error)const;//输出错误信息
public:
    Array(int size=0);//构造函数
    Array(const Array<T> &other);//拷贝构造函数
    ~Array(void);//析构函数
    Array<T>& operator=(const Array<T>& other);//重载赋值运算
    T& operator[](int i);//重载下标运算符
    int getSize(void) const;//获取当前列表长度
    void resize(int size);//重置顺序表长度
    void print(void);//输出列表元素

};




#endif // ARRAY_H_INCLUDED
