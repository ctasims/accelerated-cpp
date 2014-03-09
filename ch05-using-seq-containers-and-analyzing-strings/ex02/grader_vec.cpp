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

// for reading from file
#include <fstream>

// for timing
#include <chrono>
#include <thread>


//void f()
//{
    //std::this_thread::sleep_for(std::chrono::seconds(1));
//}


// predicate to determine whether a student failed
bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

// separate passing and failing students
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();

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

int grade_with_vector()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store all the records, and find length of longest name
    std::ifstream infile("10_students.txt");
    while (read(infile, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // alphabetize records
    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::const_iterator iter = students.begin();
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


int main()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    grade_with_vector();
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "f() took "
        << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
        << " milliseconds\n";

    return 0;
}

