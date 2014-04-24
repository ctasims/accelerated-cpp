#include "Student_info.h"
#include "median.h"
#include "grade.h"
#include <algorithm>

using namespace std;

Student_info::Student_info(): midterm(0), final(0) {
    ++num_create;
}

Student_info::Student_info(istream& is) {
    ++num_create;
    read(is);
}

// copy
Student_info::Student_info(const Student_info& st) {
    ++num_copy;
    midterm = st.midterm;
    final = st.final;
    //homework = std::copy(st.homework.begin(), st.homework.end());
    homework = st.homework;
}

// assignment
Student_info& Student_info::operator= (const Student_info& rhs) {
    ++num_asmt;
    
    // check for self-assignment
    if (&rhs != this) {
        final = rhs.final;
        midterm = rhs.midterm;
        //homework = copy(rhs.homework.begin(), rhs.homework.end());
        homework = rhs.homework;
    }
    return *this;
}


// destructor
Student_info::~Student_info() {
    ++num_destr;
    delete(&homework);
}


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
    return in;
}

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name() < y.name();
}

double Student_info::grade() const {
    return ::grade(midterm, final, homework);
}

double Student_info::median_grade() const {
    return ::grade(midterm, final, median(homework));
}

double Student_info::average_grade() const {
    double average = std::accumulate(homework.begin(), homework.end(), 0.0) /
        homework.size();
    return ::grade(midterm, final, average);
}
