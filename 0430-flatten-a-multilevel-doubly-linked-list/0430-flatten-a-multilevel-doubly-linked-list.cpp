/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> st;
        Node*curr=head;
        while(curr){
            if(curr->child){
                if(curr->next){
                    Node*temp=curr->next;
                    curr->next=NULL;
                    st.push(temp);
                }
                curr->next=curr->child;
                curr->next->prev=curr;
                curr->child=NULL;              
            }
            else if(curr->next==NULL&&!st.empty()){
                Node *newnode=st.top();
                st.pop();
                curr->next=newnode;
                newnode->prev=curr;
            }
            curr=curr->next;
        }
        return head;
    }
};