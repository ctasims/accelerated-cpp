#include <list>
using std::list;

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


// predicate to determine whether a student failed
bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

// separate passing and failing students
list<Student_info> extract_fails(list<Student_info>& students)
{
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();

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
    list<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store all the records, and find length of longest name
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // alphabetize records
    students.sort(compare);

    for (list<Student_info>::const_iterator iter = students.begin();
            iter != students.end(); ++iter) {
        // write name, padded on the right to maxlen + 1 chars
        cout << iter->name
            << string(maxlen + 1 - students[i].name.size(), ' ');

        // compute and write the grade
        try {
            double final_grade = grade(students[i]);
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

