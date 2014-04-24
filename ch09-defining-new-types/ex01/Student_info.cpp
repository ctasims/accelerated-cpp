#include "Student_info.h"
#include "median.h"
#include "grade.h"

using namespace std;

Student_info::Student_info(): midterm(0), final(0), final_grade(0) {}

Student_info::Student_info(istream& is) { read(is); }


// read hw grades from input stream into vector<double>
istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        // get rid of previous contents
        hw.clear();

        // read hw grades
        double x;
        while (in >> x) {
            hw.push_back(x);
        }

        // clear the stream so input will work for next student
        in.clear();
    }
    return in;
}

istream& Student_info::read(istream& in)
{
    in >> n >> midterm >> final;
    read_hw(in, homework);
    final_grade = grade();
    return in;
}

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name() < y.name();
}

double Student_info::grade() const {
    return ::grade(midterm, final, homework);
}

