# Chapter 11: Defining abstract data types

## Exercises
0. Done.

1. 

2. 

3. 

4. 

5. Might be done. I instrumented the `Student_info` class but I'm unsure how to do the analysis based on Chapter 6 exercises. My analysis was uninformative.

6. 

7. (med)

8. (hard)

9. (med)



## Notes
Always handle actions like assignment, copying, deletion, etc. of objects.

When designing a class, begin with the interface.
It can be helpful to think about what users will do with the class.

A **template class** can be used to create a family of types that only differ in the types used in the specified parameter list.

    template <class T> class Vec {
        public:
          // interface
        private:
          // implementation
    };

The keyword `explicit` forces the compiler to only use the constructor when it is expressly invoked.

The type `value_type` defines the type of objects held in a container.

Define an overloaded operator like so: `operator[]` with the correct symbols.
Pass the correct arguments to the overloaded function.
If it is a member function, it will also have access to the instance.

### 11.3 Copy control
The compiler synthesizes definitions for actions like assignment if we do not provide them.
The synthesized default constructor recursively initializes each data member in the same way the instance object was initialized: default-, value-...



The **copy constructor** takes an instance of the class as input:

    <Classname> (class_instance);

For assignment, overload the assignment operator:

    Vec& operator=(const Vec&);

Remember to handle self-assignment, and to take care of the lhs!

The `this` keyword is valid inside a member function and is a pointer to the instance object.

**When we use `=` to give an initial value to a variable, we are invoking the copy constructor. When we use it in an assignment expression, we're calling `operator=`.**
Assignment obliterates a previous value; copying never does.
Constructors control initializiation while the `operator=` function always controls assignment.

**Destructors** carry out the deletion and cleanup of an object.

    ~Vec() { ... };

**Rule of three: if your class needs a destructor, it probably needs a copy constructor and an assignment operator as well.**

### 11.4 Dynamic Vecs
It's important to find ways to trim down expensive operations, like copying memory.
E.g. when dynamically allocating a new array, allocate for more than is needed so allocation isn't required on every call for expansion.

### 11.5 Flexible memory management
The `new` operate allocates *and* initializes memory.
The `<memory>` header provides `allocater<T>`, which can allocate a block of uninitialized memory.

We can use a class invariant similar to how we used a loop invariant - to provide true statements when the object is constructed.
