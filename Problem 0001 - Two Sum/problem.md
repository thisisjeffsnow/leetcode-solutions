# Problem 1 - Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

# Solution

You could use nested For loops and iterate over the indicies $(i, j)$ and check when $\text{nums}[i] + \text{nums}[j] = \text{target}$, but that's slow and $O(n^2)$ time complexity as we iterate through the array for each index.

Optimally, we should traverse the array once, keeping track of the numbers we've visited in a map. At each iteration, check if the required difference is a number we've already seen by looking in the map. Otherwise, continue.
