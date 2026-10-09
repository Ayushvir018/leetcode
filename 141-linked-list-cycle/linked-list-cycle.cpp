
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         ListNode* visited[10000]; 
//         int count = 0;

//         while (head != NULL) {
//             for (int i = 0; i < count; i++) {
//                 if (visited[i] == head) {
//                     return true; 
//                 }
//             }

//             visited[count] = head;
//             count++;

//             head = head->next;
//         }

//         return false; 
//     }
// };



class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow= head;
        if(head==NULL){
            return false;
        }
        if(head->next==NULL){
            return false;
        }
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            
        
        if(fast==slow){return true;
        }}
        
        return false;
    }
    
};
