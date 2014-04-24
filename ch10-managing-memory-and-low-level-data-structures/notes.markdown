# Chapter 10: Managing memory and low-level data structures

## Exercises
0. done.

1. done.

2. done. Had to get help on how to pass correct value type, and to just pass iterators. Easy once I saw the trick.

3. done.

4. See ex04-06. This was an awkward problem because it basically required wrapping `list`.

5. ditto.

6. ditto.




## Notes

### 10.1 Pointers and arrays
A **pointer** represents an address in memory. Same as C. (This part is mostly review.)
`&p` yields an address, `*p` dereferences a pointer.

Initialize a pointer with value 0 provides a `null pointer`.
We can pass pointers to functions and use the pointer to call the function.

    int (*fp)(int);

says our function `fp` takes an int and returns an int.
**Any use of a function that is not a call is assumed to be taking its address.**

An **array** is a built-in container that lays out its members contiguously in memory.
An array variable is really just a pointer to its first element.

Pointer arithmetic lets us modify pointers using integers to refer to different elements.
Use `ptrdiff_t` type to represent the difference between pointers.

We can also use `p[n]` to index into a pointer's array, to get the actual element.

### 10.2 String literals revisited
Review of character arrays from C.  
Use `size_t` type for size of an array.

### 10.3 Initializing arrays of character pointers
We can initialize an array of character pointers by giving a sequence of string literals.

Use `sizeof` to determine the size of its argument in bytes.

### 10.4 Arguments to main
Pass command-line arguments to main with:

    int main(int argc, char** argv)

Where `argc` is the number of arguments, including the script name,
and `argv` is a pointer to an array of char pointers, one for each arg.

### 10.5 Reading and writing files
Use the standard error stream, `cerr`, to immediately write out.
Use the logging stream `clog` to write out similarly to how `cout` is buffered.

Use `ifstream` and `ofstream` objects from `<fstream>` for working with files.
We must refer to the filename with a null-terminated character array.
If we have a string, use `str.c_str()`.

### 10.6 Three kinds of memory management
We can keep local variables in existence with `static` allocation.

Use dynamic allocation with `new` and `delete` to create and manage objects on the heap.
Don't forget to add `[]` if handling an array!
