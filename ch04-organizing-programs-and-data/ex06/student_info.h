#ifndef GUARD_student_info
#define GUARD_student_info

// student_info.h header file
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>


struct Student_info {
    std::string name;
    double grade;
};


bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif

