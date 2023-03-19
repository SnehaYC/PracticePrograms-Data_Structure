using namespace std;
#include<iostream>

 typedef struct node
 {
    int data;
    struct node *next;
 }NODE, *PNODE;
 
class SinglyLL
{
private:
    PNODE Head;
    int iSize;
    
public:
    SinglyLL()      
    {
        Head = NULL;
        iSize = 0;
    }
    
    int Count()
    {
        return iSize;
    }
    
    void Display()
    {
        PNODE temp = Head;
        while(temp != NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp -> next;
        }
        cout<<"\n";
    }
    
    void InsertFirst(int iValue)
    {
        PNODE newn = NULL;
        newn = new NODE;
        newn->data = iValue;
        newn->next = NULL;
        
        if(Head == NULL)    
        {
            Head = newn;
        }
        else   
        {
            newn->next = Head;
            Head = newn;
        }
        iSize++;
    }
    
    void InsertLast(int iValue)
    {
        PNODE newn = NULL;
        newn = new NODE;
        newn->data = iValue;
        newn->next = NULL;
        
        PNODE temp = Head;
        if(Head == NULL)    
        {
            Head = newn;
        }
        else    
        {
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = newn;
        }
        iSize++;
    }
    
    void DeleteFirst()
    {
            if(Head != NULL)
            {
                PNODE temp = Head;
                Head = Head -> next;
                delete temp;
                iSize--;
            }
    }
    
    void DeleteLast()
    {
        if(Head == NULL)
        {
            return;
        }
        else if (Head -> next == NULL)
        {
            delete Head;
            Head = NULL;
            iSize--;
        }
        else
        {
            PNODE temp = Head;
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete (temp->next);
            temp->next = NULL;
            iSize--;
        }
    }
};

int main()
{
    int iChoice = 1,iNo = 0;
    
    SinglyLL obj1;
    
    while(iChoice != 0)
    {
        cout<<"Enter your choice :"<<"\n";
        cout<<"1 : Insert at first position "<<"\n";
        cout<<"2 : Insert at last position "<<"\n";
        cout<<"3 : Insert at given position "<<"\n";
        cout<<"4 : Delete first node "<<"\n";
        cout<<"5 : Delete last node "<<"\n";
        cout<<"6 : Delete node at give position "<<"\n";
        cout<<"7 : Display the contents "<<"\n";
        cout<<"8 : Count the number of nodes "<<"\n";
        cout<<"0 : Exit the application "<<"\n";
        cin>>iChoice;
        
        switch(iChoice)
        {
            case 1:
                cout<<"Enter number\n";
                cin>>iNo;
                obj1.InsertFirst(iNo);
                break;
                
            case 2:
                cout<<"Enter number\n";
                cin>>iNo;
                obj1.InsertLast(iNo);
                break;
            
            case 3:
                break;
            
            case 4:
                obj1.DeleteFirst();
                break;
            
            case 5:
                obj1.DeleteLast();
                break;
                
            case 6:
                break;
            
            case 7:
                obj1.Display();
                break;
            
            case 8:
                iNo = obj1.Count();
                cout<<"Number of elements are : "<<iNo<<"\n";
                break;
                
            case 0:
                cout<<"Thank you for using the application\n";
                break;
                
            default:
                cout<<"Please enter procper option\n";
                break;
        }
    }
    return 0;
}
