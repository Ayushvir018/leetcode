class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL)
            return head;

        ListNode* temp = head;
        ListNode* last = NULL;

        int count = 0;

        while(temp != NULL){
            count++;
            last = temp;
            temp = temp->next;
        }

        k = k % count;

        if(k == 0)
            return head;

        int cut = count-k;

        temp = head;
        int count1 = 1;

        while(count1 < cut){
            temp = temp->next;
            count1++;
        }

        ListNode* temp2 = temp->next;

        temp->next = NULL;
        last->next = head;

        head = temp2;

        return head;
    }
};