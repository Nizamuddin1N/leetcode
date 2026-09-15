class Solution {
public:
    // vector<int> cost;
    // int m;
    // int ans = 0;

    // TreeNode* makebinarytree(int i) {
    //     if (i > m)
    //         return nullptr;

    //     TreeNode* root = new TreeNode(i);

    //     root->left = makebinarytree(2 * i);
    //     root->right = makebinarytree(2 * i + 1);

    //     return root;
    // }

    // int store(TreeNode* root) {
    //     if (root == nullptr)
    //         return 0;

    //     int left = store(root->left);
    //     int right = store(root->right);

    //     ans += abs(left - right);

    //     return cost[root->val - 1] + max(left, right);
    // }
    int ans=0;
    int solution(int i, vector<int>&cost){
        if(i>cost.size()){
            return 0;
        }
        int left = solution(2*i, cost);
        int right = solution(2*i+1, cost);
        ans +=abs(left-right);
        return cost[i-1]+max(left, right);
    }
    int minIncrements(int n, vector<int>& cost) {
        // this->cost = cost;
        // m = n;
        // ans = 0;

        // TreeNode* root = makebinarytree(1);

        // store(root);

        // return ans;
        solution(1, cost);
        return ans;
    }
};