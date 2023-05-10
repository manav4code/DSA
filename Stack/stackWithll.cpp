#include<bits/stdc++.h>

using namespace std;

class Node{
    private:
        int data;
        Node* next;
    public:
        Node(){}
        Node(int x){
            data = x;
            next = NULL;
        }

        void inserAhead(Node **head,int x){
            Node *temp = new Node(x);
            temp->next = (*head);
            (*head) = temp;
            return;
        }

        int removeFront(Node **head){
            int retData = (*head)->data;
            Node* temp = (*head);
            (*head) = (*head)->next;
            delete temp;
            return retData;
        }
};

class Stack:private Node{
    private:
        int minNum;
        int topNum;
        Node* topPtr;
    public:
        Stack(){
            minNum = INT_MIN;
            topNum = 0;
            topPtr == NULL;
        }

        void push(int x){
            topNum = x;
            minNum = min(x,minNum);
            inserAhead(&topPtr,x);
        }

        int pop(){
            int retData = removeFront(&topPtr);
            return retData;
        }

        int minimun(){
            return minNum;
        }
};