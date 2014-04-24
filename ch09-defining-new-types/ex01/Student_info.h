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
        bool valid() const { return !homework.empty(); }
        std::istream& read(std::istream&);
        double grade() const;
        double final_grade;

    private:
        // implementation goes here
        std::string n;
        double midterm, final;
        std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);

#endif
