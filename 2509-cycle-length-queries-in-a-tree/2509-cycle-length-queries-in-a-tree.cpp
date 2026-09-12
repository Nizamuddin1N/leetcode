class Solution {
public:
    // unordered_map<TreeNode*, TreeNode*> parents;
    // unordered_map<int, TreeNode*> nodes;
    // vector<bool> visited;

    // void parentstore(TreeNode* root, TreeNode* parentnode) {
    //     if(root == nullptr) {
    //         return;
    //     }

    //     parents[root] = parentnode;

    //     parentstore(root->left, root);
    //     parentstore(root->right, root);
    // }

    // void makeBinaryTree(TreeNode*& root, int n, int value) {
    //     if(n == 0) {
    //         return;
    //     }

    //     root = new TreeNode(value);
    //     nodes[value] = root;

    //     makeBinaryTree(root->left, n - 1, 2 * value);
    //     makeBinaryTree(root->right, n - 1, 2 * value + 1);
    // }

    // int bfs(int a, int b) {
    //     visited.assign(nodes.size() + 1, false);

    //     queue<TreeNode*> q;
    //     q.push(nodes[a]);
    //     visited[a] = true;

    //     int k = 1;

    //     while(!q.empty()) {
    //         int n = q.size();

    //         for(int i = 0; i < n; i++) {
    //             TreeNode* temp = q.front();
    //             q.pop();

    //             if(temp->val == b) {
    //                 return k;
    //             }

    //             // left
    //             if(temp->left && !visited[temp->left->val]) {
    //                 q.push(temp->left);
    //                 visited[temp->left->val] = true;
    //             }

    //             // right
    //             if(temp->right && !visited[temp->right->val]) {
    //                 q.push(temp->right);
    //                 visited[temp->right->val] = true;
    //             }

    //             // parent
    //             if(parents[temp] != nullptr &&
    //                !visited[parents[temp]->val]) {
    //                 q.push(parents[temp]);
    //                 visited[parents[temp]->val] = true;
    //             }
    //         }

    //         k++;
    //     }

    //     return -1;
    // }

    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        // TreeNode* root = nullptr;

        // makeBinaryTree(root, n, 1);
        // parentstore(root, nullptr);

        // vector<int> ans;

        // for(auto &q : queries) {
        //     ans.push_back(bfs(q[0], q[1]));
        // }

        // return ans;
        vector<int>ans;
        for(auto &q : queries){
            int a = q[0];
            int b = q[1];
            int length = 1;
            while(a != b){
                if(a>b){
                    a /=2;
                }
                else{
                    b /= 2;
                }
                length++;
            }
            ans.push_back(length);
        }
        return ans;
    }
};