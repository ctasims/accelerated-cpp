import random
import string

"""
Generate dummy files containing sample student grade data
"""
def gen_data(n, filename):
    with open(filename, 'w') as mfile:
        for i in range(n):
            name = ''.join(random.choice(string.ascii_lowercase) for _ in range(6))
            grades = [random.choice(range(100)) for grd in range(5)]
            grades.insert(0, name)
            line = ' '.join(str(e) for e in grades)
            line += '\n'
            mfile.write(line)

if __name__ == "__main__":
    gen_data(10, '10_students.txt')
    gen_data(1000, '1000_students.txt')
    gen_data(10000, '10000_students.txt')
