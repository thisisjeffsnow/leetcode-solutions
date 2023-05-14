# Problem 6 - Reverse Integer

Given a signed 32-bit integer $x$, return $x$ with its digits reversed. If reversing $x$ causes the value to go outside the signed 32-bit integer range [$-2^{31}$, $2^{31} - 1$], then return $0$.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

# Solution

Create a variable $reversed$ to store the result.

Pull the right most digit from $x$ one-by-one and append it to the right of the current value in $reversed$

$123$ for example:

-   Pull the $3$ off and attach it to $reversed = 3$
-   Pull the $2$ off and attach it to $reversed = 32$
-   Pull the $1$ off and attach it to $reversed = 321$

The operation to remove the right most digit is modular division by $10$. To 'attach' a digit, multiply the current value by $10$ and then add the digit.

Before appending, if $reversed$ is below INT_MIN/$10$ or above INT_MAX/$10$, then return 0.
