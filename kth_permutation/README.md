# Description

Find the `kth` permutation of a given string.
The ordering of the permutations can be derived by following the order of the lexicographically sorted permutations of an array of distinct numbers.
k is `0-indexed`, hence `0th` permutation is the given string itself.

# Insights

The number of permutations of a string of length n = `n!`. This becomes very huge very quickly. `20!` is near the max limit of the cpp `long long` type.
So even if `n` is huge, the input `k` which we assume will fit in a long long will restrict the length to be considered for permutation very small, i.e. less than `20`.

While computing the permutation there are swap operations in the algorithm. Maximum number of swaps for finding a permutation will not exceed `19*20/2 = 190`.

For all practical purposes the time complexity for finding a permutation of the string is nearly constant.
And the swaps happen in place, and no other data structure is used to be stored in some auxilary space hence constant space complexity as well.

Time Complexity: `O(1)`

Space Complexity: `O(1)`

# Solution
https://ideone.com/1rlVkm
