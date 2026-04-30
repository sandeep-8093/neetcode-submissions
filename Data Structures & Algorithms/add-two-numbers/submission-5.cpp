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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }


    ListNode* addLinkedList( ListNode* l1, ListNode* l2){
        ListNode* ans = NULL;
        ListNode* tail = NULL;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int val1=0, val2=0;
            if(l1!=NULL){
                 val1 = l1->val;
            }
            if(l2!=NULL){
                 val2 = l2->val;
            }
            int sum = val1+ val2 + carry;
            carry = sum/10;
            int digit = sum%10;
            ListNode* newNode = new ListNode(digit);
            if (ans == NULL) {
                ans = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }            if(l1 != NULL)
                l1 = l1 -> next;
            
            if(l2 != NULL)
                l2 = l2 -> next;
            
        }
        return ans;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       if(l1==NULL){
        return l2;
       } if(l2==NULL){
        return l1;

       }
       
       ListNode* ans= addLinkedList(l1,l2);
       return ans;
    }
};
