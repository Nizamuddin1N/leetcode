/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // bool checkpath(LitNode* head, TreeNode* root){
    //     if(head->val == root->val && head->next ==  nullptr){
    //         return true;
    //     }
    //     if(root->val != head->val){
    //         return false;
    //     }
    //     ListNode* temp = head;
    //     stack<TreeNode*>st;
    //     st.push(root);
    //     temp = temp->next;
    //     while(!st.empty()){
    //         auto node = st.top();
    //         st.pop();
    //         if(node->left->val != temp->val && node->right->val != temp->val){
    //             return false;
    //         }
    //         if((node->right->val == temp->val || node->left->val == temp->val) && temp->next == nullptr){
    //             true;
    //         }
    //         //some code how to handle when left and right of root are equal and i dont know which path is right 
    //         // becuase here we find path not exploring 
    //     }
    // }
    bool check(ListNode* head, TreeNode* root){
        if(head==nullptr){
            return true;
        }
        if(root == nullptr){
            return false;
        }
        if(root->val != head->val){
            return false;
        }
        return check(head->next, root->left) || check(head->next, root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL){
            return false; 
        }
        if(head == NULL){
            return true;
        }
        if(check(head, root)){
            return true;
        }
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};