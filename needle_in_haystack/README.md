# Statement
Search a word in the given string. Return all the positions where the word matches in the string.

# Approach
It generates a unique hash of the word. The hash changes if even a single char is changed. It even changes if a char changes its position. As hash is sensitive to both char value and its position it can be used to check quickly against hash of the part of the string under consideration.

# Caveat
This is a hash based implementation. It sacrifices some accuracy for simplicity and speed. We can have some false positive but never a true negative, i.e., we can get a result where word doesn't actually matches the string, but we will never miss any result if it is present.

It happens because two words may have same hash. Although it is very rare but it is very much a chance. As the hash can take only `mod=1000000007` `(10^9+7)` values, if the number of possible words is more than `mod` some of them will have clashes. In case of a clash we can have a false positive. But same word cannot have two hashes hence we will never have a true negative.

We can put an overhead to check if the word matches at the position or not, once the hash is matched. If size of word is small then the overhead will also be small.

# Complexity
Say size of word : w

say size of search string : n

hash of word : O(w)

hash of window : O(w)

hash of next window : O(1)

moving window accross search space : O(n)

Total Time Complexity : O(n+w)

Overhead : O(r*w)

here r is the size of result

# Code
https://ideone.com/8rv2vs
