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
ListNode* rev(ListNode* head, int k,int a) {
        //base case
    if(head==NULL){
        return NULL;
    }
        //reverse ka logic
    int count=0;
    ListNode* prev=NULL;
    ListNode* next=NULL;
    ListNode* curr=head;
    while(curr!=NULL && count<k &&a>0){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
        //recursion
    if(a>1){
        if(next!=NULL){
            head->next= rev(next, k,a-1);
        }}
    else{
        head->next = next;
        }
    
        //print
    return prev;

}


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int c=0;
        //node count 
        ListNode* curr=head;
        while(curr!=NULL ){
            curr=curr->next;
            c++;
        }
        int a=c/k;
        return  rev(head, k,a);
    }
};