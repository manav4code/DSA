#ifndef QUEUE_H
#define QUEUE_H

typedef struct Qnode
{
    int data;
    struct Qnode* next;
}Qnode;

/*
DOCS

This header file includes all Queue Basic 
Functions implemented in C.
*/

// Inserts in queue at the end
void Queue_push(Qnode** queueNode, int data);

// Deletes front element
void Queue_pop(Qnode** queueNode);

// Returns the number at front
int Queue_front(Qnode* queueNode);

// Returns whether the queue is empty or not
bool Queue_empty(Qnode* queueNode);

// Returns the size of the queue.
int Queue_size(Qnode* queueNode);

#endif