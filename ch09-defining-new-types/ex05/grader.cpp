#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <stdexcept>
#include <iomanip>
#include "Student_info.h"

using namespace std;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store the data
    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    // alphabetize the student records
    sort(students.begin(), students.end(), compare);
    char status;

    // write names and grades
    for (vector<Student_info>::size_type i = 0;
            i != students.size(); ++i) {
        cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');

        double final_grade = students[i].grade();
        if (final_grade >= 60)
            status = 'P';
        else
            status = 'F';
        streamsize prec = cout.precision();
        cout << setprecision(3) << status
            << setprecision(prec) << endl;
    }
    return 0;
}
