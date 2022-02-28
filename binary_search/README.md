# Binary Search
No more information is required. The name tells everything.
## Proof
- Assume the lower bound of the search space is `l` and upper bound is `r`.
- Hence the size of search space say `n` = `r-l`
- We ask 1 question for this search space i.e. for `m = (r-l)/2`, at `m` we ask if given method evaluates `true` or `false`
- depending on the result, the new search space either becomes `l` to `m`, or `m` to `r`
- the size of the new search space = `r-m = n/2` or `m-l = n/2`.
- No matter what the answer is, search space is reduced by a factor of 2
- Hence we have proved that with each successive question we are reducing the search space by a factor of 2
- So in total the search space reduction will look like: `n, n/2, n/4, n/8, ...` and so on
- final question will be on search space of size 1. At which point the search will terminate
- So for calulation of the total number of questions we can analyse the series above.
- The total number of elements in the above searies (before it reduces to 1), will be the total number of questions asked
- The general `ith` term of the series can be written as `n/(2^i)` (0 - indexed)
- from equation `1 = n/(2^i)` we can calculate at which `i`, n reduces to 1, `i = log2(n)`
- as total number of questions are `i+1`, Hence total questions asked are congruent to `O(log n)`

# Features
- Both lower bound and upper bound search, by just the switch of a flag.
- Straight forward algorithm, can be reused in any type of scenario which requires a binary search.

# V2 features
- flexible usage, any type of binary search can directly use the function. Just need to provide comparison function
