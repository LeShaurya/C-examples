#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct list
{
    struct node *headPointer;
};

void initList(struct list *head)
{
    head->headPointer = NULL;
}

struct node *createNode(int ele)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = ele;
    newNode->next = NULL;

    return newNode;
}

void insertFront(struct list *head,struct node *newNode)
{
    newNode->next = head->headPointer;
    head->headPointer = newNode;
}

void insertNode(struct list *head, int ele)
{
    struct node *newNode = createNode(ele);
    struct node *p = head->headPointer,*q = NULL;
    while(p!=NULL && newNode->data > p->data)
    {
        q = p;
        p = p->next;
    }

    if(q == NULL)
        insertFront(head,newNode);
    
    else
    {
        q->next = newNode;
        newNode->next = p;
    }

}

void display(struct list *head)
{
    struct node *traverse = head->headPointer;
    if(head->headPointer == NULL)
    {
        printf("No Elements to traverse.\n");
        return;
    }
    while (traverse != NULL)
    {
        printf("%d\n",traverse->data);
        traverse = traverse->next;
    }
    return;
    
}

int main()
{
    int testCase;
    scanf("%d",&testCase);
    int ele;
    struct list ordList;
    initList(&ordList);
    while (testCase--)
    {
        scanf("%d", &ele);
        insertNode(&ordList, ele);
    }
    printf("Elements in the ordered list are:\n");
    display(&ordList);
    return 0;
}