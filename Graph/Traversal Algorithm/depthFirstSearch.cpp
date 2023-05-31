#include <iostream>
#include<vector>

using namespace std;

void dfs(int node, vector<vector<int>> adjList, vector<int> &vis){
    
    vis[node] = 1;

    std::cout << node << " ";

    for(auto it : adjList[node]){
        if(vis[it] == 0){
            dfs(it, adjList,vis);
        }
    }

    return;
}

int main(){
    vector<vector<int>>adjList;

    adjList.push_back({-1});
    adjList.push_back({2,3});
    adjList.push_back({1,5,6});
    adjList.push_back({1,4,7});
    adjList.push_back({3,8});
    adjList.push_back({2});
    adjList.push_back({2});
    adjList.push_back({3,8});
    adjList.push_back({7,4});

    vector<int> vis(9,0);

    dfs(1,adjList,vis);
    

    return 0;

}