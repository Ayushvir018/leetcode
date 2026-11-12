class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL)
            return head;

        ListNode* temp = head;
        ListNode* last = NULL;
        //count .. mja ata h

        int count = 0;

        while(temp != NULL){
            count++;
            last = temp;
            temp = temp->next;
        }
        //kha se cut
        k = k % count;
        if(k == 0)
            return head;
        int cut = count-k;

        temp = head;
        int count1 = 1;
        //jb tk katenge nhi tb tk chhodenge nhi
        while(count1 < cut){
            temp = temp->next;
            count1++;
        }
        //kataaa
        ListNode* temp2 = temp->next;

        temp->next = NULL;
        last->next = head;

        head = temp2;

        return head;
    }
};