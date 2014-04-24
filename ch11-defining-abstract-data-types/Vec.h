#ifndef GUARD_VEC_H
#define GUARD_VEC_H

#include <memory>


template <class T> class Vec {
    public:
        // interface
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef size_t size_type;
        typedef T value_type;

    private:
        // implementation
        iterator data;  // first element in Vec
        iterator avail;  // pointer to one past the last constructed elem
        iterator limit;  // one past the last elem in Vec

        std::allocator<T> alloc;  // object to handle memory allocation

        // allocate and initialize the underlying array;
        void create();
        void create(size_type, const T&);
        void create(const_iterator, const_iterator);

        // destroy elems in the array and free the memory
        void uncreate();

        // support functions for push_back
        void grow();
        void unchecked_append(const T&);


    public:
        ~Vec() { uncreate(); }
        Vec (const Vec& v) { create(v.begin(), v.end()); }  // copy constructor
        Vec& operator=(const Vec&);
        Vec() { create(); }
        explicit Vec(size_type n, const T& val = T()) { create(n, val); }

        // return reference so user can write to it as well
        T& operator[](size_type i) { return data[i]; }
        // return a reference to avoid copying the element
        const T& operator[](size_type i) const { return data[i]; }

        size_type size() const { return avail - data; }

        iterator begin() { return data; }
        const_iterator begin() const { return data; }

        iterator end() { return limit; }
        const_iterator end() const { return limit; }

        void push_back(const T& val) {
            if (avail == limit)
                grow();
            unchecked_append(val);
        }
};


#endif
