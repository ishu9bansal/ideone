# Description
Simulate Huffman coding, for lossless compression of a long text.  
Show intermediate states of the memory usage and how exactly the data is stored.  
Also compare the original text size with the final compressed version, to show the efficiency of compression.

# Disclaimer
It misses an edge case where all the text contains just one unique character. The function will behave unexpectedly for such a text.  
There is an inefficiency in the huffman_tree here. We don't need to store the sum of the frequency counts of each subtree. We can save some spcace for the tree there. This was stored for the representational purposes only. To show how the tree actually looks like.

# Complexity
Size of input text: `n`  
Uniq chars in text: `q`  
- Creating the tree:
    - Time Complexity: O(`n` + `qlog(q)`), counting frequency of uniq chars + creating the tree.
    - Space Used for tree: O(`q`), total `2*q` nodes will be there
    - Auxiliary space: O(`q`), keeping the frequency table for unique chars
- Creating the table: Uses dfs to reach all the leaf nodes and record the path to reach there against the leaf value in a hashmap  
    - Time Complexity: O(`q`)
    - Space used for table: O(`q`)
    - Reccursive stack space: O(`log(q)`), maximum depth of the tree ~ 9-10
- Encoding:
    - Time Complexity: O(`n`), read every char and replace it with corresponding bitpath
    - No extra space required than the table used for encoding
- Decoding:
    - Time Complexity: O(`n`), traverse the tree one step over each bit in the encoding.
    - No extra space required than the tree used for decoding

# Code
https://ideone.com/7BBdMz
