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

 ListNode *ReverseLL(ListNode *head){
    
    ListNode *prev=NULL;
    ListNode *curr=head;
    while(curr!=NULL){
        ListNode* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
 }
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||head->next==NULL)return true;
    ListNode *slow=head;
    ListNode *fast=head;
    while(fast->next&&fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* temp=ReverseLL(slow->next);
    ListNode *temp2=head;
    while(temp!=NULL){
        if(temp->val!=temp2->val){return false;}
        else{
            temp=temp->next;
            temp2=temp2->next;
        }
    }
    return true;
    }
};