class Solution {
public:

    unordered_map<int, pair<int, int>> mp;
    long long maxScore = 0;
    int count = 0;
    int total;

    int dfs(int node) {

        if (node == -1) {
            return 0;
        }

        int left = dfs(mp[node].first);
        int right = dfs(mp[node].second);

        int remaining = total - left - right - 1;

        long long leftPart = (left == 0 ? 1 : left);
        long long rightPart = (right == 0 ? 1 : right);
        long long remainingPart = (remaining == 0 ? 1 : remaining);

        long long score = leftPart * rightPart * remainingPart;

        if (score > maxScore) {
            maxScore = score;
            count = 1;
        }
        else if (score == maxScore) {
            count++;
        }

        return left + right + 1;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        total = parents.size();
        for (int i = 0; i < total; i++) {
            mp[i] = {-1, -1};
        }

        int root = -1;

        for (int i = 1; i < total; i++) {

            int parent = parents[i];

            if (mp[parent].first == -1) {
                mp[parent].first = i;
            }
            else {
                mp[parent].second = i;
            }
        }
        root = 0;
        dfs(root);
        return count;
    }
};