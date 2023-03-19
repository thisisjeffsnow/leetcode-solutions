# Problem 3 - Longest Substring Without Repeating Characters

Given a string $s$, find the length of the **longest substring** without repeating characters.

# Solution

Make a blank pile (string) to store characters. Have two points, A, and B starting at the beginning of the string. Slide B forward, trying to add the next char to the current pile. As long as that character doesn't exist in the pile, then the extracted string is the longest so far. If the char exists already, increment A so it's past the first instance of that character and make a new pile from that unique string. Keep track of the max length along the way, and return it at the end.
