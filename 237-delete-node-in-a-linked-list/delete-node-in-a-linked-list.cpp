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
    void deleteNode(ListNode* node) {
       int temp = node->next->val;
       ListNode* del = new ListNode(temp);

       node->val= temp;
       node->next=node->next->next;

       delete del;

       

        
    }
};