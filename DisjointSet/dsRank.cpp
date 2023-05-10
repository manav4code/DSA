#include <bits/stdc++.h>

using namespace std;

class disjointSet{
    private:
        vector<int> rank, parent;
    public:
        disjointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);

            for(int i = 1; i <= n; i++){
                parent[i] = i;
            }
        }

        int findUPar(int node){
            if(parent[node] == node) return node;
            return parent[node] = findUPar(parent[node]);
        }

        void updateChild(int p){
            for (int i = 1; i < parent.size(); i++)
            {
                if (parent[i] == p){
                    parent[i] = parent[p];
                }
            }
        }

        void unionByRank(int u, int v){
            int pu = findUPar(u);
            int pv = findUPar(v);

            if(pu == pv) return;    // Belongs to same component

            if(rank[pu] > rank[pv]){
                parent[pv] = pu;
                updateChild(pv);
            }
            else if(rank[pv] > rank[pu]){
                parent[pu] = pv;
                updateChild(pu);
            }
            else{   // if same rank
                parent[pv] = pu;
                updateChild(pv);
                rank[pu]++;
            }
        }

        void check(int u,int v){
            int pu = findUPar(u);
            int pv = findUPar(v);
            if(pu == pv){
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }

        void getProvince(){
            set<int>s;
            for(int i = 1; i < parent.size(); i++){
                s.insert(parent[i]);
            }
            cout << s.size() << endl;
            
            for(auto it : s){
                cout << it << " ";
            }
            cout << endl;
        }
};

int main(){

    disjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    ds.check(6,7);
    ds.check(3,7);
    ds.getProvince();
    ds.unionByRank(3,7);
    ds.getProvince();

    return 0;
}