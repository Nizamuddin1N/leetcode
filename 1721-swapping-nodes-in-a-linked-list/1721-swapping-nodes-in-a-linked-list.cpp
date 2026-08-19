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
    ListNode* swapNodes(ListNode* head, int k) {
        // int size = 0;
        // ListNode* temp = head;
        // while(temp != NULL){
        //     size++;
        //     temp = temp->next;
        // }
        // int firstNodeval, secondNodeval;
        // int secondIndex = size-k+1;
        // int index=0;
        // temp = head;
        // while(temp!=NULL){
        //     index++;
        //     if(index == k){
        //         firstNodeval = temp->val;
        //     }
        //     if(index == secondIndex){
        //         secondNodeval = temp->val;
        //         temp->val = firstNodeval;
        //     }
        //     temp = temp->next;
        // }
        // index=0;
        // temp = head;
        // while(temp != NULL){
        //     index++;
        //     if(index==k){
        //         temp->val = secondNodeval;
        //     }
        //     temp = temp->next;
        // }
        // return head;
        ListNode *first, *second;
        ListNode* temp = head;
        int index=0;
        while(temp != NULL){
            index++;
            if(index==k){
                first = temp;
                second = head;
            }
            if(index >k){
                second = second->next;
            }
            temp = temp->next;
        }
        swap(first->val, second->val);
        return head;
    }
};