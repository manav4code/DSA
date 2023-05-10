#include<bits/stdc++.h>

using namespace std;

class Stack{
    private:
        queue<int>q1;
        queue<int>q2;
        int head;
    public:
        Stack(){
            head = 0;
            q1 = {};
            q2 = {};
        }

        void push(int data){
            q1.push(data);
            head = data;
            return;
        }

        int top(){
            return head;
        }

        int pop(){
            int retData;
            while(!q1.empty()){
                q2.push(q1.front());
                retData = q1.front();
                q1.pop();
            }
            
            while(!q2.empty()){
                if(retData != q2.front()){
                    q1.push(q2.front());
                    head = q2.front();
                }
                q2.pop();
            }

            return retData;
        }
};


int main(){
    Stack s1;

    s1.push(7);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    int x = s1.pop();
    int y = s1.pop();
    cout << "Pop : " << s1.pop() << "\n";
    cout <<"Top of the stack : "<< s1.top();
    
    return 0;
}