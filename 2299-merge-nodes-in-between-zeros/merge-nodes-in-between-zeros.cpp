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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* modify = head->next;
        ListNode* nextSum = modify;
        

        while(nextSum){
            int sum = 0;
            //sum until next 0
            while(nextSum->val!=0){
                sum += nextSum->val;
                nextSum = nextSum->next;
            }

            //Assign sum to current node 
            modify->val = sum;
            //moving after the next 0
            nextSum = nextSum->next;
            //move modify to where nextsum is
            modify->next = nextSum;
            modify = modify->next;

        }

        return head->next;
    }
};