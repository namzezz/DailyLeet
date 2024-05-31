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
    
    ListNode* reverseList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp; 
            temp = front;
        }

        return prev;
    }

    ListNode* getKthNode(ListNode* temp, int k){
        k-=1;
        while(temp!=NULL && k>0){
            k--;
            temp = temp -> next; 
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while(temp!=NULL){

            //get the kth node
            ListNode* kthNode = getKthNode(temp ,k);
            //edge case if ll length is less than k then connect the prev ll to this ll
            if(kthNode == NULL){
                if(prevLast) 
                {prevLast ->next = temp;}
                break;            
            }
            //preserve the next of kthnode to join later
            ListNode* nextNode = kthNode->next;
            //seperate k length ll to reverse it
            kthNode->next = NULL;
            //reverse kgrp
            reverseList(temp);

            //for the first grp temp==head (no prevlast)
            if(temp == head){
                head = kthNode;
            }
            //connecting the prev LL group's last node to the first node(kth node after reversal) 
            else{
                prevLast->next = kthNode;
            }

            prevLast = temp;
            temp = nextNode;

        }

        return head;
    }
};