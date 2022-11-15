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

// Only Inserting the elements in the front
void insertFront(struct list *head, int ele)
{
    struct node *newNode = createNode(ele);
    newNode->next = head->headPointer;
    head->headPointer = newNode;
}

void display(struct list *head)
{
    struct node *traverse = head->headPointer;
    if (head->headPointer == NULL)
    {
        printf("No Elements to traverse.\n");
        return;
    }
    while (traverse != NULL)
    {
        printf("%d\n", traverse->data);
        traverse = traverse->next;
    }
    return;
}

void reverseList(struct list *head)
{
    struct node *curr = head->headPointer, *next = NULL, *prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->headPointer = prev;
}

int main()
{
    int testCase;
    scanf("%d", &testCase);
    int ele;
    struct list ordList;
    initList(&ordList);
    while (testCase--)
    {
        scanf("%d", &ele);
        insertFront(&ordList, ele);
    }
    printf("Elements in the list are:\n");
    display(&ordList);
    reverseList(&ordList);
    printf("Elements in the list (reversed):\n");
    display(&ordList);
    return 0;
}