---
permalink: 12_ball_puzzle
title: 12 Ball Puzzle
---
# Problem
You are given 12 identical balls, one of which is slightly heavier or lighter than the rest. (All other are of exactly each weights)

You are also given a balance scale to use. Write an algorithm for identifying the defective ball using that scale minimum number of times.

This is achievable in 3 usage. In an ideal scenario we will never need to use the balance more than 3 times to know exactly which ball is defective and also to know whether its heavier or lighter.

Can you find a way to do so?

# Solution
The first trick is to realize that the balance scale don't give us binary information but it gives us one extra information. It just doesn't tell us the left is heavier or the right, it also tells if the things are of equal weight. So if we use the scale smarty we can exploit this property of the scale and achieve our goal.

Another approach while finding the solution is to not get lost in the rabbit hole. We should early reject some of the ideas we try in hit and trial. To early reject something we need to see the redundancy in the method or a lost oppertunity.

So if we see that when using the scale for some use case it is giving us the already known information or even not giving us a good amount of information (at least 3 points of information we should get (defining information is tricky here, we'll have to get a feel for it)) then its a lost cause and we can reject that idea early on.

We should also build a few things bottom top. Keep your answers ready for small use cases, for 2, 3, 4 balls etc. This will give you a connection point while you are deep inside the rabbit hole and you will save you a few backtracks.

# Algorithm
The one algorithm I found is given shape in this cpp code. It also tests all the 12*2 = 24 use cases and prints the result for those.

# Code
```cpp
{% include_relative dIZtHl.cpp %}
```

# [Ideone it!](https://ideone.com/dIZtHl)
