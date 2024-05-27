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

        ListNode* temp=head;
        int cnt=1;

        while(temp->next!=NULL){
            temp=temp->next;
            cnt++;
        }

        int jump=0;

       if(cnt/2==0) {
        jump=cnt/2;
       }else{
         jump=cnt/2+1;
       }
       
       ListNode* h=head;
       for(int i=1; i<jump; i++){
        h=h->next;
       }
       return h;
        
    }
};