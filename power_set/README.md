# Problem

Print the power set of a given set of numbers, in the lexicographically sorted order.

# Solution

https://ideone.com/DXm5uR

# Explanation

A power set of a set (set here is the mathematical collection of numbers) is the set of all its subsets.
It can be done by recursive method or iterative method. Both are shown in the solution.
Both the solution are exponential in time complexity, as the size of the output is exponential.
But the recursive approach is better here, because, it uses maximum stack memory of O(n).
While the iterative method is incrementaly creating the answer and storing it in the memory,
pushing its space complexity to be same as the time complexity that is exponential O(n*2^(n-1))

# Complexity

Size of a power set is 2^n if size of set is n. Not only this, each element of power set will have elements in it, ranging from 0-n.
We have to print the whole power set i.e., all the subsets of given set.
Hence the problem is inherently exponential. Total n*2^(n-1)  numbers to be printed.

