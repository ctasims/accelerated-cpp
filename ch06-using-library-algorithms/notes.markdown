# Chapter 6: Using library algorithms

## Exercises
0. sf.

1. sf. 

2. sf.

3. sf. This program crashes.

4. sf.

5. See `grade_analysis.cpp`.

6. 

7. 

8. 

9. 


## Notes

### 6.1 Analyzing `strings`
Common interfaces are used so that the standard library can provide useful algorithms that work in a general way.
Such an algorithm is called a `generic algorithm`.
Generic algorithms use their inputs to determine their functionality.
For example, `copy`:

    copy(bottom.begin(), bottom.end(), back_inserter(ret));

`copy` copies the content `[begin, end)` at the end of `ret`.

The postfix operator, `it = begin++`, is equivalent to:

    it = begin;
    ++begin;

It returns the value and then increments it.

`iterator adaptors` return iterators based on their arguments.
`back_inserter` returns an iterator that points to the end of its argument.

The algorithm `find_if(x,y,z)` tests the predicate `z` on each item in the sequence `[x, y)`.

`static` is a storage class specifier.
It causes a variable to persist through function calls.


### 6.2 Comparing grading schemes
When checking if container has elements, use `empty()` instead of checking size.

`transform` takes three iterators and a predicate and applies the predicate to the elements between [x, y) and appends them to z.

Use `void` when a function shouldn't return a value.

The standard library provides `_copy` variants of algorithms which copy the results into the provided location.


### 6.3 Classifying students, revisited
`remove_copy_if` will shuffle all `true` elements to the front and will set the failing elems to be replaced.
It will also copy the `true` elems to the designated location.

`erase` erases the elements between the provides iterators.

`partition` and `stable_partition` will rearrange elements based on a predicate.


### 6.4 Algorithms, containers and iterators
Algorithms act on container elements, not on containers themselves.

If we want to remove elements, we must explicitly call the removal.
The following code rearranges elements so the failing ones are at the end of the container.
It then returns an iterator pointing to the last elem that failed the predicate.

    remove_if(students.begin(), students.end(), fgrade)

If we want to actually remove these elements, we must call `erase` next.

Generic algorithms do not change the size of a container(?)

Note that iterators are often invalidated after a container or its elements have been modified.


