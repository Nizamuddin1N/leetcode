class Solution {
public:
    vector<int> ans;

    int solve(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int left = solve(root->left);
        int right = solve(root->right);

        if(right == -1 || left == -1){
            return -1;
        }
        else if(right == left){
            ans.push_back(left + right + 1);
            return left + right + 1;
        }
        else{
            return -1;
        }
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        ans.clear();
        solve(root);
        sort(ans.begin(), ans.end(), greater<int>());
        if (k-1 < ans.size()) {
            return ans[k-1];
        }
        return -1;
    }
};