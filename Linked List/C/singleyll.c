#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX_ITR 50

// Singley Linked List
typedef struct Node
{
    int data;
    struct Node* next;
}Node;

// Structure for passing thread arguments
typedef struct threadArgs{
    void *args[10];
    void *res;
}threadArgs;


// Thread function to return tail node
void *getLast(void* args){
    threadArgs *arg = (threadArgs *)args;

    // Head to the list
    struct Node* head = (struct Node*)(arg->args[0]);

    struct Node* curr = head;

    while(curr->next){
        curr = curr->next;
    }

    // Storing result back in res;

    arg->res = (void*)(curr);
    curr = NULL;
}


// Function to insert element at the back of the linked list
void appendList(struct Node** head,int k){

    // If List is empty
    if(*head == NULL){
        *head = (struct Node*)malloc(sizeof(struct Node));
        (*head)->data = k;
        (*head)->next = NULL;
        return;
    }

    // Passing Node* head as argument
    threadArgs *arg = (threadArgs*)malloc(sizeof(threadArgs));
    arg->args[0] = (void*)(*head);

    // Creating thread
    pthread_t t;
    pthread_create(&t,NULL,getLast,arg);

    // Function task continues..
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = k;
    temp->next = NULL;

    pthread_join(t,NULL);

    // Pointing the next of current tail to the new tail node
    struct Node* currentTail = (struct Node*)(arg->res);
    currentTail->next = temp;

    temp = NULL;
    free(arg);
    return;
}

// Reversing a Linked List

void reverseList(Node** head){
    Node* curr = (*head);
    Node* prev = NULL;
    Node* next = NULL;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    (*head) = prev;
    prev = NULL;
    curr = NULL;
    next = NULL;
    return;
}

// Copying List 
Node* copyList(Node* head){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = -1;

    Node* newList = newNode;

    Node* curr = head;

    while(curr){
        newList->next = (Node*)malloc(sizeof(Node));
        newList = newList->next;
        newList->data = curr->data;
        curr = curr->next;
    }

    newList->next = NULL;

    newList = newNode->next;
    free(newNode);
    return newList;
}


// Printing the Linked List
void printList(struct Node* head){
    int count = MAX_ITR;
    struct Node* curr = head;
    printf("\n");
    while(curr && (count--)){
        printf("%d\t",curr->data);
        curr = curr->next;
    }
    printf("\n");
    return;
}


int main(){
    struct Node* head = NULL;
    int size;

    printf("Enter size of the List: ");
    scanf("%d",&size);
    printf("--> ");

    for(int i = 0; i < size; ++i){
        int x;
        scanf("%d",&x);
        appendList(&head,x);
    }

    printList(head);

    printf("Copied List: \n");
    Node* copiedList = copyList(head);
    printList(copiedList);

    system("pause");
    return 0;
}