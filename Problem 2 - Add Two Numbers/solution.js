/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    
    var carry = 0;
    var result = new ListNode();
    var current = result;
    var current_sum = 0;
    
    while(l1 || l2 || carry > 0) {
        current_sum = carry + (l1 ? l1.val : 0) + (l2 ? l2.val : 0);
        carry = (current_sum > 9) ? 1 : 0;
        current.next = new ListNode(current_sum % 10);
        current = current.next;
        l1 = ( l1 ? l1.next : null);
        l2 = ( l2 ? l2.next : null);
    }
    
    return result.next;
    
    
};