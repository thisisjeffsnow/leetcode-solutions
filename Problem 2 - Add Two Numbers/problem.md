# Problem 2 - Add Two Numbers

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

# Solution

Create a variable to keep track of any values that carry over from addition. Begin a new linked list, and move along the linked list assigning each node the mod 10 value of the sum of the respective nodes from both lists, adding and reseting the carry value as necessary.

Some lists will be shorter than others, so assume a node has a zero value if it doesn't exist, and continue iterating as long as there are nodes or carry values present.
