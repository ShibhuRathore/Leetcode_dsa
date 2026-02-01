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
void reverseLL(ListNode*head){
ListNode*prev=NULL;
ListNode*curr=head;
while(curr!=NULL){
    ListNode*next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
}
}
ListNode* Kth(ListNode* head, int k){
    ListNode* temp=head;
    while(--k&&temp!=NULL){
        temp=temp->next;
    }
    return temp;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode*nextNode=NULL;
       ListNode*prevNode=NULL;
       ListNode*KthNode=NULL;
       ListNode*temp=head;
       while(temp!=NULL){
        KthNode=Kth(temp,k);
        if(KthNode==NULL){
            if(prevNode)prevNode->next=temp;
            break;
        }
        nextNode=KthNode->next;
        KthNode->next=NULL;
        reverseLL(temp);
        if(temp==head)head=KthNode;
        else{
            prevNode->next=KthNode;
        }
        prevNode=temp;
         temp=nextNode;
       }
       return head;
    }
};