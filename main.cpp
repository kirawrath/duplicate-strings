#include "sets.h"
#include "test.h"

int main()
{
    /* TEST 1 */
    {
        cout << "\nTEST 1\n\n";
        Test t("./tests/input.txt");
        t.print_all();

        cout << "duplicates test: " <<
            (t.test_duplicates(475,26) ? "OK" : "FAIL") << endl;

        vector<int> vec = {3,5,11,23,24,88,189};
        cout << "most repeated test: " <<
            (t.test_most_repeated(vec, 28) ? "OK" : "FAIL") << endl;

        vector<string> inv =
        {
            ",,,,",
            "A, B, C",
            "---",
            "This line should be ignored because it's not valid",
            ",",
            "50 41 87 95"
        };

        cout << "invalid test: " <<
            (t.test_invalids(inv) ? "OK":"FAIL") << endl;
    }
    {
        /* TEST 2 */
        cout << "\nTEST 2\n\n";
        Test t("./tests/input2.txt");
        t.print_all();

        cout << "\nDuplicates test: " <<
            (t.test_duplicates(0,4) ? "OK" : "FAIL") << endl;

        vector<int> vec = {};
        cout << "Most repeated test: " <<
            (t.test_most_repeated(vec, 0) ? "OK" : "FAIL") << endl;

        vector<string> inv =
        {
            "Hello NCR",
            "!@#$"
        };

        cout << "Invalid test: " <<
            (t.test_invalids(inv) ? "OK":"FAIL") << endl;
    }
    /* TEST 3 */
    {
        cout << "\nTEST 3\n\n";
        Test t("./tests/input3.txt");
        t.print_all();

        cout << "\nDuplicates test: " <<
            (t.test_duplicates(0,3) ? "OK" : "FAIL") << endl;

        vector<int> vec = {};
        cout << "Most repeated test: " <<
            (t.test_most_repeated(vec, 0) ? "OK" : "FAIL") << endl;

        vector<string> inv =
        {
            "1 2 3",
            "Numbers without commas?"
        };

        cout << "Invalid test: " <<
            (t.test_invalids(inv) ? "OK":"FAIL") << endl;
    }
    /* TEST 4 */
    {
        cout << "\nTEST 4\n\n";
        Test t("./tests/input4.txt");
        t.print_all();        

        cout << "\nDuplicates test: " <<
            (t.test_duplicates(10,2) ? "OK" : "FAIL") << endl;

        vector<int> vec = {0,1,2};
        cout << "Most repeated test: " <<
            (t.test_most_repeated(vec, 9) ? "OK" : "FAIL") << endl;

        vector<string> inv =
        {
            "0 1 2",
            "// 9 duplicates so far (not 10 nor 11)",
            "4,5,@",
            "just 2 unique"
        };

        cout << "Invalid test: " <<
            (t.test_invalids(inv) ? "OK":"FAIL") << endl;
    }

    if(Test::test_failed())
        cout << "\nTEST FAILED." << endl;
    else
        cout << "\nALL TESTS PASSED!" << endl;

    return 0;
}
