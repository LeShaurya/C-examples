#include <stdio.h>
#include <stdlib.h>

typedef struct priorityQueue
{
    int data;
    int priority;
    struct priorityQueue *next;
} NODE;

typedef struct queue
{
    NODE *front;
} QUEUE;

void initQueue(QUEUE *pq);
void enqueue(QUEUE *pq, int ele, int pty);
int minDelete(QUEUE *pq);
void destroyQueue(QUEUE *pq);

int main()
{
    QUEUE qobj;

    initQueue(&qobj);

    enqueue(&qobj, 100, 1);
    enqueue(&qobj, 10, 3);
    enqueue(&qobj, 50, 2);
    enqueue(&qobj, 50, 4);
    if (qobj.front != NULL)
        printf("%d\n", minDelete(&qobj));

    if (qobj.front != NULL)
        printf("%d\n", minDelete(&qobj));

    destroyQueue(&qobj);
    return 0;
}

void initQueue(QUEUE *pq)
{
    pq->front = NULL;
}

void enqueue(QUEUE *pq, int ele, int pty)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = ele;
    newNode->priority = pty;
    NODE *traverse = pq->front;
    NODE *behind = NULL;
    while (traverse != NULL && newNode->priority > traverse->priority)
    {
        behind = traverse;
        traverse = traverse->next;
    }
    if (behind == NULL)
    {
        newNode->next = traverse;
        pq->front = newNode;
    }
    else
    {
        newNode->next = traverse;
        behind->next = newNode;
    }
}

int minDelete(QUEUE *pq)
{
    NODE *removed = pq->front;
    int ele = pq->front->data;
    pq->front = pq->front->next;
    free(removed);

    return ele;
}

void destroyQueue(QUEUE *pq)
{
    NODE *p = pq->front;
    while (pq->front != NULL)
    {
        pq->front = pq->front->next;
        printf("%d deleted\n", p->data);
        free(p);
        p = pq->front;
    }
}