# Problem Statement
Given multiple connected nodes, find if two given nodes are connected or not

# Solution
We can start by thinking that we are assigning one of the nodes as the parent of the other node randomly.
Now assume we want to know if two nodes are connected or not. We can find the super parent of each node, if they are same it means they are connected.
Hence we just want to make finding this super parent super quick. While finding a super parent we pass through all the other parents of the node in between.
We can set their immediate parent as the super parent to find it quicker the next time.

Hence we just take advantage of averages and on average it will return the super parent in very less time

# Bonus
The more we use it more quicker it will become.
The method to set a new link also uses get method internally, so creating the graph randomly gives us good enough calls to make the graph shallow.

# Code
https://ideone.com/xF6FnB
