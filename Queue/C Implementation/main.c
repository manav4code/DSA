/*MAIN FILE*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdbool.h>
#include "queue.h"

#define endl printf("\n")

void printQueue(Qnode* front){
    Qnode* curr = front;
    while(curr){
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
    return;
}

int main(){
    Qnode* front = NULL;
    Queue_push(&front,1);
    Queue_push(&front,2);
    Queue_push(&front,3);
    Queue_push(&front,5);
    
    int Qsize = Queue_size(front);
    printf("Size = %d",Qsize);endl;

    printQueue(front);

    return 0;
}
