/**
反转一个单链表。
示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *curr = NULL;
		ListNode *idx = head;
		ListNode *newHead = NULL;

		while (idx != NULL) {
			/* 保存当前节点的地址 */
			curr = idx;
			/* idx指针指向下一节点 */
			idx = idx->next;
			/* 当前节点指向上一节点 */
			curr->next = newHead;
			newHead = curr;
		}

		return newHead;
	}
};

/* 递归
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL)
        return NULL;
    if (head -> next == NULL)
        return head;
    struct ListNode *newHead = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return newHead;
}
*/

int main(int argc, char *argv[])
{
	
	return 0;
}