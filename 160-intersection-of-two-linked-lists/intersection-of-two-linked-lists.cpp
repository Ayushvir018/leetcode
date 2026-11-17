// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */

//  // Link list ko reverse kro
// ListNode* reverse(ListNode* head) {
//     ListNode* temp = head;
//     ListNode* prev = NULL;

//     while (temp != NULL) {
//         ListNode* next = temp->next;
//         temp->next = prev;
//         prev = temp;
//         temp = next;
//     }

//     return prev;
// }

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* originalA = headA;
//         ListNode* originalB = headB;
//         headA = reverse(headA);
//         headB = reverse(headB);
//         ListNode* temp = headA;
//         ListNode* temp2 = headB;

//         ListNode* ans = NULL;

//         while (temp != NULL && temp2 != NULL) {

//             if (temp != temp2) {
//                 break;
//             }

//             ans = temp;

//             temp = temp->next;
//             temp2 = temp2->next;
//         }
//         reverse(originalA);
//         reverse(originalB);
//         return ans;
//     }
// };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {

            if (a == NULL)
                a = headB;
            else
                a = a->next;

            if (b == NULL)
                b = headA;
            else
                b = b->next;
        }

        return a;
    }
};