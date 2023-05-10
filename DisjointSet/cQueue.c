#include <stdio.h>

#define SIZE (5)

typedef struct cQueue
{
    int front;
    int rear;
    int arr[SIZE];
}cQueue;

void initQueue(cQueue *cq){
    cq->front = cq->rear = -1;
    
    for (int i = 0; i < SIZE; i++)
    {
        cq->arr[i] = -1;
    }
}

int isEmpty(cQueue cq){
    if(cq.front == cq.rear){
        return 1;
    }
    else return 0;
}

void enque(cQueue *cq, int data){

    if(cq->front == -1){
        cq->front = cq->rear = 0;
    }
    else{
        if((cq->rear + 1) % SIZE == cq->front){
            printf("Queue is full\n");
            return;
        }
        else{
            cq->rear = (cq->rear + 1) % SIZE;
        }
    }
    cq->arr[cq->rear] = data;
}

int deque(cQueue *cq){
    int temp;
    if(cq->front == -1){
        printf("UNDERFLOW!");
        return -1;
    }
    else{
        temp = cq->arr[cq->front];
        if(cq->front == cq->rear){
            cq->front = cq->rear = -1;
        }
        else{
            cq->front = (cq->front + 1) % SIZE;
        }
    }
    return temp;
}

int front(cQueue *cq){
    return cq->arr[cq->front];
}

void printQueue(const cQueue cq){
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ",cq.arr[i]);
    }
    printf("\n");
}

int main(){
    cQueue cq;
    initQueue(&cq);

    enque(&cq,4);
    enque(&cq,5);
    enque(&cq,6);
    enque(&cq,7);
    enque(&cq,1);
    enque(&cq,19);
    printQueue(cq);
    printf("Front : %d\n",front(&cq));

    for (int i = 0; i < SIZE; i++)
    {
        deque(&cq);
    }
    printQueue(cq);
    return 0;
}