/**
 * Definition for singly-linked list.
 * 
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = new ListNode(0);
        ListNode *head = ret;
        
        int ifCarry = 0;
        while (l1 || l2) {
        	/* Add val and carry */
            int tmpSum = ret->val + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            ret->val = tmpSum % 10;
            ifCarry = tmpSum / 10;
            
            /* if new a next node for ret */
            l1 = (l1 ? l1->next : NULL);
            l2 = (l2 ? l2->next : NULL);
            ret->next = (l1 || l2 || ifCarry) ? new ListNode(ifCarry) : NULL;
            ret = ret->next ? ret->next : ret;
        }
        
        return head;
    }
};