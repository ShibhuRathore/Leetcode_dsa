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
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        Node*curr=head;
        while(curr!=NULL){
             Node *node=new Node(curr->val);
            node->next=curr->next;
            curr->next=node;
            curr=node->next;
        }
        curr=head;
        while(curr!=NULL){
        Node *clone=curr->next;
            if(curr->random){
                clone->random=curr->random->next;
            }
            else{
                clone->random=NULL;
            }
            curr=clone->next;
          
        }
         Node* newHead = head->next;
        for (Node* cur = head; cur; ) {
            Node* clone = cur->next;
            cur->next = clone->next;
            clone->next = clone->next ? clone->next->next : nullptr;
            cur = cur->next;
        }

        return newHead;

    }
};