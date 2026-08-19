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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int sizeofll = 0;
        ListNode* temp = head;
        while(temp != NULL){
            sizeofll++;
            temp = temp->next;
        }
        int base = sizeofll/k;
        int extra = sizeofll % k;
        temp = head;
        for(int i=0; i<k; i++){
            ans.push_back(temp);
            int size = base;
            if(extra>0){
                extra--;
                size++;
            }
            if(size==0){
                continue;
            }
            for(int j=1; j<size; j++){
                temp=temp->next;
            }
            ListNode* nextpart = temp->next;
            temp->next = NULL;
            temp = nextpart;
        }
        return ans;
    }
};