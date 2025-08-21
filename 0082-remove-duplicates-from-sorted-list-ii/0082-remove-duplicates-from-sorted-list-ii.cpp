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
    ListNode* deleteDuplicates(ListNode* head) {
         if (!head || !head->next) return head;
      ListNode Dummy(0);
      Dummy.next=head;
      ListNode*prev=&Dummy;
      ListNode*curr=head;
      while(curr){
      ListNode*next=curr->next;
        bool dup=false;
        while(next&&curr->val==next->val){
            dup=true;
           next=next->next;
        }
        if(dup==true){
            prev->next=next;
            curr=next;
        }
        else{
            prev=curr;
            curr=next;
         
        }
      }
      return Dummy.next;
    }
};