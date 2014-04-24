#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <stdexcept>
#include <iomanip>
#include "Student_info.h"

using namespace std;


string letter_grade(double grade)
{
    static const double numbers[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
    };

    static const char* const letters[] = {
        "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
    };

    // compute # of grades given size of array and of single elem
    static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);

    // given numeric grade, find and return associated letter grade.
    for (size_t i = 0; i < ngrades; ++i) {
        if (grade >= numbers[i])
            return letters[i];
    }
    return "?\?\?";
}

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

    // write names and grades
    for (vector<Student_info>::size_type i = 0;
            i != students.size(); ++i) {
        cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
        try {
            string final_grade = letter_grade(students[i].grade());
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}
