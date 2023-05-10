#include<bits/stdc++.h>

using namespace std;

queue<int> queueRev(queue<int> q){
    stack<int>s;
    queue<int>res;

    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        res.push(s.top());
        s.pop();
    }

    return res;
}

void printQueue(queue<int>q){
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return;
    
}

int main(){
    queue <int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q = queueRev(q);
    printQueue(q);
    return 0;
}