#include<stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;


Node* getNode(int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}


Node* insert(Node* head, int data){
    if(!head){
        return getNode(data);
    }

    Node* curr = head;
    while(curr->next){
        curr = curr->next;
    }

    curr->next = getNode(data);
    return head;
}

void printList(Node* head){
    Node* curr = head;

    while(curr){
        printf("%d\t",curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void selectionSort(Node* head){
    Node* smallest = head;
    Node* curr = head->next;

    while (curr)
    {
        Node* temp = curr;
        while(temp){
            if(smallest->data > temp->data){
                int t = temp->data;
                temp->data = smallest->data;
                smallest->data = t;
            }
            temp = temp->next;
        }
        curr = curr->next;
        smallest = smallest->next;
    }   
}


int main(){

    int arr[] = {1,5,4,6,7,2};
    int size = sizeof(arr)/sizeof(int);

    Node* head = NULL;

    for(int i = 0; i < size; i++){
        head = insert(head,arr[i]);
    }

    printList(head);

    selectionSort(head);
    printList(head);
}
