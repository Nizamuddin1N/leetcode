class Solution {
public:
        vector<int>parent;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        int edge=0;
        int redundantConnections = 0;
        for(auto& connection: connections){
            if(unite(connection[0], connection[1])){
                edge++;
            }
            else{
                redundantConnections++;
            }
        }
        int needEdge = n-1-edge;
        if(needEdge <= redundantConnections){
            return needEdge;
        }
        else{
            return -1;
        }
        return -1;
    }
};