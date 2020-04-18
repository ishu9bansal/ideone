# Description
Write a code to print lexicographically next `k` strings of a given string.
Stop at the lexicographically largest string.

# Complexity

- Space Complexity: O(n)  
Just to represent the string

- Max Heap Size: O(n)  
Recursive stack can maximum go upto the length of the required string.

- Time Complexity: O(n*(d+k))  
Here `d` is the size of the alphabet we are allowed to choose from.  
O(n * d) to reach the given string in the heap space.  
O(n * k) to write out all the strings.

- If we have to print only first `k` iterations, the time complexity would be **O(k)**. As we can just keep a counter and stop when we hit the limit


# Code
https://ideone.com/hqakFi
