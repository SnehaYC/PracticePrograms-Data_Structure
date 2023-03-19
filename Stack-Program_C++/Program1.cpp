#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, * PNODE;

class Stack
{
private:
    PNODE Head;
    int iSize;
    
public:
    Stack();                
    ~Stack();             
    void Push(int);     
    int Pop();              
    void Display();
    int Count();
};

Stack::Stack()  
{
    this->Head = NULL;  
    this->iSize = 0;
}

Stack::~Stack()
{}

void Stack::Push(int iNo)   
{
    PNODE newn = new NODE;
    newn->data = iNo;
    newn->next = NULL;
    
    newn->next = Head;
    Head = newn;
    iSize++;
}

int Stack::Pop()    
{
    int iRet = -1;
    
    if(iSize == 0)
    {
        cout<<"Stack is empty\n";
    }
    else
    {
        PNODE temp = Head;
        Head = Head -> next;
        iRet = temp->data;
        delete temp;
        iSize--;
    }
    return iRet;
}

void Stack:: Display()
{
    PNODE temp = Head;
    
    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
}

int Stack::Count()
{
    return this->iSize;
}

int main()
{
    Stack sobj;
    int iOption =1, iRet = 0, iNo = 0;
    
    while(iOption != 0)
    {
        cout<<"Please select the option\n";
        cout<<"1 : Push the element\n";
        cout<<"2 : Pop the element\n";
        cout<<"3 : Display the elements\n";
        cout<<"4 : Count number of elements\n";
        cout<<"0 : Exit the aplication\n";
        cin>>iOption;
        
        switch(iOption)
        {
            case 1:
                cout<<"Enter the element to push\n";
                cin>>iNo;
                sobj.Push(iNo);
                break;
                
            case 2 :
                iRet = sobj.Pop();
                cout<<"Poped element is : "<<iRet<<"\n";
                break;
                
            case 3:
                cout<<"Elements of stack are\n";
                sobj.Display();
                break;
                
            case 4:
                iRet = sobj.Count();
                cout<<"Number of elements in stack are : "<<iRet<<"\n";
                break;
                
            case 0:
                cout<<"Thank you for using the applicatoion\n";
                break;
                
            default:
                cout<<"Please enter the proper option\n";
                break;
        }
    } 
    return 0;
}   
