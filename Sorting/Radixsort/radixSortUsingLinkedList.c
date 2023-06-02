#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* getNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

int getMax(int arr[],int size){
    int max = arr[0];

    for(int i = 1; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

Node* appendNode(Node* head, int data){
    if(!head) return getNode(data);

    Node* curr = head;
    while(curr->next) curr = curr->next;
    curr->next = getNode(data);

    return head;
}

void radixsort(int arr[], int size){
    
    int maxnum = getMax(arr,size);
    int exp = 1;

    while (maxnum)
    {
        Node* hash[10] = { NULL };

        for(int i = 0; i < size; i++){
            int hf = (arr[i]/exp)%10;
            hash[hf] = appendNode(hash[hf],arr[i]);
        }

        int index = 0;
        for(int i = 0; i < 10; i++){
            Node* curr = hash[i];
            while(curr){
                arr[index] = curr->data;
                Node* temp = curr;
                curr = curr->next;
                free(temp);
                index++;
            }
        }
        exp *= 10;
        maxnum /= 10;
    }
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");  
}

int main(){

    int arr[] = {3,5,2,6,9,8,19,10,100,35};
    int size = sizeof(arr)/sizeof(int);

    printf("Array: ");
    printArray(arr,size);

    radixsort(arr,size);
    printf("Sorted Array: ");
    printArray(arr,size);

    return 0;
}
