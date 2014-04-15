#include <vector>
using std::vector;

#include <map>
using std::map;

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
    // map for mapping grade to letter grade
    const map<int, char> matched_grades = {
        {50, 'F'}, {60, 'D'}, {70, 'C'}, {80, 'B'}, {90, 'A'}, {100, 'A'}
    };

    map<char, vector<string>> students_by_grade;

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        // write name, padded on the right to maxlen + 1 chars
        //cout << students[i].name
            //<< string(maxlen + 1 - students[i].name.size(), ' ');

        // compute and write the grade
        try {
            double final_grade = grade(students[i]);
            // round to nearest 10
            double rounded_grade = final_grade - ((int)final_grade % 10);
            // compute letter grade
            char letter_grade;
            if (rounded_grade < 60) {
                letter_grade = matched_grades.at(50);
            } else {
                letter_grade = matched_grades.at(rounded_grade);
            }

            // record student's name to categorize by grade
            students_by_grade[letter_grade].push_back(students[i].name);

            //streamsize prec = cout.precision();
            //cout << setprecision(3) << final_grade
                //<< setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }

        //cout << endl;
    }

    // print # students per letter grade
    for (map<char, vector<string>>::const_iterator i=students_by_grade.begin();
            i != students_by_grade.end(); ++i) {
        cout << i->first << ' ' << i->second.size() << endl;
    }

    return 0;
}

