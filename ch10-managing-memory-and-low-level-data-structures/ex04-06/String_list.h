#ifndef String_list_h
#define String_list_h

#include <string>
#include <list>


class String_list {
    public:
        String_list();
        String_list(std::list<std::string>);

        bool valid() const { return !strings.empty(); }
        int size() const { return strings.size(); }

        std::string front() const;
        std::string back() const;
        void push_front(std::string);
        void push_back(std::string);
        void pop_front();
        void pop_back();

        typedef std::list<std::string>::iterator iter;
        iter begin() { return strings.begin(); }
        iter end() { return strings.end(); }

    private:
        std::list<std::string> strings;
};


#endif
