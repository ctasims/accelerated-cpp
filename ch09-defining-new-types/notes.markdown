# Chapter 9: Defining new types

## Exercises
0. Done. 

1. Done. Just added call to `grade` and updated print.

2. We also have to change the `compare` function and references to it, because it only accepts `const` name values.

3. I simply removed the `try... catch` block and ran the compiled code with no hw inputs.

4. Just added if-statement with call to `valid` before computing grade.

5. done.

6. done.

7. Add it as a private member function and call it from inside read so it cannot be accessed externally. I would also place it in `Student_info.cpp` to show that it belongs with the other member functions.


## Notes

C++ has built-in types and class types. A **class type** lets us combine related values and functions into a single data structure so we can treat it as one entity.

It's good form to hide the implementation of a class, while providing a useful interface for coders to access.

The class definition goes in a header file, where we use fully-qualified names.

We use the scope operator `::` to define new member functions.
When accessing members inside a member function we do not need to qualify them.

We can add `const` after a function's parameter list to state that the function does not modify the internal state of the instance object.

**When to define function as member function:**
if the function changes the state of an object, it should be a member of that object.

Member functions defined inside a class definition will be inlined by the implementation to avoid function call overhead.

### Protection

Use the keywords `public` and `private` to restrict access to class members.
Note that if we define an object with `struct`, the default protection is public.
`class` sets the default protection to private.

**Use struct to define simple data structures whose innards we intend to expose.**

Use **accessor functions** to provide an interface to object members that we want to expose in an abstract way.


### Constructors
When no constructor is present, value- or default-initializing the object value- or -default-initializes each of its data members. This is done recursively.

**Every data member should have a sensible value at all times.** The role of a constructor is to ensure that objects are created with their data members in a sensible state.

**It's often a good idea to create two constructors: one that takes no arguments and yields an "empty" instance and one that takes the required arguments for a complete instance.**

Constructors have the same name as the class type and do not return anything.

Default constructor with constructor initializers:

    Class_name::Class_name(): member(value), member2(value) {}

Initialization sequence:
1. Memory is allocated to hold the object.
2. The object is initialized based on the constructor's initializer set.
3. The constructor body is executed.

**Give members a value with initializers, rather than in the body, to avoid duplication of effort.**
