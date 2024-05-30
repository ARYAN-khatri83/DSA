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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next; 
        ListNode* evenHead = head->next; // evenHead would be used when there would be link change between odd and even , to point the last odd number to the even one.
        while(even!=NULL && even->next!=NULL){ // even will ensure odd is completed 
            odd->next = even->next;
            odd=odd->next;

            even->next = odd->next;
            even=even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
