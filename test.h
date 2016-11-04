#ifndef TEST_YAY_H
#define TEST_YAY_H
#include "sets.h"
class Test
{
    public:
    Test(const char* file_name);
    bool my_return(bool ret);
    bool test_duplicates(unsigned int expected_duplicates,
            unsigned int expected_unique);
    bool test_most_repeated(vector<int> expected, unsigned int n_repeated);
    bool test_invalids(vector<string> expected);
    void print_most_repeated();
    void print_invalid() ;
    void print_n_duplicates();
    void print_all();

    static bool test_failed()
    {
        return fail;
    }

    private:
    UniqueSets sets;
    static bool fail;
};

#endif
