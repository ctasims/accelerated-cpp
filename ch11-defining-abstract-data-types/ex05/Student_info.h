#ifndef Student_info_h
#define Student_info_h

#include <string>
#include <vector>
#include <istream>
#include <stdexcept>


class Student_info {
    private:
        // implementation
        std::string n;                  // name of student
        double midterm, final;
        std::vector<double> homework;

    public:
        // measuring
        static int num_create;
        static int num_copy;
        static int num_asmt;
        static int num_destr;

        // constructors
        Student_info();
        Student_info(std::istream&);

        // copy constructor
        Student_info (const Student_info& st);

        // assignment
        Student_info& operator=(const Student_info&);

        // destructor
        ~Student_info();

        std::string name() const { return n; }
        bool valid() const { return !homework.empty(); }
        std::istream& read(std::istream&);
        double grade() const;
        double median_grade() const;
        double average_grade() const;

};

bool compare(const Student_info&, const Student_info&);

#endif
