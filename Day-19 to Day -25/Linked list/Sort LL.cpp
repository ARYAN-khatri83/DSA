Explanation:
1. findMiddle Function: This function uses the slow and fast pointer technique to find the middle of the linked list. 
  The slow pointer moves one step at a time, while the fast pointer moves two steps. 
  When fast reaches the end of the list, slow will be at the middle.

2. mergeTwoLists Function: This function merges two sorted linked lists into one sorted linked list. 
   It uses a dummy node to simplify the merging process.

3. sortList Function: This function is the main function that implements merge sort for the linked list. 
   It first checks if the list is empty or has only one element, in which case it returns the list itself.
   Otherwise, it finds the middle of the list, splits it into two halves, recursively sorts each half, and then merges the sorted halves.

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
    // Function to find the middle of the list
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to merge two sorted lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummyNode(0);
        ListNode* temp = &dummyNode;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        return dummyNode.next;
    }

    // Function to sort the list using merge sort
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Find the middle of the list
        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;

        // Recursively sort the left and right halves
        ListNode* left = sortList(head);
        right = sortList(right);

        // Merge the sorted halves
        return mergeTwoLists(left, right);
    }
};
