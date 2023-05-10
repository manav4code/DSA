#include<bits\stdc++.h>

using namespace std;

class disjointSet{
    private:
        vector<int> size,parent;
    public:

        disjointSet(int n){
            size.resize(n,0);
            parent.resize(n);

            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
            }
        }

        int findUPar(int node){
            if(node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionBySize(int u,int v){
            int pu = findUPar(u);
            int pv = findUPar(v);

            if(pu == pv) return;

            if(size[pv] > size[pu]){
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            else{
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
};

int mst(int V, vector<vector<int>> adj[]){
    
    vector<pair<int,pair<int,int>>> edges;

    for (int i = 0; i < V; i++)
    {
        for(auto it : adj[i]){
            int adjNode = it[0];
            int wt = it[1];
            int node = i;

            edges.push_back({wt,{node, adjNode}});
        }
    }

    int mstWt = 0;
    disjointSet ds(V);

    sort(edges.begin(), edges.end());

    for(auto i : edges){
        int wt = i.first;
        int u = i.second.first;
        int v = i.second.second;

        if(ds.findUPar(u) != ds.findUPar(v)){
            mstWt += wt;
            ds.unionBySize(u, v);
        }
    }

    return mstWt;
}