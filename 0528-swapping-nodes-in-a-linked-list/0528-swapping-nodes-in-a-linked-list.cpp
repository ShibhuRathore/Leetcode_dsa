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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *temp=head;
        int n=k-1;
        ListNode *last=head;
        int size=1;
       
        while(temp->next!=nullptr){
            temp=temp->next;
            size++;
        }
        if (k < 1 || k > size) return head;

       temp=head;
        int m=size-k;
        while(n){
            n--;
            temp=temp->next;
        }
        while(m){
            m--;
            last=last->next;
        }
        
         int temp2=temp->val;
         temp->val=last->val;
         last->val=temp2;
         return head;
    }
};