#ifndef TEST_YAY_CPP
#define TEST_YAY_CPP
#include "test.h"
bool Test::fail = false;

Test::Test(const char* file_name)
{
    ifstream file(file_name);
    string line;
    while( getline(file, line) )
    {
        sets.add_set(line);
    }
}
bool Test::my_return(bool ret)
{
    if(!ret)
        fail = true;
    return ret;
}
bool Test::test_duplicates(unsigned int expected_duplicates,
        unsigned int expected_unique)
{
    unsigned int dup, uni;
    sets.get_n_duplicates(dup, uni);
    return my_return((dup==expected_duplicates) and (expected_unique==uni));        
}
bool Test::test_most_repeated(vector<int> expected, unsigned int n_repeated)
{
    int ret;
    vector<int> s = sets.get_most_repeated_vec(ret);
    auto it1 = expected.begin();
    for(auto it0 = s.begin();
            (it0 != s.end()) && (it1 != expected.end());
            ++it0, ++it1)
    {
        if(*it0 != *it1)
            return false;
    }
    return my_return(ret == n_repeated);
}
bool Test::test_invalids(vector<string> expected)
{
    return my_return(expected == sets.get_invalids());
}
void Test::print_most_repeated()
{
    int times;
    string s = sets.get_most_repeated(times);
    cout << s << " repeated " << times << " times.\n";
}
void Test::print_invalid() 
{
    cout << "Invalid inputs:" << endl;
    auto& vec = sets.get_invalids();
    for(auto& i : vec )
        cout << i << endl;
    cout << "Total invalid lines: " << vec.size()<< endl;
}
void Test::print_n_duplicates()
{
    unsigned int dup, unique;
    sets.get_n_duplicates(dup, unique);
    cout << "Total duplicates: " << dup <<".\n";
    cout << "Total unique: " << unique << ".\n";
}
void Test::print_all()
{
    print_n_duplicates();
    print_most_repeated();
    print_invalid();
}
#endif
