class Solution {
public:
    // unordered_map<TreeNode*, TreeNode*> parents;
    // unordered_map<TreeNode*, bool> visited;

    // void storeParent(TreeNode* root, TreeNode* parent){
    //     if(root == nullptr){
    //         return;
    //     }

    //     parents[root] = parent;

    //     storeParent(root->left, root);
    //     storeParent(root->right, root);
    // }

    // TreeNode* s = nullptr;
    // TreeNode* t = nullptr;

    // int start, dest;

    // void findingAddress(TreeNode* root){
    //     if(root == nullptr){
    //         return;
    //     }

    //     if(root->val == start){
    //         s = root;
    //     }

    //     if(root->val == dest){
    //         t = root;
    //     }

    //     findingAddress(root->left);
    //     findingAddress(root->right);
    // }

    // string ans;

    // void solution(TreeNode* s, string str){
    //     if(s == nullptr || visited[s]){
    //         return;
    //     }

    //     visited[s] = true;

    //     if(s == t){
    //         ans = str;
    //         return;
    //     }

    //     solution(s->left, str + "L");
    //     solution(s->right, str + "R");
    //     solution(parents[s], str + "U");
    // }
    TreeNode* findLCA(TreeNode* root, int startValue, int destValue){
        if(root == nullptr || root->val == startValue || root->val == destValue){
            return root;
        }
        TreeNode* left = findLCA(root->left, startValue, destValue);
        TreeNode* right = findLCA(root->right, startValue, destValue);
        if(left != nullptr && right != nullptr){
            return root;
        }
        return left != nullptr ? left : right;
    }
    bool findPath(TreeNode* root, int value, string& path){
        if(root == nullptr){
            return false;
        }
        if(root->val == value){
            return true;
        }
        path.push_back('L');
        if(findPath(root->left, value, path)){
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if(findPath(root->right, value, path)){
            return true;
        }
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue){
        // start = startValue;
        // dest = destValue;

        // storeParent(root, nullptr);
        // findingAddress(root);
        // solution(s, "");

        // return ans;
        TreeNode* lca = findLCA(root, startValue, destValue);
        string startPath;
        string destPath;
        findPath(lca, startValue, startPath);
        findPath(lca, destValue, destPath);
        for(char& c:startPath){
            c = 'U';
        }
        return startPath + destPath;
    }
};