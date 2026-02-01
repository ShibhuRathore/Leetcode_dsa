/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      ListNode*fast=head;
      ListNode*slow=head;
      bool iscycle=false;
      while(fast&&fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            iscycle=true;
            break;
        }
      }
      if(!iscycle)return NULL;
      fast=head;
      while(slow!=fast){
        fast=fast->next;
        slow=slow->next;
      
      }
      return slow;
    }
};