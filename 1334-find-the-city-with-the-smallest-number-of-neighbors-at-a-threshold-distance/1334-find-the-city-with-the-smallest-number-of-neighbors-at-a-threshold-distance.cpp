class Solution {
public:
    void dfs(int node, unordered_map<int, vector<pair<int, int>>>& mp,int distance, int distanceThreshold, vector<int>& dist) {

        if (distance > distanceThreshold) {
            return;
        }

        if (distance >= dist[node]) {
            return;
        }

        dist[node] = distance;

        for (auto& x : mp[node]) {
            int next = x.first;
            int weight = x.second;

            dfs(next, mp, distance + weight, distanceThreshold, dist);
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<pair<int, int>>> mp;

        for (auto& edge : edges) {
            mp[edge[0]].push_back({edge[1], edge[2]});
            mp[edge[1]].push_back({edge[0], edge[2]});
        }

        int result = -1;
        int minNodes = INT_MAX;

        for (int i = 0; i < n; i++) {
            vector<int> dist(n, INT_MAX);

            dfs(i, mp, 0, distanceThreshold, dist);

            int count = 0;

            for (int j = 0; j < n; j++) {
                if (j != i && dist[j] <= distanceThreshold) {
                    count++;
                }
            }

            if (count <= minNodes) {
                minNodes = count;
                result = i;
            }
        }

        return result;
    }
};