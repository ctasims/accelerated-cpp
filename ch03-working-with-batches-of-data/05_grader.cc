#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::sort;

int main()
{
    vector<string> names;
    vector<double> grades;
    int stu;

    for (stu=0; stu < 5; stu++) {
        // get student's name
        cout << "Please enter the student's name: ";
        string name;
        cin >> name;
        names.push_back(name);

        // ask for and read midterm and final grades
        cout << "Please enter 5 grades for "<< name << ": ";

        double grade;
        int count = 0;
        double average = 0;
        double sum = 0;

        // invariant: average is the average grade up to this point
        for (int j=0; j < 5; j++) {
            cin >> grade;
            sum += grade;
            count++;
            average = sum / count;
        }

        grades.push_back(average);
    }

    // write the result
    double grade;
    string name;
    streamsize prec = cout.precision();
    cout << setprecision(3);
    for (stu=0; stu < names.size(); stu++) {
        name = names[stu];
        grade = grades[stu];
        cout << "Final grade for "<< name << " is "
            << grade
            << endl;
    }
    cout << setprecision(prec);

    return 0;
}

