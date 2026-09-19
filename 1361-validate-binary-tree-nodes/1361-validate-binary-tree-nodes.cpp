class Solution {
public:
    int count=0;
    bool solve(int root, vector<int>& leftChild, vector<int>& rightChild, vector<int>&visited){
        if (root == -1) return true;

        if (visited[root]) return false;
        visited[root] = 1;
        count++;

        bool left = solve(leftChild[root], leftChild, rightChild, visited);
        bool right = solve(rightChild[root], leftChild, rightChild, visited);

        return left && right;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n, 0);

        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                parent[leftChild[i]]++;
                if (parent[leftChild[i]] > 1) return false;
            }

            if (rightChild[i] != -1) {
                parent[rightChild[i]]++;
                if (parent[rightChild[i]] > 1) return false;
            }
        }
        int root = -1;

        for (int i = 0; i < n; i++) {
            if (parent[i] == 0) {
                if (root != -1) return false;
                root = i;
            }
        }

        vector<int> visited(n, 0);
        if (!solve(root, leftChild, rightChild, visited))
            return false;

        return count == n;
    }
};