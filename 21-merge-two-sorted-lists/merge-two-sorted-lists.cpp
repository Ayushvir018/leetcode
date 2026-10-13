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
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//          vector<int> vals;

//         while (list1) {
//             vals.push_back(list1->val);
//             list1 = list1->next;
//         }

//         while (list2) {
//             vals.push_back(list2->val);
//             list2 = list2->next;
//         }

//         sort(vals.begin(), vals.end());
//         ListNode* dummy = new ListNode(0);
//         ListNode* curr = dummy;

//         for (int x : vals) {
//             curr->next = new ListNode(x);
//             curr = curr->next;
//         }

//         return dummy->next;
//     }
// };
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode dummy(0);
//         ListNode* curr = &dummy;

//         while (list1 != NULL && list2 != NULL) {
//             if (list1->val <= list2->val) {
//                 curr->next = list1;
//                 list1 = list1->next;
//             } else {
//                 curr->next = list2;
//                 list2 = list2->next;
//             }
//             curr = curr->next;
//         }

//         if (list1 != NULL)
//             curr->next = list1;
//         else
//             curr->next = list2;

//         return dummy.next;
//     }
// };
class Solution {
public:
    ListNode* solve(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        ListNode* prev = list1;
        ListNode* curr = list1->next;
        ListNode* next = list2;

        while (next != NULL) {
            if (curr == NULL) {
                prev->next = next;
                break;
            }

            if (next->val <= curr->val) {
                ListNode* next2 = next->next;
                prev->next = next;
                next->next = curr;
                prev = next;
                next = next2;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return list1;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        if (list1->val <= list2->val)
            return solve(list1, list2);
        else
            return solve(list2, list1);
    }
};