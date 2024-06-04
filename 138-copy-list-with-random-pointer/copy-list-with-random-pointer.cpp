/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // insert duplicate node bw existing nodes
    void insertCopy(Node* head) {
        Node* temp = head;

        while (temp != NULL) {
        Node* nextElement = temp->next;
        Node* copy = new Node(temp->val);  
        copy->next = nextElement;  
        temp->next = copy;         
        temp = nextElement; 
        }
    }

    //random pointer of copy node is temp->random->next i.e the copy of temp->random

    void connectRandomPointers(Node* head) {
        Node* temp = head;

        while (temp != NULL) {
            Node* copyNode = temp->next;
            if (temp->random) {
                copyNode->random = temp->random->next;
            } else {
                copyNode->random = nullptr;
            }

            temp = temp->next->next;
        }

        
    }

    //create a new LL with just the copy nodes

    Node* getDeepCopyList(Node* head) {
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;

        while (temp != NULL) {
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummy->next;
    }

    Node* copyRandomList(Node* head) {
        insertCopy(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }
};