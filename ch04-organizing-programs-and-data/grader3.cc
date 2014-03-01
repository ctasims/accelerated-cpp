#include <vector>
using std::vector;

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


int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store all the records, and find length of longest name
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // alphabetize records
    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        // write name, padded on the right to maxlen + 1 chars
        cout << students[i].name
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

