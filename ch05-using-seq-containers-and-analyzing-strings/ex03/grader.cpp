#include <string>
using std::string;

#include <stdexcept>
using std::domain_error;

#include <iomanip>
using std::setprecision;

#include <ios>
using std::istream;
using std::streamsize;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
using std::sort;
using std::max;

#include "grade.h"
#include "Student_info.h"

// for reading from file
#include <fstream>

// for timing
#include <chrono>
#include <thread>

#include <vector>
typedef std::vector<Student_info> stu_container;
//#include <list>
//typedef std::list<Student_info> stu_container;


// predicate to determine whether a student failed
bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

// separate passing and failing students
stu_container extract_fails(stu_container students)
{
    stu_container fail;
    stu_container::iterator iter = students.begin();

    // invariant: elements [0, i) of students represent passing grades
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);  // point iter to next element
        } else {
            ++iter;
        }
    }
    return fail;
}

int main()
{
    stu_container students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store all the records, and find length of longest name
    std::ifstream infile("10000_students.txt");
    while (read(infile, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // alphabetize records
    //students.sort(compare);

    for (stu_container::const_iterator iter = students.begin();
            iter != students.end(); ++iter) {
        // write name, padded on the right to maxlen + 1 chars
        cout << iter->name
            << string(maxlen + 1 - iter->name.size(), ' ');

        // compute and write the grade
        try {
            double final_grade = grade(*iter);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }

        cout << endl;
    }

    return 0;
}

