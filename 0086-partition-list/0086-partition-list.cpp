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
    ListNode* partition(ListNode* head, int x) {
  ListNode smallDummy(0);
  ListNode bigDummy(0);
  ListNode *Big=&bigDummy;
  ListNode *Small=&smallDummy;
  ListNode *small=&smallDummy;
  ListNode *big=&bigDummy;
 ListNode *temp=head;
  while(temp!=NULL){
      if(temp->val<x){
        ListNode *newnode=new ListNode(temp->val);
        small->next=newnode;
        small=newnode;
      }
      else{
        ListNode *newnode=new ListNode(temp->val);
        big->next=newnode;
        big=newnode;
      }
      temp=temp->next;
  }
  small->next=Big->next;
  Big->next=nullptr;
  return Small->next;
    }
};