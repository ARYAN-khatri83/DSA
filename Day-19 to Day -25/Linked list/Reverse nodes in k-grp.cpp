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
    ListNode* reverseKGroup(Node* head, int k) {
        // base call
        if(head==NULL){
            return NULL;
        }

        // step1 : reverse first k nodes
        Node* next = NULL;
        Node* prev = NULl;
        Node* curr= head;
        int count = 0;

        while(curr != NULL && count <k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // step2 Recursion 
        if(next!=NULL){
            head->next = reverseGroup(next , k);
        }


        // return head of reversed list
        return prev;

    }
};
