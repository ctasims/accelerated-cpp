// source file for median function
# include <algorithm>
using std::sort;

#include <stdexcept>
using std::domain_error;

#include <vector>
using std::vector;


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
