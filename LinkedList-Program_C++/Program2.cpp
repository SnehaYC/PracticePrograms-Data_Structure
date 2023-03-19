#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE;

class SinglyCL
{
private:
    PNODE Head;
    PNODE Tail;
    int iSize;
    
public:
    SinglyCL()
    {
        Head = NULL;
        Tail = NULL;
        iSize = 0;
    }
    
    void InsertFirst(int iNo)
    {
        PNODE newn = NULL;
        
        newn = new NODE;
        newn -> data = iNo;
        newn->next = NULL;
        
        if((Head == NULL) && (Tail == NULL))    
        {
            Head = newn;
            Tail = newn;
        }
        else    
        {
            newn->next = Head;
            Head = newn;
        }
        iSize++;
        Tail -> next = Head;
    }
    
    void InsertLast(int iNo)
    {
        PNODE newn = NULL;
        
        newn = new NODE;
        newn -> data = iNo;
        newn->next = NULL;
        
        if((Head == NULL) && (Tail == NULL))    
        {
            Head = newn;
            Tail = newn;
        }
        else   
        {
            Tail->next = newn;
            Tail = Tail->next;      
        }
        iSize++;
        Tail -> next = Head;
    }
    
    int Count()
    {
        return iSize;
    }
    
    void Display()
    {
        PNODE temp = Head;
        int i = 0;
        for(i=1; i <= iSize; i++)
        {
            cout<<temp->data<<"\t";
            temp = temp -> next;
        }
        cout<<"\n";
    }
    
    void DeleteFirst()
    {
        if(iSize == 0)   
        {
            return;
        }
        else if(iSize == 1)   
        {
            delete Head;
            Head = NULL;
            Tail = NULL;
            iSize--;
        }
        else        
        {
            Head = Head -> next;
            delete(Tail->next);
            Tail->next = Head;
            iSize--;
        }
    }
    
    void DeleteLast()
    {
        if(iSize == 0)    
        {
            return;
        }
        else if(iSize == 1)   
        {
            delete Head;
            Head = NULL;
            Tail = NULL;
            iSize--;
        }
        else        
        {
            PNODE temp = Head;
            int i = 0;
            for(i = 1; i < iSize-1; i++)
            {
                temp = temp -> next;
            }
            delete Tail;
            Tail = temp;
            Tail->next = Head;
            iSize--;
        }
    }
};

int main()
{
    SinglyCL obj;
    int iChoice = 1, iRet = 0, iPos = 0, iValue = 0;
    
    while(iChoice != 0)
    {
        cout<<"Enter your choice\n";
        cout<<"1 : Insert First\n";
        cout<<"2 : Insert Last\n";
        cout<<"3 : Insert at position\n";
        cout<<"4 : Delete first \n";
        cout<<"5 : Delete Last\n";
        cout<<"6 : Delete at position \n";
        cout<<"7 : Display the contents\n";
        cout<<"8 : Count the elements\n";
        cout<<"0 : Exit the application\n";
        cin>>iChoice;
        
        switch(iChoice)
        {
            case 1:
                cout<<"Enter number\n";
                cin>>iValue;
                obj.InsertFirst(iValue);
                break;
                
            case 2:
                cout<<"Enter number\n";
                cin>>iValue;
                obj.InsertLast(iValue);
                break;
                
            case 3:
                cout<<"Enter number\n";
                cin>>iValue;
                cout<<"Enter position\n";
                cin>>iPos;
                //obj.InsertAtPos(iValue,iPos);
                break;
                
            case 4 :
                obj.DeleteFirst();
                break;
                
            case 5 :
                obj.DeleteLast();
                break;
                
            case 6:
                cout<<"Enter the position\n";
                cin>>iPos;
               // obj.DeleteAtPos(iPos);
                break;
                
            case 7:
               obj.Display();
                break;
                
            case 8:
               iRet = obj.Count();
                cout<<"Number of nodes are : "<<iRet<<"\n";
                break;
                
            case 0:
                cout<<"Thank you for using the application\n";
                break;
                
            default:
                cout<<"Please enter proper option\n";
                break;
        }
    }
    return 0;
} 































