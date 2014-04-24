# Chapter 8: Writing Generic Functions

## Exercises
Ranking: 1 easy, 5 hard.

0. done. Lots of tests...

1. (2) done. That was hairy... I'm already finding ways to improve my coding style.

2. (4) Seriously good exercise in gaining familiarity with templates and some simple algorithms.

3. (2) This should give an excellent speedup, depending on size of containers.

4. (3) I'm not sure why we can't just implement it in-line. Worked fine for me either way.

5. (3) done.

6. (2) x is iterator of container/object that can handle same pairs as m because we're copying elements from a map into another map.

7. (1) As mentioned, max has no way of inferring which arg should be converted to which, if they're different.

8. (1) Because begin and end are iterators, not absolute numbers, so we want to calculate an offset from the beginning iterator, not some absolute value.


## Notes
**Generic functions** are used when return and parameter types are not known until the function is called. C++ implements generic functions with **template functions**.

**Template Functions** have the form:

    template<class type-parameter [, class type-param]... >
    return-type function-name (parameter-list)

The caller must include the actual types if they cannot be inferred:

    template<class T> T zero() { return 0; }
    ...
    double x = zero<double>();

Use the **typename** keyword to qualify declarations using inferred types:

    typename T::size_type name

When a generic function is called, the code is instantiated with the provided types.
This instantiation often happens at link time in the edit-compile-link model.

C++ maintains separation between data structures and algorithms using iterators.
There are five iterator types. Each one assumes the capabilities of the previous:

* Input iterator: sequential access in one direction, input only
* Output iterator: sequential access in one direction, output only
* forward: sequential access in one direction, input/output
* bidirectional: sequential access in both directions
* random-access: efficient access to any element, input and output

The second argument when specifying a range is always one past the last value. Why?
* If we treat the last element special, it would be easy to accidentally ignore it.
* If the range was empty, how else would we mark the end?
* it allows us to compare iterators using only `==` and `!=`
* it provides a natural way to indicate when something is `out of range`.
