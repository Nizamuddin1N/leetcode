/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serializedata = "";
    void treeTostring(TreeNode* root){
        if(root == nullptr){
            return;
        }
        serializedata += to_string(root->val) + "#";
        treeTostring(root->left);
        treeTostring(root->right);
    }
    string serialize(TreeNode* root) {
        treeTostring(root);
        return serializedata;
    }

    // Decodes your encoded data to tree.
    TreeNode* stringTotree(string &data, int min, int max, int &i){
        if(i>=data.size()){
            return nullptr;
        }
        string val = "";
        int start = i;
        while(data[i] != '#'){
            val.push_back(data[i]);
            i++;
        }
        i++;
        int value = stoi(val);
        if(value < min || value > max){
            i=start;
            return nullptr;
        }
        TreeNode* root = new TreeNode(value);
        root->left = stringTotree(data, min, root->val, i);
        root->right = stringTotree(data, root->val, max, i);
        return root;
    }
    TreeNode* deserialize(string data) {
        if(data == ""){
            return nullptr;
        }
        int min = INT_MIN;
        int max = INT_MAX;
        int i=0;
        return stringTotree(data, min, max, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;