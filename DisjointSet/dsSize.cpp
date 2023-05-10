#include<bits\stdc++.h>

using namespace std;

class disjointSet{
    private:
        vector<int> size, parent;
    public:
        disjointSet(int n){
            size.resize(n+1,0);
            parent.resize(n+1);

            for(int i = 1; i <= n; i++){
                parent[i] = i;
            }
        }

        int findUPar(int node){
            if(node == parent[node]){
                return node;
            }
            
            return parent[node] = findUPar(parent[node]);
        }

        void unionBySize(int u, int v){
            int pu = findUPar(u);
            int pv = findUPar(v);

            if(pu == pv) return;

            if(size[pu] > size[pv]){
                parent[pv] = pu;
                size[pu] += size[pv];
            }
            else if(size[pv] > size[pu]){
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            else{
                parent[pv] = pu;
                size[pu] += size[pv];
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
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    ds.check(6,7);
    ds.check(3,7);
    ds.getProvince();
    ds.unionBySize(3,7);
    ds.getProvince();

    return 0;
}