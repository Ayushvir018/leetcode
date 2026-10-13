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
int len1(ListNode* l1){
    ListNode* curr = l1;
    int c1=0;
    while(curr!=NULL){
        c1++;
        curr=curr->next;
    }
    return c1;
}
int len2(ListNode* l2){
    ListNode* curr = l2;
    int c2=0;
    while(curr!=NULL){
        c2++;
        curr=curr->next;
    }
    return c2;
}

ListNode* add(ListNode* l1, ListNode* l2) {
    int carry=0;
    ListNode* curr=l1;
    while (curr!= nullptr  ) {
        int sum=curr->val+carry;
        if(l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
        }
        curr->val=sum%10;
        carry=sum/10;

        if(curr->next==NULL &&carry>0){
            curr->next=new ListNode(carry);
            carry=0;
        }
        curr=curr->next;
                
    }
    return l1;
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        int c1=len1(l1),c2=len2(l2);
        if(c1>c2){
            return add(l1,l2);
        }
        else{
            return add(l2,l1);
        }
        

        
    }
};
