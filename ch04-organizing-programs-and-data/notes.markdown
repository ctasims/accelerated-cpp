# Chapter 4: Organizing programs and data

## Exercises
0. Done.

1. This will only work if `s.name.size()` returns an int. If it doesn't we should typecast it to an int, or perhaps pass a `compare` functions, if allowed.

2. sf.

3. sf. If we do not change the width, the numbers run together. Ugly! Instead, I use a function which calculates the length of a number, based on `log10`.

4. This doesn't seem to need any changes, besides converting types. Perhaps it wants me to print out squares of decimals in-between whole numbers? In that case I would use setprecision and would modify how I compute number lengths.

5. sf.

6. sf.

7. sf.

8. The returned value is being indexed and the element is a `double. So `f` must return a `vector<double>`.


## Notes

### 4.1 Organizing computations
C++ is **call by value**.
Parameters are created upon function call and destroyed when it returns.
They're local variables.

Throw exceptions to handle unexpected input.
`domain_error` for an arg outside the acceptable domain of values.
If a function doesn't handle a thrown exception, it will be passed along.

MK call a **reference** a synonym for an object, whilst using `&`.
I'm assuming they don't want to introduce pointers yet?

Defining a reference to a reference just creates another reference to the same object.

**Overload** a function by supplying a different argument list.
This allows us to have several different functions with the same name.

An `lvalue` denotes a nontemporary object. `sum/count` is temporary.

Arguments for non`const` parameters must be `lvalues`.
This is because those arguments will likely change, so passing a temporary object/value would be useless.

Use a reference and `const` when you don't want a function to copy its argument.
Don't worry about doing this for primitive types, though.
The overhead isn't an issue.

Rule of thumb: **avoid more than one side affect in a single statement.**
Throwing an exception is a side affect.

### 4.2 Organizing data

Create a type with custom data members using a `struct`:

    struct <type_name> {
        string name;
        double midterm;
        vector<double> homework;
        ...
    };

Pass a `predicate` function to `sort` to compare custom, non-numeric values.


### 4.3 Putting it all together
Use header files to allow for separate compilation.
In header files, declare the functions to share.
Never use `using` shortcut because it will propagate to whoever is using the header file.

To protect against loading headers multiple times, can use preprocessor variables and logic.

### 4.4
It can be useful to include a header file in the `.cpp` file.
This allows the compiler to check the return types and arguments of the given functions.
