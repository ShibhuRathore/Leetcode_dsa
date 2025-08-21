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
struct Compare{
    bool operator()(ListNode *l1,ListNode *l2){
        return l1->val>l2->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return NULL;
        priority_queue<ListNode*,vector<ListNode*>,Compare>pq;
        for(auto &node:lists){
            if(node)pq.push(node);
        }
      ListNode Dummy(0);
      ListNode *temp=&Dummy;
        while(!pq.empty()){
            ListNode *node=pq.top();
            pq.pop();
            temp->next=node;
            temp=temp->next;
            if (node->next) pq.push(node->next);
        }
        return Dummy.next;
    }
};