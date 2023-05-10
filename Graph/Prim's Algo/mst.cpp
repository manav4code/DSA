#include<bits\stdc++.h>

using namespace std;

int mstWt(int V, vector<vector<int>> adj[]){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    vector<int> vis(V,0);

    pq.push({0,0});

    int mst = 0;

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int wt = it.first;
        int node = it.second;

        if(vis[node] == 1) continue;

        mst += wt;

        for(auto i : adj[node]){
            int adjNode = i[0];
            int edgeWt = i[1];

            if(vis[adjNode] != 1){
                pq.push({wt,adjNode});
            }
        }
    }
    return mst;
}