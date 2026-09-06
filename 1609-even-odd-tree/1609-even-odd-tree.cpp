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
    pair<bool, bool> checkArray(vector<int>& arr){
        bool strictlydecreasing = true;
        bool strictlyincreasing = true;
        if(arr[0]%2 == 0){
            strictlyincreasing = false;
        }
        else{
            strictlydecreasing = false;
        }
        for(int i=1; i<arr.size(); i++){
            if(arr[i-1]>=arr[i] || arr[i]%2 == 0){
                strictlyincreasing = false;
            }
            if(arr[i-1]<=arr[i] || arr[i]%2 != 0){
                strictlydecreasing = false;
            }
        }
        return {strictlydecreasing, strictlyincreasing};
    }
    bool isEvenOddTree(TreeNode* root) {
        int level=0;
        if(root == nullptr){
            return true;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>arr;
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                arr.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            pair<bool, bool>ans = checkArray(arr);
            if((level & 1)==0){
                if(ans.second == false){
                    return false;
                }
            }
            else{
                if(ans.first == false){
                    return false;
                }
            }
            level++;
        }
        return true;
    }
};