Explanation:
reverseLinkedList Function:
This function reverses the entire linked list starting from head and returns the new head after reversal.
The comments within the function explain each step of the reversal process.
  
getKthNode Function:
This function returns the k-th node from the current position. If there are fewer than k nodes left, it returns nullptr.
The comments within the function describe the process of finding the k-th node.
  
reverseKGroup Function:
This function performs the main logic of reversing nodes in groups of k.
It first checks if the k-th node exists. If not, it means the remaining nodes are less than k, so no reversal is needed.
If the k-th node exists, it reverses the nodes from the current node to the k-th node.
It then updates the previous group's last node (prevLast) to point to the newly reversed group.
The loop continues until all nodes are processed.
The comments within the function describe each step of the process.




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

    // Function to reverse a linked list using the 3-pointer approach
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* temp = head;  
        ListNode* prev = nullptr;  
        while(temp != nullptr) {  
            // Store the next node in 'front' to preserve the reference
            ListNode* front = temp->next;  
            // Reverse the direction of the current node's 'next' pointer to point to 'prev'
            temp->next = prev;  
            // Move 'prev' to the current node for the next iteration
            prev = temp;  
            // Move 'temp' to the 'front' node advancing the traversal
            temp = front; 
        }
        return prev;  
    }

    // Function to get the Kth node from a given position in the linked list
    ListNode* getKthNode(ListNode* temp, int k) {
        // Decrement K as we already start from the 1st node
        k -= 1; 
        // Decrement K until it reaches the desired position
        while(temp != nullptr && k > 0) {
            // Decrement k as temp progresses
            k--; 
            temp = temp->next; 
        }
        return temp; 
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // Initialize a temporary node to traverse the list
        ListNode* temp = head; 
        // Initialize a pointer to track the last node of the previous group
        ListNode* prevLast = nullptr; 
        
        // Traverse through the linked list
        while(temp != nullptr) {
            // Get the Kth node of the current group
            ListNode* kThNode = getKthNode(temp, k); 
            // If the Kth node is NULL (not a complete group)
            if(kThNode == nullptr) {
                // If there was a previous group, link the last node to the current node
                if(prevLast != nullptr) {
                    prevLast->next = temp; 
                }
                // Exit the loop
                break; 
            }
            
            // Store the next node after the Kth node
            ListNode* nextNode = kThNode->next; 
            // Disconnect the Kth node to prepare for reversal
            kThNode->next = nullptr; 
            // Reverse the nodes from temp to the Kth node
            ListNode* reversedHead = reverseLinkedList(temp); 
            
            // Adjust the head if the reversal starts from the head
            if(temp == head) {
                head = reversedHead;
            } else {
                // Link the last node of the previous group to the reversed group
                prevLast->next = reversedHead; 
            }
            
            // Update the pointer to the last node of the previous group
            prevLast = temp; 
            // Move to the next group
            temp = nextNode; 
        }
        
        // Return the head of the modified linked list
        return head; 
    }
};
