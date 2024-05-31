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

// samaj nhi ayya but good approach with TC-O(N) (IMPRESSIVE)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        // compute head , Compute the Length of the List:
        ListNode * curr = head;
        int len  = 1;
        while(curr->next && ++len){
            curr = curr->next;
        }

        // get till that node
        curr->next = head; // Make the List Circular:
        k = k%len;
        k = len-k;
        while(k--) curr = curr->next;
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};

// OTHER SOL WITH TC-O(2N)

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


    ListNode* find_Nth_Node(ListNode* temp , int k){
        int cnt = 1;
        while(temp!=NULL){
            if(cnt == k) return temp;
            cnt++;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL){
            tail = tail->next;
            len+=1;
        }
        if(k%len == 0) return head;
        k = k%len;

        tail->next = head;
        ListNode* newLastNode =  find_Nth_Node(head , len-k);
        head=newLastNode->next;
        newLastNode->next = NULL;
        return head;
    }
};

// EXPLANATION
The rotateRight function rotates a linked list to the right by k places. It first checks if the list is empty or has only one node,
returning the head if true. It then finds the list's length by traversing to the last node (tail). If k is a multiple of the list 
length, the list remains unchanged. Otherwise, it calculates the effective rotations needed (k % len). The list is made circular by
connecting tail to the head. The new last node is found at the (len - k)-th position, its next node becomes the new head, and the 
circular link is broken by setting newLastNode->next to NULL. The new head is then returned.
