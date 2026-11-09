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
 ListNode* swap(ListNode* head){
    ListNode* temp=head;
    int count =0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    temp=head;
    if(count==1||count==0){
        return head;
    }
    ListNode* temp2=NULL;
    ListNode* prev=NULL;
    int k=0;
    while(temp != NULL && temp->next != NULL) {
        if(k==0){
            temp2=temp->next;
            temp->next=temp2->next;
            temp2->next=temp;
            head=temp2;
            prev=temp;
            temp=temp->next;
        }
        else{
            temp2=temp->next;
            temp->next=temp2->next;
            temp2->next=temp;
            prev->next=temp2;
            prev=temp;
            temp=temp->next;
            
        }
        k++;
        
    }
    return head;
 }
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *temp=head;
       return swap(head);
    }
};