#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <ostream>
#include "student_info.h"
#include "grade.h"
#include "median.h"

using namespace std;


bool did_all_hw(const Student_info& s);
double grade_aux(const Student_info& s);
void write_analysis(ostream& out, const string& name,
        double method(const vector<Student_info>&),
        const vector<Student_info>& did,
        const vector<Student_info>& didnt);
double average(const vector<double>& v);
double average_grade(const Student_info& s);
double analysis(const vector<Student_info>& students);
double optimistic_median(const Student_info& s);
bool pgrade(Student_info& s);
bool fgrade(Student_info& s);


bool did_all_hw(const Student_info& s)
{
    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

bool pgrade(Student_info& s)
{
    return !fgrade(s);
}
bool fgrade(Student_info& s)
{
    return grade(s) < 60;
}

double average(const vector<double>& v)
{
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}


double average_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, average(s.homework));
}

double grade_aux(const Student_info& s)
{
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

// median of the nonzero elements of s.homework or 0 if no such elements exist
double optimistic_median(const Student_info& s)
{
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero),
            0);

    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}


template<class Fn>
double analysis(const vector<Student_info>& students, Fn grade)
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), grade);
    return median(grades);
}

void write_analysis(ostream& out, const string& name,
        double method(const Student_info&),
        const vector<Student_info>& did,
        const vector<Student_info>& didnt)
{
    out << name << ": median(did = " << analysis(did, method) <<
        ", median(didnt) = " << analysis(didnt, method) << endl;
}

int main()
{
    // students who did and didn't do all of their hw
    vector<Student_info> did, didnt;

    // read the student records and partition them
    Student_info student;
    while (read(cin, student)) {
        if (did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }

    // check that both groups contain data
    if (did.empty()) {
        cout << "No student did all the homework!" << endl;
        return 1;
    }
    if (didnt.empty()) {
        std::cout << "Every student did all the homework!" << std::endl;
        return 1;
    }

    // do the analysis
    write_analysis(cout, "median", grade_aux, did, didnt);
    write_analysis(cout, "average", average_grade, did, didnt);
    write_analysis(cout, "median of hw turned in", optimistic_median, did, didnt);

    return 0;
}

