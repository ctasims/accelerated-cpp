# Chapter 1: Working with strings

## Exercises

0. See files (sf).

1. The first is a valid definition and explicit initialization.
The second is also valid because the `+` operator executes left to right.
The string and string literal are concatenated, then the result of those (a string) is concatenated with the next string literal. sf.

2. The `message` definition is not valid because it attempts to concatenate two string literals together.

3. It is valid. The `s` variable is local-scoped in each set of braces.
After the first block closes, it is cleared.
It is defined again in the next block. sf.

4. This program is valid (sf).
The inner `s` declaration hides the outer one, so the output is the same as in exercise 3.

Adding a `;` changes nothing.
I believe that's interpreted as a null statement.

5. This program is not valid because `x` is out of scope once the final `cout` is hit.
This is because it is destroyed after the inner scope ends.
To fix this, we need to either declare it in the outer scope, or move the `cout` call inside the inner scope.

6. Perhaps only the first name will be stored because `cin` will stop once it hits whitespace?
Just ran it. Interesting! So the latter term is stored in the buffer, then?
It is then used in the next line automatically.


## Notes

### 1.1 Input
`std::cin` to get input from primary input source (command-line).

A variable is a *named object*.
Variables defined inside a function are *local variables*.
They are destroyed on function exit.
I'm assuming they're automatic and exist on the stack frame.

Output operations are expensive so the system uses a *buffer* to build up output.
Output is then flushed when: it's full, it's about to read input, or we tell it to.
It's important to flush the buffer at the right time.


### 1.2 Framing a name
`const` to designate a variable as constant.

`+` to concatenate two strings or a string and a string literal (but not two string literals).
String literals like `"Hello"` are just an array of characters - `const char [N]`.
Usually these are just pointers to the first element.
So adding two of them is meaningless.
However, we can concatenate them by placing them together:
`"Hello" " world"`.

`wchar_t` type for unicode-ish, "wide" characters.
