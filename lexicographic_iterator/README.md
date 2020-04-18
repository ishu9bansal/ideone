# Description
A recursive method to genearate the lexicographic iterations of a certain length.

# Complexity

- Space Complexity: O(n)  
Just to represent the string

- Max Heap Size: O(n)  
Recursive stack can maximum go upto the length of the required string.

- Time Complexity: O(n*d^n)  
Here `d` is the size of the alphabet we are allowed to choose from. This is the minimal amount of time just to write it out.

- If we have to print only first `k` iterations, the time complexity would be **O(k)**. As we can just keep a counter and stop when we hit the limit


# Code
https://ideone.com/hqakFi
