#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>
using std::find_if;
using std::find;

#include <iterator>
using std::stable_partition;

#include <stdexcept>
using std::vector;

#include <ostream>
using std::ostream;

#include "student_info.h"
#include "grade.h"
#include "median.h"


bool did_all_hw(const Student_info& s);
double grade_aux(const Student_info& s);
double median_analysis(const vector<Student_info>& students);
void write_analysis(ostream& out, const string& name,
        double analysis(const vector<Student_info>&),
        const vector<Student_info>& did,
        const vector<Student_info>& didnt);
double average(const vector<double>& v);
double average_grade(const Student_info& s);
double average_analysis(const vector<Student_info>& students);
double optimistic_median(const Student_info& s);
double optimistic_median_analysis(const vector<Student_info>& students);
vector<Student_info> extract_students(vector<Student_info>& students,
        bool analysis_func(const Student_info&));
bool pgrade(Student_info& s);
bool fgrade(Student_info& s);


int main()
{
    // students who did and didn't do all of their hw
    vector<Student_info> did, didnt;

    // read the student records and partition them
    Student_info student;
    while (read(cin, student)) {
        did.push_back(student);
    }

    // separate out those who didn't do homework
    didnt = extract_students(did, did_all_hw);

    // test it
    for (std::vector<Student_info>::const_iterator i = did.begin(); i != did.end(); ++i) {
        cout << "did: " << i->name << " " << (i->homework).size() << endl; 
    }
    for (std::vector<Student_info>::const_iterator i = didnt.begin(); i != didnt.end(); ++i) {
        cout << "didnt: " << i->name << " " << (i->homework).size() << endl; 
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
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    write_analysis(cout, "median of homework turned in",
            optimistic_median_analysis, did, didnt);

    return 0;
}


bool did_all_hw(const Student_info& s)
{
    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}


double grade_aux(const Student_info& s)
{
    try {
        return grade(s);
    } catch (std::domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}


double median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades),
            grade_aux);
    return median(grades);
}


void write_analysis(ostream& out, const string& name,
        double analysis(const vector<Student_info>&),
        const vector<Student_info>& did,
        const vector<Student_info>& didnt)
{
    cout << name << ": median(did) = " << analysis(did) <<
        ", median(didnt) = " << analysis(didnt) << endl;
}


double average(const vector<double>& v)
{
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}


double average_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, average(s.homework));
}


double average_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades),
            average_grade);
    return median(grades);
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

double optimistic_median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades),
            optimistic_median);
    return median(grades);
}


vector<Student_info> extract_students(vector<Student_info>& students,
        bool extract_func(const Student_info&))
{
    vector<Student_info>::iterator iter = stable_partition(students.begin(),
            students.end(), extract_func);
    vector<Student_info> didnt_do_hw(iter, students.end());
    students.erase(iter, students.end());
    return didnt_do_hw;
}


bool pgrade(Student_info& s)
{
    return !fgrade(s);
}


bool fgrade(Student_info& s)
{
    return grade(s) < 60;
}
