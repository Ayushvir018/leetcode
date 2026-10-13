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
 bool pal(vector<int> arr){
    int k=arr.size()-1;
    int i=0;
    while(i<k){
        if(arr[i]!=arr[k])return false;
        i++;
        k--;
    }
    return true;

 }
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int>arr;
        ListNode* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
            
        }
        return pal(arr);
    }
};