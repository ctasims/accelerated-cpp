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
    vector<Student_info> passes;
    vector<Student_info> fails;

    // write names and grades
    for (vector<Student_info>::size_type i = 0;
            i != students.size(); ++i) {
        double final_grade = students[i].grade();
        if (final_grade >= 60)
            passes.push_back(students[i]);
        else
            fails.push_back(students[i]);
    }
    cout << endl << endl;

    cout << "Students who passed:" << endl;
    for (vector<Student_info>::size_type i = 0;
            i != passes.size(); ++i) {
        cout << passes[i].name() << string(maxlen + 1 - passes[i].name().size(), ' ');
    }

    cout << "Students who failed:" << endl;
    for (vector<Student_info>::size_type i = 0;
            i != fails.size(); ++i) {
        cout << fails[i].name() << string(maxlen + 1 - fails[i].name().size(), ' ');
    }
    cout << endl << endl;

    return 0;
}
