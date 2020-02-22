# Question

When we ```find()``` an element in a set, the iterator for the set which is returned, points to the object itself or the position of the object in the set?

That is when a new object is added in the set, will the iterator be pointing to the same object, or is it going to change due to rearrangement of the elements of the set?

# Answer

Question becomes irrelavent because, from the iterator we cannot know the position of the object in the set, i.e., syntax ```it-2``` or ```it-h.begin()``` doesn't work.
Iterator doesn't store any position information, it only points to the object of the set directly.

But it is an iterator at the end so it has some kind of position information because it can go to the next and previous elements of the set in constant time.
There comes the part that it is a bi-directional iterator and not the random-access iterator.

# Exection

https://ideone.com/odvz6E
