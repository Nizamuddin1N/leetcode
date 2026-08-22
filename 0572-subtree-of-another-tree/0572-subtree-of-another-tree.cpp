class Solution {
public:

    // bool checkSubtree(TreeNode* root, TreeNode* subRoot) {
    //     if(root == nullptr && subRoot == nullptr)
    //         return true;
    //     if(root == nullptr || subRoot == nullptr)
    //         return false;
    //     if(root->val != subRoot->val)
    //         return false;
    //     queue<pair<TreeNode*, TreeNode*>> q;
    //     q.push({root, subRoot});

    //     while(!q.empty()) {
    //         auto [node1, node2] = q.front();
    //         q.pop();
    //         if(node1->val != node2->val)
    //             return false;
    //         if(node1->left == nullptr && node2->left != nullptr)
    //             return false;
    //         if(node1->left != nullptr && node2->left == nullptr)
    //             return false;
    //         if(node1->right == nullptr && node2->right != nullptr)
    //             return false;
    //         if(node1->right != nullptr && node2->right == nullptr)
    //             return false;
    //         if(node1->left && node2->left)
    //             q.push({node1->left, node2->left});
    //         if(node1->right && node2->right)
    //             q.push({node1->right, node2->right});
    //     }

    //     return true;
    // }
    bool checkNodesIsSubtree(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL){
            return true;
        }
        if(root == NULL || subRoot == NULL){
            return false;
        }
        if(root->val !=  subRoot->val){
            return false;
        }
        return checkNodesIsSubtree(root->left, subRoot->left) && checkNodesIsSubtree(root->right, subRoot->right);
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // if(subRoot == nullptr)
        //     return true;
        // if(root == nullptr)
        //     return false;
        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty()) {
        //     TreeNode* node = q.front();
        //     q.pop();

        //     if(node->val == subRoot->val) {

        //         if(checkSubtree(node, subRoot))
        //             return true;
        //     }

        //     if(node->left)
        //         q.push(node->left);

        //     if(node->right)
        //         q.push(node->right);
        // }

        // return false;
        if(subRoot == NULL){
            return true;
        }
        if(root == NULL){
            return false;
        }
        if(checkNodesIsSubtree(root, subRoot)){
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};