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
    ListNode* middleNode(ListNode* head) {
        if(head->next==nullptr)
        return head;
        if(head->next->next==nullptr)
        return head->next;

        ListNode* l=head;
        ListNode* m=head;
        int cnt=0;
        while(l&&l->next){
            cnt++;
            cout<<l->val<<endl;
            l=l->next;
        }
        cnt++;
        int n=cnt/2;
        n++;
        while(m&&m->next){
            if(n==1) return m;
            n--;
            m=m->next;
        }
        return head;
    }
};