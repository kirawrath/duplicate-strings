#include "sets.h"

class Test
{
    public:
    Test(const char* file_name)
    {
        ifstream file(file_name);
        string line;
        while( getline(file, line) )
        {
            sets.add_set(line);
        }
    }
    bool test_duplicates(unsigned int expected_duplicates,
            unsigned int expected_unique) const
    {
        unsigned int dup, uni;
        sets.get_n_duplicates(dup, uni);
        return ((dup==expected_duplicates) and (expected_unique==uni));        
    }
    bool test_most_repeated(vector<int> expected, unsigned int n_repeated)
    {
        int ret;
        vector<int> s = sets.get_most_repeated_vec(ret);
        auto it1 = expected.begin();
        for(auto it0 = s.begin();
                (it0 != s.end()) && (it1 != expected.end());
                ++it0, ++it1)
        {
            if(*it0!=*it1)
                return false;
        }
        return (ret == n_repeated);
    }
    bool test_invalids(vector<string> expected)
    {
        return expected == sets.get_invalids();
    }
    void print_most_repeated() const
    {
        int times;
        string s = sets.get_most_repeated(times);
        cout << s << "repeated " << times << " times.\n";
    }
    void print_invalid() 
    {
        cout << "Invalid inputs:" << endl;
        auto& vec = sets.get_invalids();
        for(auto& i : vec )
            cout << i << endl;
        cout << "Total invalid lines: " << vec.size()<< endl;
    }
    void print_n_duplicates() const
    {
        unsigned int dup, unique;
        sets.get_n_duplicates(dup, unique);
        cout << "Total duplicates: " << dup <<".\n";
        cout << "Total unique: " << unique << ".\n";
    }
    void print_all()
    {
        print_n_duplicates();
        print_most_repeated();
        print_invalid();
    }
    UniqueSets sets;
};

int main()
{
    Test t("./input.txt");
    t.print_all();        

    cout << "duplicates test: " <<
        (t.test_duplicates(475,27) ? "OK" : "FAIL") << endl;

    vector<int> vec = {3,5,11,23,24,88,189};
    cout << "most repeated test: " <<
        (t.test_most_repeated(vec, 29) ? "OK" : "FAIL") << endl;
    
    vector<string> inv =
    {
        ",,,,",
        "A, B, C",
        "---",
        "This line should be ignored because it's not valid",
        ","
    }

    cout << "invalid test: " <<
        (t.test_invalids(inv) ? "OK":"FAIL") << endl;

    return 0;
}
