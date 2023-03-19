<?php

/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */
class Solution
{
    /**
     * @param ListNode $l1
     * @param ListNode $l2
     * @return ListNode
     */
    function addTwoNumbers($l1, $l2)
    {
        $return = new ListNode();
        $current = $return;
        $carry = 0;

        while ($l1 || $l2 || $carry > 0) {
            $current_sum = $carry + ($l1 ? $l1->val : 0) + ($l2 ? $l2->val : 0);
            $carry = $current_sum > 9 ? 1 : 0;
            $current->next = new ListNode($current_sum % 10);
            $current = $current->next;
            $l1 = $l1 ? $l1->next : null;
            $l2 = $l2 ? $l2->next : null;
        }

        return $return->next;
    }
}
