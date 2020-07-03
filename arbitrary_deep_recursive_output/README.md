# Description

Technique to get output quickly (logarithmic time) of arbitrary number of repeated application of a transformation function over a finite domain.

# Solution

We have finite number of inputs, hence we can generate the transformations after 1 operation on the all the inputs and save it.

We can use this generated mapping to produce the transformations after 2 operations on the all the inputs and save it.

We can use this generated mapping to produce the transformations after 4 operations on the all the inputs and save it.

and so on...

hence we have a 2D list of all the transformations after `2^x` operations.

We can use this list to calculate the transformation after any arbitrary number `n`, 
by decomposing the number into a binary and then iteratively producing transformation after each set bit (powers of two).

The code will give more clarity, as it is very much self explainatory.

# Trivia

The code compares the iterative method with this one for verifying the results. This method is an exponential improvement on the iterative method


# Complexity

Iterative Method (Naive)
 - Time Complexity: `O(n)`
 - Space Complexity: `O(1)`

This technique:
 - Time Complexity: `O(log(N))` ~ `O(1)`
 - Space Complexity: `O(m*log(N))`

Precomputation:
 - Time Complexity: `O(m*log(N))`
 - Space Complexity: `O(m*log(N))`

Here
 - `n`: arbitrary number of operations
 - `N`: Max input we can expect for `n`.
 - `m`: finite domain of transformatino function

# Code
https://ideone.com/I9WNY7

# Usage

https://leetcode.com/submissions/detail/361593754/?from=/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3379/
