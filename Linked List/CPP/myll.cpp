// Building a Linked List having a ptr pointing to tail Node.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
    private:
        Node* tail;

    public:
        int data;
        Node* next = NULL;

        Node(){
            data = 0;
            next = NULL;
        }
        Node(int x){
            data = x;
            next = NULL;
        } 

        Node* getTail(){
            return tail;
        }

        void updateTail(Node** temp){
            tail = (*temp);
        }
};

void appendNode(Node **head,int x){
    
    
    if((*head)==NULL){
        return;
    }
    else{
        Node *temp = new Node(x);
        (*head)->getTail()->next = temp;
        (*head)->updateTail(&temp);
    }
}

void enterList(Node** head){

    vector<int>v = {1,2,3,4,5};

    for(auto i:v){
        appendNode(head,i);
    }
    
}

void printList(Node* head){
    if(head == NULL){
        cout << "List is empty!";
        return;
    }
    else{
        while(head != NULL){
            cout << head->data << " ";
            head=head->next;
        }

        cout << "END";
    }
}

int main(){
    Node *head = new Node();
    head->updateTail(&head);

    enterList(&head);
    printList(head);

    exit(0);
}