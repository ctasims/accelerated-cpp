#include <vector>
#include <string>
#include <algorithm>
#include "Student_info.h"
#include "grade.h"


vector<Student_info> did, didnt;
Student_info student;


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
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}


double average(const vector<double>& v)
{
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}


double average_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, average(s.homework));
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


// one-pass solution, twice as fast as two-pass
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info>::iterator iter = stable_partition(students.begin(),
            students.end(), pgrade);
    vector<Student_info> fail(iter, students.end());
    students.erase(iter, students.end());
    return fail;
}


bool pgrade(Student_info& s)
{
    return !fgrade(s);
}


double analysis(
        const vector<Student_info>& students,
        double analysis_func(const Student_info& s))
{
    /*
     * Analyze grades using specified analysis function
     */
    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades),
            analysis_func);
    return median(grades);
}


void write_analysis(ostream& out, const string& name,
        //double analysis(const vector<Student_info>&),
        double analysis_func(const Student_info&),
        const vector<Student_info>& did,
        const vector<Student_info>& didnt)
{
    out << name << ": median(did = " analysis(did, analysis_func) <<
        ", median(didnt) = " << analysis(didnt, analysis_func) << endl;
}

