# Chapter 7: Using associative containers

## Exercises
0. done.

1. done.

2. done.

3. done.

4. done.

5. done.

6. done.

7. done.

8. done.

9. done. These were all pretty straightforward.


## Notes

Vectors and lists are ideal for iteration and insertion/deletion.
But **associative containers** like maps are great for efficient lookups.

* Maps are comprised of key-value pairs where a key maps to a value.  
* A map key must be something we can compare.  
* indexing into a map at a nonexistent pair will create that k-v pair.
* with a map iterator `it`, use `it->first` and `it->second` to access the key and value.

C++ libs often use a balanced self-adjusting tree structure to implement associative containers.

C++ supports default arguments in function args.

C++ supports function recursion!

The `rand` function is only pseudo-random.

Hash tables are different than maps - they rely on a hash function for handling unique k-v pairs and do not order their contents in a reliable way.
