#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;


double average(const vector<double>& nums) {
    vector<double>::size_type sz = 0;
    double sum = 0;


    for (sz = 0; sz != nums.size(); sz++) {
        sum += nums[sz];
    }
    return sum / sz;
}


int main() {
    vector<double> nums;
    double num;

    while (cin >> num)
        nums.push_back(num);
        ;

    cout << "Average: " << average(nums) << endl;

    return 0;
}
