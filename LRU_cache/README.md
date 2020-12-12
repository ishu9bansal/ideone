# Description
Implement LRU cache (Least Recenetly Used).

# Definition
An LRU cache has a fixed capacity. It supports two type of operations, `put` and `get`.  
We can store a key value pair in the cache using a `put` method.  
We can retrieve a value for a key by `get` method (if it is present in the cache).  
As the capacity of the cache is fixed, it can only store limited number of unique key value pairs.  
If the capacity of the cache is reached, we can remove the least recently used key from the cache memory.  
As cache needs to be fast, it has to support both `get` and `put` methods with O(1) time complexity.

# Solution
Under the hood, two data structures are used to achieve the functionality of the LRU cache.  
One is the obvious choice of hashmap.
As we have to get and set the value of any key in O(1) time complexity, the natural choice would be a hashmap.
Hashmap can do both of these operations in O(1) time complexity.  
But we also have to remove the least recently used element once the capacity is reached.
Hence to keep track of the usage of the keys we want one more data structure.
We want to have some kind of list which is ordered by the usage of the key.
Once a key is used it comes in the front of the list.
And once the capacity is reached we can remove the last key in the list from the hahsmap.  
A doubly linked list will be ideal choice for these kind of operations. As inserting in front of the linked list is O(1).
Identifying the last element in the list is O(1). Removing an element from the middle of the list is O(1).  
Hence both the operations `get` and `put` can be done in O(1) time complexity.

# Complexity
Time Complexity: O(`1`)  
Space Complexity: O(`n`)  
`n`: capacity of the cache

