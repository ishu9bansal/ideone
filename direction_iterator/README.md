# Problem
Create a quick direction iterator, which iterates over all 4 directions, i.e., up down left and right, in. a 2d space.

In many problems we have to do some operation on all the neighboring elements. So in that scenario we might have to write them one by one in the code.
Instead of it if we generate the difference programatically we can write the code more neatly and understandable manner.

# Solution
- Encode the directions in 2 bit binary bitset. Hence directions can be iterated using int [0,4).
- Other is a clever trick I found in someone else's code online. Here we exploit the way of writing the directions.

# Code
https://ideone.com/CGUrP8
