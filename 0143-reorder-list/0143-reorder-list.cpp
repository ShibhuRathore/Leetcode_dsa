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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nex = head;

        while (curr) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *temp = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *newList = reverseList(slow->next);
        fast = newList;
        slow->next = NULL;
        slow = head;

        ListNode *temps = slow;
        ListNode *tempf = fast;
        ListNode* ans = new ListNode(-1);
        ListNode* tans = ans;

        while(tempf != NULL && temps != NULL){
            
            tans->next = temps;
            tans = tans->next;
            temps = temps->next;
            
            tans->next = tempf;
            tans = tans->next;
            tempf = tempf->next;

        }
        if(tempf != NULL){
            tans ->next = tempf;
        }
        if(temps != NULL){
            tans ->next = temps;
        }
        head = ans->next;

        
    }
};