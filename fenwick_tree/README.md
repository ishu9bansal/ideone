# Description
Fenwick Tree (also known as Binary Indexed Tree). This is usefull for efficiently storing the prefix sums of an array which have frequent updates.

# Properties
Initialize the class with the max and min limits of the input indexes. By default it works over all positive `int`.    
data type of max and min limits is `int`. This restricts the allowed range of index numbers to be over `int` only.    
To change this behaviour we need to make changes in the implementation (which is good), otherwise we might end up with an overflow error in some scenario.

method `set` will add the value `d` at the index `I` given to the method.    
method `get` will return the sum of all the value with index less than or **equal** to `I`.

# Complexity

Time: `O(log(N)) = O(1)`  *for both get and set operations*    
Space: `O(n * log(N))`    *overall space used in worst case*

**Naive method**

`set` Time: `O(log(n)) ~ O(log(N)) ~ O(1)`     *insertion in an ordered map*    
`get` Time: `O(n)`          *iterate upto the last element in worst case*    
Space: `O(n)`

Other naive implementation is to store the prefix sums instead of the values itself, but that will **only flip** the time complexity for get and set operations, keeping the overall complexity same if both the operations are equally frequent.

__Legend__

`n`: number of unique indexes for which the updates may come    
`N`: size of the range of the input numbers, i.e., `max-min+1`

# Code
https://ideone.com/dIYSUb

# Usage
 - https://leetcode.com/problems/count-of-smaller-numbers-after-self/
 - https://leetcode.com/submissions/detail/350260092/
 - https://leetcode.com/submissions/detail/350897497/
