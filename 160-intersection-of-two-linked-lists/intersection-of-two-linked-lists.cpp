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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while (t1 != t2) {
            if (t1 == nullptr) {
                t1 = headB;
            } else {
                t1 = t1->next;
            }

            if (t2 == nullptr) {
                t2 = headA;
            } else {
                t2 = t2->next;
            }
        }

        return t1;
    }
};