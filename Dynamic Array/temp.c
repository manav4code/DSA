#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX_ARGS 10

pthread_mutex_t mutex;
int sum = 0;

typedef struct threadArg{
    void* argptr[MAX_ARGS];
}threadArg;


void updateSum(int x){
    pthread_mutex_lock(&mutex);
    sum += x;
    pthread_mutex_unlock(&mutex);
    return;
}

void printArray(int *arr,int size){
    for(int i = 0; i < size; ++i){
       printf("%d ",arr[i]);
    }
    printf("\n");
    return;
}

void *arraySum(void* args){
    threadArg* arg = (threadArg*)args;
    int* arr = (int*)arg->argptr[0];
    int* size = (int*)arg->argptr[1];

    int tempSum = 0;
    for(int i = 0; i < (*size); i++){
        tempSum += (*(arr + i));
    }
    updateSum(tempSum);
    arr = NULL; size = NULL;
}

int main(){
    int arr[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int size = 14;

    pthread_t tid;
    pthread_mutex_init(&mutex,NULL);

    threadArg *args = (threadArg*)malloc(sizeof(threadArg));
    args->argptr[0] = (void*)arr;
    args->argptr[1] = (void*)(&size);

    pthread_create(&tid,NULL,arraySum,args);
    pthread_join(tid,NULL);

    pthread_mutex_destroy(&mutex);

    printf("Sum: %d",sum);

    return 0;
}