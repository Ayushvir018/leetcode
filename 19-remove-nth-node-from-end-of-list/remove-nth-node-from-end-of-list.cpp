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
        int l=0;
        int count=0;
        ListNode *temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if (count == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        temp=head;
        l=count-n;
        for(int i=0;i<l;i++){
            if(i+1==l){
                ListNode* toremove=temp->next;
                temp->next=temp->next->next;
                delete toremove;
            }
            temp=temp->next;
        }
        return head;  
    }
};