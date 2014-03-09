# Chapter 5: Using sequential containers and analyzing strings

## Exercises
The `+` signs denote difficulty. `+++++` is hardest.

0. ++. done.

1. +++++. Done. Wow. That was a HARD problem to implement. It showcased many errors in my problem-solving methodology.

2. ++++. With lists, functions took: 5 ms, 277 ms, 2678 ms with printing. Vector implementation took 5, 275, 2734 ms. Pretty close! Would likely see greater difference with larger inputs.

3. ++. sf.

4. +. Already done in 3.

5. +++. sf. Easier than expected. Learning lots!

6. +++. sf. Updated version took 3721 ms with 10,000 records. Regular version took 8413 ms!
The regular copies them to another vector, then erases them. The updated one just inserts them into the front of the original vector and resizes in the end. I'm honestly surprised at these results. I assumed the constant insertion would really kill efficiency. I guess since we're always inserting in the beginning, it's not as big of a deal?

7. ++. If we pass an empty vector I think it will return a frame comprised of just the top and bottom border because the loops don't execute. I was right!

8. +. If there is a left side, it will work fine. Whenever there isn't, though, we'll have `s +=...` so the next row will contain the previous row's text.
I'm wrong! It threw a `std::length_error` error. I guess when assigning to s, the differing lengths were unacceptable. This only happened when the left pic had few rows than the right.
The error was thrown when attempting to add to s a string of spaces, because we end up with a negative number of spaces from `width - size`.

9. ++. sf.

10. +++. A fun one! Got to work with files and analyzing strings.

11. +++. Another fun one!


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

Fantastic `details` section!


### Exercises
The chapter 5 exercises were difficult, but fantastic ways to learn the topics in-depth.
I worked with strings, vectors, lists, files, sorting, printing, etc.
Great practice!
I also learned more about passing and working with pointers.
