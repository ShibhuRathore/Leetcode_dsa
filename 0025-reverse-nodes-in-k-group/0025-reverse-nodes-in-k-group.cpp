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
void reverseLL(ListNode*head,ListNode *tail){
  ListNode*curr=head;
  ListNode*prev=NULL;
  while(curr!=NULL){
    ListNode *next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
  }

}
ListNode *getKthNode(ListNode*head, int k){
    ListNode *temp=head;
         while(--k&&temp){
            temp=temp->next;
         }
         return temp;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||!head->next||k==1)return head;
        ListNode *temp=head;
        ListNode *prev=NULL;
        while(temp!=NULL){
           ListNode *kthNode=getKthNode(temp,k);
           if(!kthNode){
           if(prev)prev->next=temp;
            break;}
           ListNode *nextNode=kthNode->next;
           kthNode->next=NULL;
          reverseLL(temp,kthNode);
         if(temp==head)
           {head=kthNode;}
        
           else{
            prev->next=kthNode;}
            prev=temp;
            temp=nextNode;
        }
           
           return head;
    }
};