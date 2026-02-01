class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode *temp = head;
        ListNode *prevtotemp = nullptr; // Initialize as null

        // 1. Move to the starting position
        for (int i = 1; i < left; i++) {
            prevtotemp = temp;
            temp = temp->next;
        }

        // 2. Setup reversal
        ListNode *prev = nullptr;
        ListNode *curr = temp;
        ListNode *next = nullptr;
        ListNode *tailOfSublist = temp; // 'temp' is the original 'left' node

        // 3. Reverse (right - left + 1) nodes
        for (int i = 0; i < (right - left + 1); i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 4. Stitch back together
        // 'prev' is now the new head of the reversed section
        // 'curr' is the first node of the remaining list
        if (prevtotemp != nullptr) {
            prevtotemp->next = prev;
        } else {
            head = prev; // Update head if left was 1
        }
        
        tailOfSublist->next = curr; // Connect tail to the rest of the list

        return head;
    }
};
