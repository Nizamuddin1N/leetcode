class DSU{
    public:
    vector<int>parent;
    DSU(int n){
        parent.resize(n+1);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv){
            return false;
        }
        parent[pv] = pu;
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n);
        DSU bob(n);
        int used = 0;
        for(auto &edge:edges){
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(type == 3){
                bool a = alice.unite(u, v);
                bool b = bob.unite(u, v);
                if(a || b){
                    used++;
                }
            }
        }
        for(auto &edge:edges){
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(type == 1){
                if(alice.unite(u, v)){
                    used++;
                }
            }
        }
        for(auto &edge:edges){
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(type == 2){
                if(bob.unite(u, v)){
                    used++;
                }
            }
        }
        int aliceRoot = alice.find(1);
        int bobRoot = bob.find(1);

        for(int i=2; i<=n; i++){
            if (alice.find(i) != aliceRoot || bob.find(i) != bobRoot) {
                return -1;
            }
        }
        return edges.size() - used;
    }
};