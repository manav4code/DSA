#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int node, vector<vector<int>> adjList, vector<int> &vis){

    queue<int>q;
    vis[node] = 1;
    q.push(node);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        cout << x << " ";

        for(auto it : adjList[x]){
            if(vis[it] == 0){
                q.push(it);
                vis[it] = 1;
            }
        }
    }

}

int main(){

    vector<vector<int>>adjList;

    // Building Graph's Adjacency List
    adjList.push_back({-1});
    adjList.push_back({2,3});
    adjList.push_back({1,5,6});
    adjList.push_back({1,4,7});
    adjList.push_back({3,8});
    adjList.push_back({2});
    adjList.push_back({2});
    adjList.push_back({3,8});
    adjList.push_back({7,4});

    // Visited Node Array
    vector<int> vis(9,0);

    bfs(1,adjList,vis);

    return 0;
}