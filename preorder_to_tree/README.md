# Problem
Given a preorder traversal of a binary search tree. Create the tree and print the tree. (Assume all the nodes are unique)

# Description
This problem covers three concepts.
 - Insertion of a node into a BST
 - Understanding preorder traversal
 - Printing a tree

### Printing a tree
Printing trees in top to bottom manner is not ideal with how we use our screens.  
Mostly we have scrollable pages in vertical direction, hence we have more space in vertical direction. Horizontal direction is just limited to the screen width.  
But as we know the height of the tree is `h ~ log(n)` while width of the tree `w ~ n/2`.  
As the width increases exponentially faster than the height of the tree, it would be ideal to print trees from left to right.
That is column wise. In the first column just the root node, in second column the nodes at level 1, in third column the nodes at level 2 and so on.  
For a more general tree (with more than 2 children) we can just print the parent node at top and then the whole subtree below it, and next subtree below that one and so on. But for Binary trees we can do better. We can print the parent node in the middle of two subtrees. This gives a nice visual feel of the whole tree.

### Preorder Traversal
In a preorder traversal we traverse the root node, then left subtree in recursive manner, and then right subtree.

### Binary Search Tree
Binary search tree is a binary tree which follows the invariant that for each node the max value in the left subtree of the node is less than the node value, and the min value of the right subtree is greater than the node value.
Equality case can be decided to place at any one side.

### Explaination
From the structure of a BST and the way preorder traversal is done, it is not difficult to see that we can start inserting the nodes in the order of preorder traversal and it will create a BST that will give out the same preorder traversal. (Given that all entries of preorder traversal are unique)
