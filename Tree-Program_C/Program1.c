#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}NODE,*PNODE, **PPNODE;

void InsertNode(PPNODE Head, int iNo)
{
    PNODE temp = *Head;
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->lchild = NULL;
    newn->rchild = NULL;
    
    if(*Head == NULL)
    {
        *Head = newn;
    }
    else            
    {
        while(1)
        {
            if(iNo > temp->data)    
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(iNo < temp->data)   
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
            else if(iNo == temp->data)  
            {
                printf("Duplicate element\n");
                free(newn);
                break;
            }
        }
    }
}

void Inorder(PNODE Head)    
{
    if(Head != NULL)
    {
        Inorder(Head->lchild);     
        printf("%d\t",Head->data);  
        Inorder(Head->rchild);  
    }
}
void Postorder(PNODE Head)  
{
    if(Head != NULL)
    {
        Postorder(Head->lchild);  
        Postorder(Head->rchild); 
        printf("%d\t",Head->data); 
    }
}
void Preorder(PNODE Head)   
{
    if(Head != NULL)
    {
        printf("%d\t",Head->data); 
        Preorder(Head->lchild);  
        Preorder(Head->rchild);  
    }
}

int Count(PNODE Head)
{
    static  int iCnt = 0;
    
    if(Head != NULL)
    {
        iCnt++;
        Count(Head->lchild);
        Count(Head->rchild);
    }
    
    return iCnt;
}

 int main()
{
    PNODE Root = NULL;
    int iChoice = 1, iNo = 0, iRet = 0;
    while(iChoice != 0)
    {
        printf("Enter your choice\n");
        printf("1 : Insert node\n");
        printf("2 : Display Inorder\n");
        printf("3 : Display Preorder\n");
        printf("4 : Display Postorder\n");
        printf("5 : Count nodes\n");
        printf("0 : Terminate the appplication");
        
        scanf("%d",&iChoice);
        
        switch(iChoice)
        {
            case 1 :
                printf("Enter number\n");
                scanf("%d",&iNo);
                InsertNode(&Root,iNo);
                break;
                
            case 2 :
                printf("Inorder traversal\n");
                Inorder(Root);
                printf("\n");
                break;
                
            case 3:
                printf("Preorder traversal\n");
                Preorder(Root);
                printf("\n");
                break;
            
            case 4:
                printf("Postorder traversal\n");
                Postorder(Root);
                printf("\n");
                break;
                
            case 5:
                iRet = Count(Root);
                printf("Number of nodes are : %d\n",iRet);
                break;
                
            case 0:
                printf("Thank you for using appplication\n");
                break;
                
            default:
                printf("Please enter proper choice\n");
                break;
        } 
    }  
    return 0;
}   
