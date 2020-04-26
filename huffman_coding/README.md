# Description
Simulate Huffman coding, for lossless compression of a long text.  
Show intermediate states of the memory usage and how exactly the data is stored.  
Also compare the original text size with the final compressed version, to show the efficiency of compression.

# Disclaimer
It misses an edge case where all the text contains just one unique character. The function will behave unexpectedly for such a text.  
There is an inefficiency in the huffman_tree here. We don't need to store the sum of the frequency counts of each subtree. We can save some spcace for the tree there. This was stored for the representational purposes only. To show how the tree actually looks like.

# Code
https://ideone.com/7BBdMz
