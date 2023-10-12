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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(); // create a dummy node
        ListNode *temp = dummy; // copy the val of dummy
        int carry=0;
        while(l1 != NULL || l2 !=NULL || carry){
            int sum = 0;
            if(l1!=NULL){
                sum+=l1->val; // if l1 is not null then we will add the val     
                l1=l1->next;  // of l1 into the sum and inc the l1
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry; // adding carry to sum
            carry = sum/10; // if sum is greate then 10 will div to find the dig
            ListNode *node = new ListNode(sum%10); // create a new node for that new digit
            temp->next = node; 
            temp = temp->next;
        }
        return dummy->next;
    }

};
