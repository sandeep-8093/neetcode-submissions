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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }

        ListNode* node = head;
        int count1 = 0;
        while (node != NULL && count1 < k) {
            node = node->next;
            count1++;
        }

        // If fewer than k nodes, return head without reversing
        if (count1 < k) return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        int count =0;
        while(curr!=NULL && count<k ){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(next != NULL){
            head->next = reverseKGroup(next,k);
        }
        return prev;
    }
};
