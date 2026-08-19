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
        // vector<int>ans(store.size(), 0);
        // for(int i=0;i<store.size()-1; i++){
        //     for(int j=i+1; j<store.size(); j++){
        //         if(store[i]<store[j]){
        //             ans[i] = store[j];
        //             break;
        //         }
        //     }
        // }
        stack<int>st;
        for(int i=store.size()-1; i>=0; i--){
            int value = store[i];
            while(!st.empty() && st.top()<=store[i]){
                st.pop();
            }
            if(st.empty()){
                store[i]=0;
            }
            else{
                store[i] = st.top();
            }
            st.push(value);
        }
        return store;
    }
};