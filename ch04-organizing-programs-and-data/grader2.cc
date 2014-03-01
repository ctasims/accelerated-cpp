#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <ios>
#include <iostream>
#include <algorithm>

using std::vector;
using std::istream;
using std::sort;
using std::string;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::streamsize;


// compute student's overall grade
double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}


// compute median of a vector<double>.
// Note that callin this function copies the entire argument vector.
double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    if (size == 0) {
        throw domain_error("median of an empty vector");
    }

    sort(vec.begin(), vec.end());

    vec_sz mid = size/2;
    return size % 2 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}


// compute student's overall grade from midterm and final exam grades
// and vector of hw grades.
// This function does not copy its argument because median does so for us.
double grade(double midterm, double final, const vector<double>& hw)
{
    if (hw.size() == 0) {
        throw domain_error("student has done no homework");
    }
    return grade(midterm, final, median(hw));
}


// read hw grades from input stream into vector<double>
istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        // get rid of previous contents
        hw.clear();

        // read hw grades
        double x;
        while (in >> x)
            hw.push_back(x);

        // clear the stream so input will work for next student
        in.clear();
    }
    return in;
}


int main()
{
    // ask for and read student's name
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // ask for and read midterm and final grades
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    // ask for homework grades
    cout << "Enter all your homework grades, "
        "followed by end-of-file: ";

    vector<double> homework;

    // read hw grades
    read_hw(cin, homework);

    // compute and generate final grade, if possible
    try {
        double final_grade = grade(midterm, final, homework);
        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3) << final_grade
            << setprecision(prec) << endl;
    } catch (domain_error) {
        cout << endl << "You must enter your grades. "
            "Please try again." << endl;
        return 1;
    }
    return 0;
}
