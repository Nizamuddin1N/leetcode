class Solution {
public:
    int findParent(vector<int>& parent, int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = findParent(parent, parent[x]);
    }
    bool unite(vector<int>& parent, vector<int>& rank, int u, int v){
        u = findParent(parent, u);
        v = findParent(parent, v);

        if(u == v){
            return false;
        }
        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[u] > rank[v]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
        return true;
    }

    int kruskal(int n, vector<vector<int>>&edges, int skip, int force){
        vector<int>parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);
        int weight = 0;
        int count = 0;
        //force an edge to be included first
        if(force != -1){
            int u = edges[force][0];
            int v = edges[force][1];
            int w = edges[force][2];

            unite(parent, rank, u, v);
            weight += w;
            count++;
        }
        for(int i=0; i<edges.size(); i++){
            if(i == skip || i == force){
                continue;
            }
            int u  = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if(unite(parent, rank, u, v)){
                weight += w;
                count++;
            }
        }
        if(count != n-1){
            return INT_MAX;
        }
        return weight;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>>indexedEdges;
        for(int i=0; i<m; i++){
            indexedEdges.push_back({edges[i][0], edges[i][1], edges[i][2], i});
        }
        sort(indexedEdges.begin(), indexedEdges.end(), [](const vector<int>&a, const vector<int>&b){
            return a[2]<b[2];
        });
        vector<vector<int>>sortedEdges;
        for(auto& e: indexedEdges){
            sortedEdges.push_back({e[0], e[1], e[2]});
        }
        int base = kruskal(n, sortedEdges, -1, -1);
        vector<int>critical, pseudo;
        for(int i=0; i<m; i++){
            if(kruskal(n, sortedEdges, i, -1) > base){
                critical.push_back(indexedEdges[i][3]);
            }
            else if(kruskal(n, sortedEdges, -1, i) == base){
                pseudo.push_back(indexedEdges[i][3]);
            }
        }
        return {critical, pseudo};
    }
};