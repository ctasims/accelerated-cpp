#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <ostream>
#include "Student_info.h"
#include "grade.h"
#include "median.h"

using namespace std;


bool did_all_hw(const Student_info& s);
double grade_aux(const Student_info& s);
void write_analysis(ostream& out, const string& name,
        double method(const vector<Student_info>&),
        const vector<Student_info>& did,
        const vector<Student_info>& didnt);
double average_grade(const Student_info& s);
double analysis(const vector<Student_info>& students);
double optimistic_median(const Student_info& s);
bool pgrade(Student_info& s);
bool fgrade(Student_info& s);


bool did_all_hw(const Student_info& s)
{
    return s.valid();
}

bool pgrade(Student_info& s)
{
    return !fgrade(s);
}
bool fgrade(Student_info& s)
{
    return s.grade() < 60;
}

double average_grade(const Student_info& s)
{
    return s.average_grade();
}

double grade_aux(const Student_info& s)
{
    return s.grade();
}

// median of the nonzero elements of s.homework or 0 if no such elements exist
double optimistic_median(const Student_info& s)
{
    return s.median_grade();
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
    out << name << ": median(did = " << analysis(did, method) << endl;
}

int Student_info::num_asmt = 0;
int Student_info::num_copy = 0;
int Student_info::num_destr = 0;
int Student_info::num_create = 0;

int main()
{

    // students who did and didn't do all of their hw
    vector<Student_info> did, didnt;

    // read the student records and partition them
    Student_info student;
    while (student.read(cin)) {
        if (did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }

    // check that both groups contain data
    //if (did.empty()) {
        //cout << "No student did all the homework!" << endl;
        //return 1;
    //}
    //if (didnt.empty()) {
        //std::cout << "Every student did all the homework!" << std::endl;
        //return 1;
    //}

    // do the analysis
    write_analysis(cout, "median", grade_aux, did, didnt);
    cout << "Created: " << Student_info::num_create << endl;
    cout << "Copied: " << Student_info::num_copy << endl;
    cout << "Destroyed: " << Student_info::num_destr << endl;
    cout << "Assigned: " << Student_info::num_asmt << endl;
    write_analysis(cout, "average", average_grade, did, didnt);
    cout << "Created: " << Student_info::num_create << endl;
    cout << "Copied: " << Student_info::num_copy << endl;
    cout << "Destroyed: " << Student_info::num_destr << endl;
    cout << "Assigned: " << Student_info::num_asmt << endl;
    write_analysis(cout, "median of hw turned in", optimistic_median, did, didnt);
    cout << "Created: " << Student_info::num_create << endl;
    cout << "Copied: " << Student_info::num_copy << endl;
    cout << "Destroyed: " << Student_info::num_destr << endl;
    cout << "Assigned: " << Student_info::num_asmt << endl;

    return 0;
}


