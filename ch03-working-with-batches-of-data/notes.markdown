# Chapter 3: Working with batches of data

## Exercises
0. Done.

1. At this point our values are unsorted.
If we discard element n then the parity of our collection changes (odd to even or even to odd).
This will cause the median value to change unless all the values are equal.

The above proof assumes the number of elements changes if we discard a value.
If we assume the number doesn't change and we just set an element to null:

Assume we can discard element n.
* If `n > median` and x elems on each side of n, now x+1 on left and x-1 on right so median will change.
* If `n == median` obviously nulling it will ruin us.
* If `n < median` no change.

2. sf.

3. sf.

4. sf.

5. sf.

6. On Windows 7, my division by 0 results in `nan`.


## Notes

### 3.1 Computing student grades
`streamsize` for type of io sizes.
`<iomanip>` for manipulators like `setprecision`.

`double` is double-precision floating point numbers. It offers at least 10 (nowadays usually 15 or more) significant digits.
`float` can be as little as 6, so it's usually best to stick with `double`.

If we leave out initialization for a built-in type, it is initialized as undefined, i.e. random garbage.

Using `cin` as a condition is equivalent to testing whether our last attempt to read from it was successful or not.
This is built into the `istream` code.
It is converted to a `bool` so the logical expression can evaluate correctly (details later).

`setprecision` to define our output precision.
`streamsize` is the type expected by `setprecision` and returned by `precision`.


### 3.2 Using medians instead of averages
A `vector` holds a sequence of values of a given type, grows as needed for more values, and lets us get each individual value efficiently.
A `vector` is a container that holds the same type of values.
They grow dynamically and can be appended to using `push_back`.
When growing, a vector must be reallocated.
This is not done with every push - vectors are created with extra space.
The goal is to reallocate a vector a logarithmic number of times so element insertion can be done with amortized constant time complexity.

(http://www.cplusplus.com/reference/vector/vector/push_back/)[Vector]

When working with the size of a container, don't just use an int.
An int may not correctly handle the largest sizes possible.
Instead, use the `size_type` defined by the container.
That provides an unsigned int which is guaranteed to hold the largest possible value.

Use `typedef` to establish a synonym for a given type.

`sort`, from `<algorithm.h>`, sorts a container in-place.
`sort` O-complexity is `n log n`.
