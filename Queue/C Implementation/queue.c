#include<stdlib.h>
#include<stdbool.h>


#include "queue.h"

/* 
Queue implementation using linked list

-->Important Functions
> push
> pop
> front
> empty
> size

*/

void Queue_push(Qnode** queueNode, int data){
    
    Qnode* temp = (Qnode*)malloc(sizeof(Qnode));
    temp->data = data;
    temp->next = NULL;

    // If Queue empty
    if((*queueNode) == NULL){
        (*queueNode) = (Qnode*)malloc(sizeof(Qnode));
        (*queueNode)->data = data;
        (*queueNode)->next = NULL;
        return;
    }

    // Get Tail if Queue not empty
    Qnode* curr = (*queueNode);
    while(curr->next){
        curr = curr->next;
    }

    curr->next = temp;
    return;
}

void Queue_pop(Qnode** queueNode){
    if((*queueNode) == NULL) return;

    Qnode* temp = (*queueNode);
    (*queueNode) = temp->next;

    free(temp);
    return;
}

int Queue_front(Qnode* queueNode){
    return queueNode->data;
}

bool Queue_empty(Qnode* queueNode){
    if(queueNode)return true;
    else return false;
}

int Queue_size(Qnode* queueNode){
    
    if(queueNode == NULL) return 0;
    return (1 + Queue_size(queueNode->next));

}


