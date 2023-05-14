# Problem 5 - Longest Palindromic Substring

Given a string $s$, return the longest **palindromic substring** in s.

# Solution

We are given that the length of $s$ is at least $1$.

Initalize the variable responsible for holding the longest string equal to the first character of $s$. Keep track of the current maximum palindromic string length we've found so far as well.

Iterate through each character of $s$ (let's call that position $p$) and consider $p$ the hypothetical center of a potential palindome for now. Extract from $s$, a number of characters from the left and right of $p$ such that the extracted string is at least the maximum length palindrome we've seen so far. Increase this 'max spread' as long as the resulting string is still within the bounds of $s$ and is indeed a palindrome. This handles the cases when the number of characters in the palindrome is odd.

For the even case, consider $p$ and an adjacent letter the 'center' of the hypothetical palindrome, and increase the 'max spread' in the same way, as long as the substring is a palindrome and within the bounds of $s$.

Continue choosing new centers as long as we have room to extract substring candidates that are at least as long as the best palindrome substring we've already seen. For example, if we've already seen a palindome substring of length 10, there's no reason to check values of $p$ that are within three characters distance from the end of the string as the biggest possible palindome with $p$ as a center in that case wouldn't even be of length 10. This will speed up the iteration significantly.

Then return the max substring palindome we've seen.
