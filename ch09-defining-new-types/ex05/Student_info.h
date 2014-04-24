#ifndef Student_info_h
#define Student_info_h

#include <string>
#include <vector>
#include <istream>
#include <stdexcept>


class Student_info {
    public:
        // interface goes here
        Student_info();
        Student_info(std::istream&);
        std::string name() const { return n; }
        std::istream& read(std::istream&);
        double grade() const;

    private:
        // implementation goes here
        std::string n;
        double midterm, final;
};

bool compare(const Student_info&, const Student_info&);

#endif
