#include"Array.h"
//构造函数
template<class T>
Array<T>::Array(int size){
    if(size<=0){
        Error(invalidArraySize);
    }
    this->size=size;
    alist=new T[this->size];
    if(alist==0)
        Error(memoryAllocationError);
}
//拷贝构造函数
template<class T>
Array<T>::Array(const Array<T>& other){
    int n=other.size;
    this->size=n;
    alist=new T[n];
    if(alist==0)
        Error(memoryAllocationError);
    T* srcptr=other.alist;
    T* dstptr=alist;
    while(n--){
        *dstptr++=*srcptr;
    }
}
//析构函数
template<class T>
Array<T>::~Array(void){
    delete[] alist;//释放内存
}
//赋值操作函数
template<class T>
Array<T>& Array<T>::operator=(const Array<T> &other ){
    int n=other.size;
    if(size!=n){
        delete[] alist;
        alist=new T[n];
        if(alist==0){
            Error(memoryAllocationError);
        }
        T* srcptr=other.alist;
        T* dstptr=alist;
        while(n--){
            *dstptr++=*srcptr++;
        }
        return *this;
    }
}
//[]运算符重载
template<class T>
T& Array<T>::operator[](int n){
    if(n<0||n>=size)
        Error(indexOutOfRange);
    return alist[n];
}
template<class T>
void Array<T>::Error(ErrorType error)const{
   std:: cout<<errorMsg[error]<<std::endl;
    exit(1);
}
template<class T>
void Array<T>::print(){
    for(int i=0;i<this->size;i++){
        std::cout<<" "<<alist[i];
    }
    std::cout<<std::endl;
}


int main(){
    Array<int> list(10);
    for(int i=0;i<10;i++)
        list[i]=i;
    list.print();
    return 0;
}

