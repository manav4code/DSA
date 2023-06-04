#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool detect(int node, vector<int> adj[], int vis[]){

    queue<pair<int,int>> q;
    vis[node] = 1;
    q.push({node,-1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it : adj[node]){
            if(!vis[it]){
                q.push({it,node});
                vis[it] = 1;
            }
            else if(parent != it){
                return true;
            }
        }
    }
    return false;
}

bool checkCycle(vector<int> adj[], int V){
    int vis[V] = {0};

    for(int i = 0; i < V; i++){
        if(!vis[i]){
            if(detect(i, adj, vis))return true;
        }
    }
    return false;
}

int main(){
    vector<int> adj[7];

    adj[0] = {1,2};
    adj[1] = {0,3};
    adj[2] = {0,5};
    adj[3] = {1,4,6};
    adj[4] = {3};
    adj[5] = {2,5};
    adj[6] = {3,5};

    if(checkCycle(adj, 7)){
        cout << "Cycle Exists." << endl;
    }
    else cout << "Cycle does not exist";

    return 0;
}