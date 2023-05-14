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
        
        ListNode* result = new ListNode(0);
        int carry = 0;
        
        ListNode* current = result;
        int current_sum = 0;
        
        while(l1 || l2 || carry > 0) {
            current_sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            current->next = new ListNode(current_sum % 10);
            current = current->next;
            carry = current_sum/10;
            l1 = (l1 ? l1->next : nullptr);
            l2 = (l2 ? l2->next : nullptr);            
        }
        
        return result->next;
    }
};