#include <stdexcept>
using std::domain_error;

#include <vector>
using std::vector;

#include "grade.h"
#include "median.h"
#include "Student_info.h"


// compute student's overall grade
double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
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

