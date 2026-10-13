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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        int a = count / k;
        int b = count % k;

        vector<ListNode*> ans(k, NULL);
        temp = head;

        for (int i = 0; i < k; i++) {
            ans[i] = temp;
            int size = a + (i < b ? 1 : 0);

            for (int j = 1; j < size; j++) {
                temp = temp->next;
            }

            if (temp != NULL) {
                ListNode* nextPart = temp->next;
                temp->next = NULL;
                temp = nextPart;
            }
        }

        return ans;
    }
};