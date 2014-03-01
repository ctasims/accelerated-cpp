# Chapter : 

## Exercises
0. 

1.

2.

3.

4.

5.

6.

7.

8.

9.

10.

11. 


## Notes

### 5.1
Be aware of how you handle data flow.
Copying data from one container into another can result in many copies existing at once.
More efficient methods can reduce your memory footprint.

Be aware of the strengths and weaknesses of data structures.
Selecting an appropriate data structure and algorithm can make the difference.
e.g. indexing is ideal for random access, such as with vectors.
Sequential access can necessitate a different structure.

### 5.2 Iterators
`Iterators` are an abstraction that allows access to data structures in a controlled, optimized fashion.
Iterators:
* identify a container and an element within it.
* allow access to that element.
* provide ops for moving between elements.
* restricts ops to what the container can handle efficiently.

`<type>::const_iterator` and `<type>::iterator` depending on if we want read access or also the ability to modify the element.

`begin()` and `end()` return iterators.

To access the actual element, rather than its address, use the **dereference** operator, `*`. We can also use the shorthand `iter->property` instead of `(*iter).property`.

Some operators are overloaded to handle iterators.
e.g. `iter + 1` correctly increments the element we're looking at; it does not just add 1 to the address.


### 5.3 Using iterators instead of indices, 5.4
Erasing an `iter` invalidates the addresses of all the subsequent elements because they're shifted up.
`erase` returns the address of the new element post-shift to account for this.

Vectors are optimized for fast random access and for adding/removing elements on the end (like a stack). 
Whenever an element is added/removed inside a vector, all the remaining elements must be updated. `n^2` worst-case.


### 5.5 The `list` type
The `list` type is optimized for insertion/removal inside the list.
It is not as efficient for sequential access as vectors, nor can it do indexing.

When an element is added/removed, pointers to the rest of the elements are not invalidated.

`list` comes with it's own sort function, because the standard one won't work.


### 5.6 Taking strings apart, 5.7
The `string` is actually a container abstraction for characters.
It also includes our old friend, `getline`.
(Mostly review.)

