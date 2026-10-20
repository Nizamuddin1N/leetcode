
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;
        for (auto& p : pairs) {
            int u = p[0], v = p[1];
            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }
        int start = pairs[0][0];
        for (auto& [node, degree] : outdegree) {
            if (degree - indegree[node] == 1) {
                start = node;
                break;
            }
        }
        vector<int> st;
        vector<int> path;
        st.push_back(start);

        while (!st.empty()) {
            int u = st.back();

            if (!adj[u].empty()) {
                int v = adj[u].back();
                adj[u].pop_back();
                st.push_back(v);
            } else {
                path.push_back(u);
                st.pop_back();
            }
        }
        reverse(path.begin(), path.end());
        vector<vector<int>> ans;
        for (int i = 1; i < path.size(); i++) {
            ans.push_back({path[i - 1], path[i]});
        }
        return ans;
    }
};
