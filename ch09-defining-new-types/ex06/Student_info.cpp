#include "Student_info.h"
#include "grade.h"

using namespace std;

Student_info::Student_info(): midterm(0), final(0) {}

Student_info::Student_info(istream& is) { read(is); }


istream& Student_info::read(istream& in)
{
    in >> n >> midterm >> final;
    return in;
}

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name() < y.name();
}

double Student_info::grade() const {
    return ::grade(midterm, final);
}

