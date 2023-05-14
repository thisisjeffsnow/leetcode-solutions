/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    struct ListNode result = {0, NULL};
    struct ListNode* result_ptr = &result;
    struct ListNode* current = &result;
    int carry = 0;

    while(l1 != NULL || l2 != NULL || carry > 0) {
        int current_sum = carry + (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0);
        carry = current_sum > 9 ? 1 : 0;
        
        struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
        new->val = current_sum % 10;
        new->next = NULL;
        
        current->next = new;
        current = current->next;
        
        l1 = (l1 != NULL ? l1->next : NULL);
        l2 = (l2 != NULL ? l2->next : NULL);
    }
    
    return result_ptr->next;

}