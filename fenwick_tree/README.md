# Description
Fenwick Tree (also known as Binary Indexed Tree). This is usefull for efficiently storing the prefix sums of an array which have frequent updates.

# Properties
Initialize the class with the max and min limits of the input indexes. By default it works over all positive `int`.    
data type of max and min limits is `int`. This restricts the allowed range of index numbers to be over `int` only.    
To change this behaviour we need to make changes in the implementation (which is good), otherwise we might end up with an overflow error in some scenario.

method `set` will add the value `d` at the index `I` given to the method.    
method `get` will return the sum of all the value with index less than or **equal** to `I`.

# Code
https://ideone.com/dIYSUb
