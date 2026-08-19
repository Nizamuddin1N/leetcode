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
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>store;
        ListNode* temp = head;
        while(temp != NULL){
            store.push_back(temp->val);
            temp = temp->next;
        }
        vector<int>ans(store.size(), 0);
        for(int i=0;i<store.size()-1; i++){
            for(int j=i+1; j<store.size(); j++){
                if(store[i]<store[j]){
                    ans[i] = store[j];
                    break;
                }
            }
        }
        return ans;
    }
};