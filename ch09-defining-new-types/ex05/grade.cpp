#include <stdexcept>
using std::domain_error;

#include <vector>
using std::vector;

#include "grade.h"
#include "Student_info.h"


// compute student's overall grade
double grade(double midterm, double final)
{
    return 0.4 * midterm + 0.6 * final;
}

