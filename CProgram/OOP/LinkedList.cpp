#include<iostream>
using namespace std;
template<class Type>
class LinkedList
{
private:
    class Node
    {
    public:
        Type data;
        Node* next;
        Node(const Type data,Node* next):data(data),next(next) {}
    };
    Node* header;
    int size;
public:
    //无参构造函数
    LinkedList();
    //使用LinkedList对象构造-拷贝构造函数
    LinkedList(LinkedList<Type> &c);
    //将一个链表添加到另一个链表
    bool addAll(LinkedList<Type> &c)
    {
        return addAll(size,c);
    }
    //从指定位置插入一个链表
    bool addAll(int index,LinkedList<Type> &c)
    {
        //if(index<0||index>size)error();
        //将链表转成对象数组
        Type* a=c.toArray();
        //链表长度
        int newNum=c.size;
        //若插入的链表为空
        if(newNum==0) return false;
        //获取插入节点位置，若插入节点是在size处，则是头结点，否则获取index处结点
        Node* successor=(index==size?header:entry(index));
        //插入链表
        for(int i=0; i<newNum; i++)
        {
            //构造新的结点,结点的下一跳为successor
            Node* e=new Node(a[i],successor->next);
            successor->next=e;
        }
        size+=newNum;
        return true;
    }
    //获取指定位置结点
    Node* entry(int index)
    {
        if(index<0||index>=size)
        {

        }
        Node* e=header;
        for(int i=0; i<=index; i++)
        {
            e=e->next;
        }
        return e;
    }
    bool add(Type e)
    {
        addBefore(e,header);
    }
    Node* addBefore(Type e,Node *entry)
    {
        Node* newEntry=new Node(e,entry->next);
        entry->next=newEntry;
        size++;
        return newEntry;
    }
    bool remove(Type o)
    {
        Node* previous=NULL;
        for(Node *temp=header; temp!=NULL; temp=temp->next)
        {
            if(o==temp->data)
            {
                remove(previous);
                return true;
            }
            previous=temp;
        }
        return false;
    }
    bool remove(Node* node)
    {
        Node* next=node->next;
        Type result=next->data;
        node->next=next->next;
        next->next=NULL;
        delete next;
        return result;
    }
    LinkedList<Type>& operator=(const LinkedList<Type>&other)
    {
        this=new LinkedList(other);
        return *this;
    }
    Type* toArray(){
        Type* array=new Type[size];
        Node* e=header;
        int i=0;
        while(e->next!=NULL){
            e=e->next;
            array[i++]=e->data;
        }
        return array;
    }
    void print(void)
    {
        Node* e=header;
        while(e->next!=NULL)
        {
            e=e->next;
            cout<<" "<<e->data;
        }
        cout<<endl;
    }

};
//无参构造函数
template<class Type>
LinkedList<Type>::LinkedList()
{
    header=new Node(NULL,NULL);
    this->size=0;
}
//使用LinkedList对象构造-拷贝构造函数
template<class Type>
LinkedList<Type>::LinkedList(LinkedList<Type> &c)
{
    this();
    addAll(c);
}
int main()
{
    /*
    LinkedList<int>* linkedlist=new LinkedList<int>();
    linkedlist->add(10);
    linkedlist->print();
    */
    LinkedList<int> temp;
    LinkedList<int> data;
    for(int i=0;i<100;i++){
        temp.add(i);
        data.add(i);
    }
    temp.print();
    temp.remove(55);
    temp.print();
    temp.addAll(data);
    temp.print();
    return 0;
}
