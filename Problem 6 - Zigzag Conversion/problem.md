# Problem

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

```
P   A   H   N
A P L S I I G
Y   I   R
```

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

```
string convert(string s, int numRows);
```

# Solution

I created an array of length $\text{numRows}$, iterated through the string, and threw each character of $s$ into the correct row. Then collapsed the array into a string. I'm sure there's a faster way to do this.

For example, you could create a blank string with the same length as $s$, iterate through $s$ and determine the position of the $n\text{th}$ character in the return string based on a formula, and then just return the string.
