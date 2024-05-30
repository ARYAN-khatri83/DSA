/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Detect if there is a cycle in the list
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // Cycle detected, now find the start of the cycle
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // slow (or fast) is now at the start of the cycle
            }
        }
        
        return NULL; // No cycle detected
    }
};
