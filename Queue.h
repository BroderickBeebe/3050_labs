#ifndef _QUEUE_H
#define _QUEUE_H

#ifdef __cplusplus
extern "C" 
{
#endif

// Data types
typedef struct Node{
    void * item;
    struct Node *next;
}Node;
typedef struct Queue{
    Node * front;
    Node * rear;
}Queue;
// Prototypes
Queue * createQueue();
Node * createNode();
void enQueue(Queue * q, void * data);
void * deQueue(Queue * q);
int isEmpty(Queue *q);
void destroyQueue(Queue *q);

#ifdef __cplusplus
}
#endif

#endif