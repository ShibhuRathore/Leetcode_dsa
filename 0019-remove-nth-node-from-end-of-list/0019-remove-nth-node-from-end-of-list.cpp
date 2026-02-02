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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    int count=0;
    if(!head)return NULL;
    ListNode*temp=head;
    ListNode*prev=NULL;
    while(temp!=NULL){
       count++;
       temp=temp->next;
    }

    int jump=count-n;
    temp=head;
    if(jump==0)return head->next;
    for(int i=0;i<jump;i++){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    temp->next=NULL;
    return head;
    }
};