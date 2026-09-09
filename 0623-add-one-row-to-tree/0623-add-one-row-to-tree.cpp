/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth ==1){
            TreeNode* node = new TreeNode(val);
            node->left=root;
            return node;
        }
        queue<TreeNode*>q;
        q.push(root);
        int level=2;
        while(!q.empty()){
            int n = q.size();
            if(level == depth){
                for(int i=0; i<n; i++){
                    TreeNode* node = q.front();
                    q.pop();
                    if(node->left == nullptr){
                        node->left = new TreeNode(val);
                    }
                    else{
                        TreeNode* temp=node->left;
                        node->left = new TreeNode(val);
                        node->left->left=temp;
                    }
                    if(node->right == nullptr){
                        node->right = new TreeNode(val);
                    }
                    else{
                        TreeNode* temp = node->right;
                        node->right = new TreeNode(val);
                        node->right->right = temp;
                    }
                }
                return root;
            }
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            level++;
        }
        return root;
    }
};