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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Initialize a dummy node to build the result list
        ListNode* dummyNode = new ListNode(-1);
        ListNode* current = dummyNode;

        // Merge the two lists
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // If any list remains, append it to the merged list
        if (list1 != NULL) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        // Return the merged list starting from the next of dummy node
        return dummyNode->next;
    }
};
