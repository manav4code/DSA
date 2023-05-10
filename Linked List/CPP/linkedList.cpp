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

void enterList(Node** head,vector<int>v){

    for(auto it = v.begin(); it != v.end(); it++){
        if(it == v.begin()){
            (*head) = new Node(*it);
            (*head)->updateTail(head);
        }
        else{
            appendNode(head,*it);
        }
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

        cout << "END" << endl;
    }
}

Node* reverseList(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    return head;
}

Node* addTwoLists(Node* first, Node* second){
    Node* l1 = reverseList(first);
    Node* l2 = reverseList(second);
    Node* res = NULL;
    int carry = 0;

        int digitSum = 0;
        int base = 0;
        while(l1 && l2){
            digitSum = l1->data + l2->data;
            if(digitSum + carry >= 10){
                base = digitSum + carry - 10;
                carry = 1;
            }
            else{
                base = digitSum + carry;
                carry = 0;
            }
            Node* temp = new Node(base);
            temp->next = res;
            res = temp;

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            digitSum = l1->data;
            if(digitSum + carry >= 10){
                carry = 1;
                base = digitSum + carry - 10;
            }
            else{
                carry = 0;
                base = digitSum;
            }
            Node* temp = new Node(base);
            temp->next = res;
            res = temp;

            l1 = l1->next;  
        }

        while (l2)
        {
            digitSum = l2->data;
            if(digitSum + carry >= 10){
                carry = 1;
                base = digitSum + carry - 10;
            }
            else{
                carry = 0;
                base = digitSum;
            }
            Node* temp = new Node(base);
            temp->next = res;
            res = temp;

            l2 = l2->next;
        }

        return res;
}

Node* reorderList(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = reverseList(slow->next);
        slow->next = NULL;
        printList(fast);

        Node* next1 = NULL;
        Node* next2 = NULL;
        slow = head;
        while(slow && fast){
            next1 = slow->next;
            next2 = fast->next;

            slow->next = fast;
            fast->next = next1;

            slow = next1;
            fast = next2;
        }

        return head;
    }

int main(){
    Node *l1 = NULL;

    enterList(&l1,{1,2,3,4,5});
    printList(l1);

    Node* result = reorderList(l1);
    printList(result);

    exit(0);
}