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
class FindElements {
public:
    TreeNode * root;
    FindElements(TreeNode* root) {
        this->root = root;
        recover(this->root, 0);

    }
    void recover(TreeNode* node, int value){
        if(node== nullptr){
            return;
        }
        node->val= value;
        if(node->left){
            recover(node->left, 2*value+1);
        }
        if(node->right){
            recover(node->right, 2*value+2);
        }
    }
    
    bool find(int target) {
        // if(root=NULL){
        //     return true;
        // }
        // if(root->left){
        //     return root->left->val == 2*root->val+1;
        // }
        // if(root->right){
        //     return root->right->val = 2*root->val;
        // }
        // bool ans1 = find(root->left);
        // bool ans2 = find(root->right);
        // return ans1 && ans1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == target){
                return true;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        return false;
    
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */