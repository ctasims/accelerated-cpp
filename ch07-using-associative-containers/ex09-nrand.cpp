// return a random integer in the range [0, n)
// accounts for any value of n, even those bigger than RAND_MAX
int nrand(int n)
{
    if (n <= 0)
        throw domain_error("Argument to nrand is out of range");

    int largest_num, n2;
    int largest_num = (n > RAND_MAX) ? n : RAND_MAX;
    int n2 = (n > RAND_MAX) ? RAND_MAX : n;

    const int bucket_size = largest_num / n2;
    int r;

    do r = rand() / bucket_size;
    while (r >= n2);

    return r;
}

