# Chapter 2: Looping and Counting

## Exercises
0. sf.

1. sf.

2. sf.

3. sf.

4. sf. I check if we're on a blank row, then add a string of spaces of the correct length, then increment c. Hacky, but it works.

5. Done, and they're all automated! Can draw shapes of any size!

6. A simple loop that prints 1 through 10.

7. sf. 

8. sf.

9. sf.

10. line 4: `using-declaration` creates synonym of the call for convenience, inside this scope.
The later `std` calls are outside that scope so we must use them to access namespace.



## Notes

How should we handle brittle programs? Automate.
Rewrite the framed hello program so it automates the padding and layout.

`while` structure is familiar.
Can also write it: `while (condition) statement`

We have access to `increment` operator.

To understand a `while` loop:
* remember that its condition is false when it finishes.
* Write an `invariant` which asserts what will be true each time the condition is tested.
It's true before we start, at end of each iteration, and at iteration n + 1.

*The general idea is to find an invariant that states a relevant property of the variables that the loop involves (we have written r rows), and to use the condition to ensure that when the loop completes, those variables will have useful values (r == rows). The loop body's job is then to manipulate the relevant variables so as to arrange for the condition to be false eventually, while maintaining the truth of the invariant.*

Use `string::size_type` when storing the size of a string.
Note that this type is `unsigned` because it cannot be negative.

`==` and `||` have lower precedence than arithmetic operators.
`||` is evaluated with *short-circuit evaluation* so if the left operand is true, the right operand is ignored.

Use `using-declaration`s to import from a namespace, i.e. create a synonym.

Use asymmetric ranged like `[m, n)` because we can easily calculate the # of elements: `n - m`.

Arithmetic conversion attempt to preserve precision:
* smaller types to larger
* signed to unsigned

