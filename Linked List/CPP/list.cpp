#include<iostream>
#include<vector>

using namespace std;

class Node{

    private:
        static int count;
        Node* end;
        Node* front;

    public:

        int data;
        Node* next;
        Node* prev;

        Node(){
            end = NULL;
            front = NULL;    
        }

        Node(int x){
            data = x;
            next = NULL;
            prev = NULL;
            count++;
        }
        
        ~Node(){
            count--;
        }

        void push_front(int x){
            Node *temp = new Node(x);

            if(front == NULL){
                front = temp;
                end = temp;
            }
            else{
                front->prev = temp;
                temp->next = front->next;
                front = temp;
            }
        }

        void push_back(int x){
            Node *temp = new Node(x);
            if(front == NULL && end == NULL){
                front = temp;
                end = temp;
            }
            else{
                temp->prev = end;
                end->next = temp;
                end = temp;
            }
        }

        Node* begin(){
            return front;
        }

        Node* tail(){
            return end;
        }

        static int size(){
            return count;
        }

        void assign(int x,int y){
            Node* curr = front;

            while(curr->data != x){
                curr = curr->next;
            }

            curr->data = y;
            return;
        }

        void insert(int pos,int data){
            if(pos > count){
                cout << "Invalid Position";
                return;
            }

            if(pos == 1){
                push_front(data);
                return;
            }
            if(pos == count){
                Node* temp = new Node(end->data);
                end->next = temp;
                end->data = data;
                end = temp;
                return;
            }

            Node* curr = front;
            while(--pos){
                curr = curr->next;
            }
           

            Node* temp = new Node(data);
            curr->prev->next = temp;
            temp->prev = curr->prev;
            temp->next = curr;
            curr->prev = temp;

            return;
        }

        void insert(int pos, vector<int>v){

        }

        void print(){
            Node* curr = front;

            while (curr != NULL){
                cout << curr->data << " ";
                curr = curr->next;
            }
        }
};

int Node::count = 0;

int main(){
    Node list; 
    list.push_front(5);
    list.push_back(4);
    list.insert(2,2);
    list.insert(2,0);
    Node* iter = list.begin();
    auto it = +iter;
    cout << it->data << endl;
    cout << list.size() << endl;
    list.print();
}