// source file for Student_info-related functions
#include "student_info.h"

using std::vector;
using std::istream;
using std::string;


// read hw grades from input stream into vector<double>
istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        // get rid of previous contents
        hw.clear();

        // read hw grades
        double x;
        while (in >> x)
            hw.push_back(x);

        // clear the stream so input will work for next student
        in.clear();
    }
    return in;
}


istream& read(istream& is, Student_info& s)
{
    // read and store student's name, midterm and final grades
    is >> s.name >> s.midterm >> s.final;

    read_hw(is, s.homework);  // read and store hw grades
    return is;
}


bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}
