#include <stdio.h>
#include <stdlib.h>

#define left(i) (2*i + 1)
#define right(i) (2*i + 2)
#define parent(i) ((i-1)/2)

typedef struct Pair
{
    int data;
    int priority;    
}Pair;

void swapPair(Pair *a,Pair *b){
    Pair temp;

    // Swap Data
    temp.data = a->data;
    a->data = b->data;
    b->data = temp.data;

    // Swap Priority
    temp.priority = a->priority;
    a->priority = b->priority;
    b->priority = temp.priority;

    return;
}

void copyPair(Pair *new, const Pair old){
    new->data = old.data;
    new->priority = old.priority;

    return;
}

Pair getNullPair(){
    Pair pair;
    pair.data = -1;
    pair.priority = -1;
    return pair;
}

void heapify(Pair arr[],int index,int size){

    int left = left(index);
    int right = right(index);

    int smallest = index;

    if(left < (size) && arr[left].priority < arr[smallest].priority)
        smallest = left;
    
    if(right < (size) && arr[right].priority < arr[smallest].priority)
        smallest = right;

    if(index != smallest){
        swapPair(&arr[index], &arr[smallest]);
        heapify(arr,smallest,size);
    }
}

void insert(Pair arr[],int *size,int data,int priority){
    (*size)++;
    
    int index = (*size) - 1;
    
    arr[index].data = data;
    arr[index].priority = priority;

    while(index != 0 && arr[parent(index)].priority > arr[index].priority){
        swapPair(&arr[index], &arr[parent(index)]);
        index = parent(index);
    }
}

void print_pQue(Pair arr[],int size){

    printf("Priority Queue: \n");

    for(int i = 0; i < size; i++){
        printf("%d -> %d\n",arr[i].data,arr[i].priority);
    }

    printf("\n");
}

Pair getMin(Pair arr[], int *size){
    if((*size) == -1){
        printf("Underflow....\n");
        return getNullPair();
    }

    if((*size) == 0){
        (*size)--;
        return arr[(*size)];
    }

    Pair root;
    copyPair(&root,arr[0]);
    copyPair(&arr[0],arr[(*size)--]);

    heapify(arr,0,(*size));

    return root;

}


int main(){

    Pair pQue[100];
    int size = 0;

    insert(pQue,&size,10,5);
    insert(pQue,&size,20,3);
    insert(pQue,&size,30,4);
    insert(pQue,&size,40,2);
    insert(pQue,&size,50,1);
    insert(pQue,&size,60,6);

    print_pQue(pQue,size);

    for(int i = 0; i < size; i++){
        Pair temp;
        temp = getMin(pQue,&size);
        printf("%d -> %d\n",temp.data,temp.priority);
    }

    printf("\n");

    return 0;
}