class Solution {
public:
    vector<int>parent;
    int find(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = find(parent[node]);
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

    bool check(int x, int n, vector<vector<int>>& edges, int k){
        iota(parent.begin(), parent.end(), 0);
        int cnt = 0;
        for(auto &e : edges){
            if(e[3] == 1){
                if(e[2] < x) return false;
                if(!unite(e[0], e[1])) return false;
                cnt++;
            }
        }
        for(auto &e : edges){
            if(e[3] == 0 && e[2] >= x){
                if(unite(e[0], e[1])) cnt++;
            }
        }
        int used = 0;
        for(auto &e : edges){
            if(e[3] == 0 && e[2] < x && 2 * e[2] >= x){
                if(unite(e[0], e[1])){
                    cnt++;
                    used++;
                    if(used > k) return false;
                }
            }
        }
        return cnt == n - 1;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        parent.resize(n);
        int lo = 1, hi = 200000, ans = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid, n, edges, k)){
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return ans;
        // int ans = INT_MAX;
        // parent.resize(n);
        // iota(parent.begin(), parent.end(), 0);
        // int complEdge = 0;
        // for(auto &edge:edges){
        //     if(edge[3] == 1){
        //         complEdge++;
        //         if(!unite(edge[0], edge[1])){
        //             return -1;
        //         }
        //         ans = min(ans, edge[2]);
        //     }
        // }
        // sort(edges.begin(), edges.end(), [](vector<int>&a, vector<int>&b){
        //     return a[2]>b[2];
        // });
        // int count=0;
        // for(auto &edge:edges){
        //     if(edge[3] == 0){
        //         if(unite(edge[0], edge[1])){
        //             count++;
        //             if(k>0){
        //                 ans = min(ans, 2*edge[2]);
        //                 k--;
        //             }
        //             else{
        //                 ans = min(ans, edge[2]);
        //             }
        //         }
        //     }
        // }
        // if(count + complEdge != n-1){
        //     return -1;
        // }
        // return ans;
        // vector<int>store;
        // int result;
        // for(auto &x:edges){
        //     if(x[3]==0){
        //         store.push_back(x[2]);
        //     }
        // }
        // if(k !=0 && store.size()==0){
        //     return -1;
        // }
        // sort(store.begin(), store.end(), [](int &a, int &b){
        //     return a>b;
        // });
        // for(auto &x:store){
        //     k--;
        //     result+=x;
        //     if(k==0){
        //         return result;
        //     }
        // }
        // return -1;

    }
};