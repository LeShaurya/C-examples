#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

typedef struct circularList
{
    NODE *head, *tail;
} cList;

NODE *createNode(int ele)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = ele;
    newNode->next = NULL;
    return newNode;
}

void createList(cList *list, int n)
{
    list->head = NULL;
    list->tail = NULL;
    for (int i = 1; i <= n; i++)
    {
        NODE *newNode = createNode(i);
        // Empty List
        if (list->head == NULL || list->tail == NULL)
        {
            list->head = newNode;
            newNode->next = newNode;
            list->tail = newNode;
        }
        // Rear Insertion
        else
        {
            newNode->next = list->head;
            list->tail->next = newNode;
            list->tail = newNode;
        }
    }
}

void display(cList *list)
{
    NODE *traverse = list->head;
    do
    {
        printf("%d ", traverse->data);
        traverse = traverse->next;
    } while (traverse != list->head);
    printf("\n");
}

int winner(cList *list, int st, int sk)
{
    NODE *p = list->head, *q = list->tail;
    while (p->data != st)
    {
        q = p;
        p = p->next;
    }
    while (p != p->next)
    {
        for (int i = 0; i < sk; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        printf("%d is killed\n", p->data);
        free(p);
        p = q->next;
    }
    int ele = p->data;
    free(p);
    list->head = list->tail = NULL;
    return ele;
}

int main()
{
    cList JosephusList;
    int numberOfSoldiers, startVal, skipVal;
    scanf("%d", &numberOfSoldiers);
    createList(&JosephusList, numberOfSoldiers);
    display(&JosephusList);
    scanf("%d%d", &startVal, &skipVal);
    printf("%d is winner\n", winner(&JosephusList, startVal, skipVal));
    return 0;
}