class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        ListNode* dummy = new ListNode(0);

        ListNode* curr = head;

        while (curr != nullptr) {

            // Save next node
            ListNode* next = curr->next;

            // Find correct position
            ListNode* prev = dummy;

            while (prev->next != nullptr &&
                   prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Insert curr at correct position
            curr->next = prev->next;
            prev->next = curr;

            // Move to next original node
            curr = next;
        }

        return dummy->next;
    }
};