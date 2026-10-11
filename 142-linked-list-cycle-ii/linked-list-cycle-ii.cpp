/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* det(ListNode *head) {
    ListNode* fast=head;
    ListNode* slow=head;
    // if(head==NULL || head->next==NULL){
    //     return 0;
    // }
    while( fast!=NULL && fast->next!=NULL ){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return fast;
        }
    }
    return NULL;

        
}

ListNode* pos(ListNode* head){
    // if(head==NULL || head->next==NULL){
    //     return 0;
    // }
    ListNode* slow=head;
    ListNode* inter=det(head);
    if(inter==NULL){
        return NULL;
    }
    while(slow!=inter){
        slow=slow->next;
        inter=inter->next;
    }
    return slow;
}


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        return pos(head);
    }
};