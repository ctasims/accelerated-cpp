# Chapter 00: Getting Started

## Exercises
0. See file `hello.cc`. (sf means see file).

1. `3+4;` adds the numbers together and then throws away the result.
It's a null statement.

2. sf.

3. sf. Looks like `\t` is treated as 3 spaces, while entering an actual tab (in Vim) is eight spaces.

4. sf. I manually printed each line of the program.
A better way would be to pipe the file contents to `std::cout` or echo them.

5. sf. Compiler throws an error:
*Expected initializer before 'std'*.
This is not a valid program because `main` requires braces to set the scope.

6. sf. Yes, this one is valid. It just has redundant scopes.
It compiles and runs fine.

7. sf. Not valid because the inner comment delimiters end the outer one prematurely, so the latter part of the comment is treated as code.

8. sf. This program does work because the `//` comment delimiter makes the rest of the line a comment, regardless of what it contains.

9. sf. I tried putting a `;` only but the program needs a `main` function.
I could remove the `return` and `int` type declaration because they will be inferred.

10. See file. A fun exercise!
The `#include` line errored, but everything else worked.
I think the `int` type declaration and the return value were inferred, though.
I'm surprised I can put the output operator, `<<` on a separate line.


## Notes
I had trouble getting my compiler to work because I was using `gcc` and not `g++`. Oops! C++ is not C!

`<iostream>` is a directive.

Curly braces create scope.

`std::cout` is the standard output stream.

*Manipulators* like `std::endl` modify a stream in some way.

`::` is the scope operator and is used to access things inside a namespace.

String literals may NOT span lines.

`include` directives must appear on their own line.
