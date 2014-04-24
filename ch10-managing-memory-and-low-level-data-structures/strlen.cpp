// Example implementation of standard-library function
size_t strlen(const char* p)
{
    site_t size = 0;
    while (*p++ != '\0')
        ++size;
    return size;
}
