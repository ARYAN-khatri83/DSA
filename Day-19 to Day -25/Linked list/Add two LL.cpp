
Psuedocode
1. Create a dummy node which is the head of new linked list.
2. Create a node temp, initialise it with dummy.
3. Initialize carry to 0.
4. Loop through lists l1 and l2 until you reach both ends, and until carry is present.
Set sum=l1.val+ l2.val + carry.
Update carry=sum/10.
Create a new node with the digit value of (sum%10) and set it to temp node's next, then advance temp node to next.
Advance both l1 and l2.
Return dummy's next node.
Note that we use a dummy head to simplify the code. Without a dummy head, you would have to write extra conditional statements to initialize the head's value.

Time Complexity: O(max(m,n)). Assume that m and n represent the length of l1 and l2 respectively, the algorithm above iterates at most max(m,n) times.

Space Complexity: O(max(m,n)). The length of the new list is at most max(m,n)+1.


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
    ListNode* addTwoNumbers( ListNode* l1,  ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1); 
        ListNode* temp = dummyHead;
        ListNode* curr = dummyHead;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carry  = 0;
        while(temp1 !=  nullptr|| temp2 != nullptr){
            int sum = carry;
            if(temp1){
                sum += temp1->val;
                temp1 = temp1->next;
            }
            if(temp2){
                 sum += temp2->val;
                 temp2 = temp2->next;
            }

            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;

           curr->next = newNode;
           curr =  curr->next;

           if(carry>0){
            // ListNode* newNode = new ListNode(carry);
            curr->next = new ListNode(carry);
           }
        }
        return dummyHead->next;
    }
};
