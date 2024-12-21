#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

// Creates a Queue pointer, allocates memory for it, then returns the node pointer.
Queue * createQueue() 
{
    Queue * Q = malloc(sizeof(Queue));  
    Q->front = NULL;  
    Q->rear = NULL;   
    return Q;
}

// Creates a Node pointer, allocates memory for it, and then returns the Node pointer
Node * createNode() 
{
    Node * node = malloc(sizeof(Node));  
    node->item = NULL; 
    node->next = NULL; 
    return node;
}

// adds an item to the Queue
void enQueue(Queue * Q, void * item) {
    Node * node = createNode(); 
    node->item = item;         
    if (Q->rear == NULL) 
    { 
        Q->front = node;  
        Q->rear = node;
    }
     else 
    {
        Q->rear->next = node; 
        Q->rear = node;        
    }
}

// Function to remove an item from the queue (dequeue)
void * deQueue(Queue * Q) 
{
    if (isEmpty(Q)) 
    {  // If the queue is empty, return NULL
        return NULL;
    }

    Node * node = Q->front;  // Get the front node
    Q->front = node->next;   // Move the front pointer to the next node

    if (Q->front == NULL) 
    {  // If the queue is now empty, reset the back pointer
        Q->rear = NULL;
    }

    void * item = node->item;  // Store the item to return
    free(node);                // Free the memory of the dequeued node
    return item;
}

// Function to check if the queue is empty
int isEmpty(Queue * Q) 
{
    return (Q == NULL || Q->front == NULL);  
}

// Destroys queue and frees memory
void destroyQueue(Queue * Q) 
{
    while (!isEmpty(Q)) 
    { 
        deQueue(Q);
    }
    free(Q); 
}