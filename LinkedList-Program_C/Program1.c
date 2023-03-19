#include<stdio.h>
#include<stdlib.h>

struct node
{
    int Data;
    struct node *Next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head,  int No)
{
    PNODE newn = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));
    newn->Data = No;
    newn->Next = NULL;
    
    if(*Head == NULL)      
    {
        *Head = newn;
    }
    else                            
    {
        newn->Next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head,  int No)
{
    PNODE newn = NULL;
    PNODE temp = *Head;
    
    newn = (PNODE)malloc(sizeof(NODE));
    newn->Data = No;
    newn->Next = NULL;
    
    if(*Head == NULL)       
    {
        *Head = newn;
    }
    else                           
    {
        while(temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = newn;
    }
}

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("|%d|->\t",Head->Data);
        Head = Head -> Next;
    }
    printf("NULL\n");
}

int Count(PNODE Head)
{
    int iCnt = 0;
    while(Head != NULL)
    {
        iCnt++;
        Head = Head -> Next;
    }
    return iCnt;
}

void DeleteFirst(PPNODE Head)
{
        PNODE Temp = *Head;
        if(*Head == NULL)   
        {   return; }
        else if ((*Head) -> Next == NULL)   
        {
            free(*Head);       
            *Head = NULL;     
        }
        else    
        {
            (*Head) = (*Head)->Next;
            free(Temp);
        }
}

void DeleteLast(PPNODE Head)
{
    PNODE Temp = *Head;
    if(*Head == NULL)   
    {   return; }
    else if((*Head)->Next == NULL)  
    {
        free(*Head);        
        *Head = NULL;     
    }
    else    
    {
        while(Temp->Next->Next != NULL)
        {
            Temp = Temp -> Next;
        }
        free(Temp->Next);
        Temp -> Next = NULL;
    }
}

int main()
{
    int iRet = 0;
    PNODE First = NULL;
    InsertFirst(&First,51);     
    InsertFirst(&First,21);
    InsertFirst(&First,11);
    InsertLast(&First,111);
    
    printf("Actual nodes\n");
    Display(First);                 
    
    DeleteFirst(&First);
    printf("Nodes after delete first\n");
    Display(First);
    
    DeleteLast(&First);
    printf("Nodes after delete last\n");
    Display(First);
    
    return 0;
}































