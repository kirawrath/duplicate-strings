#ifndef UNIQUE_SETS_CPP
#define UNIQUE_SETS_CPP

#include "sets.h"
using namespace std;

UniqueSets::UniqueSets( )
{
    root = new Node(0);
    n_duplicated = n_unique = most_frequent_n = 0;
}
UniqueSets::~UniqueSets()
{
    delete root;
}
bool UniqueSets::add_set(string line)
{
    vector<int> s;
    if(line.back() == '\n') // discard \n
        line.pop_back();
    if(line.back() == '\r') // damn windows
        line.pop_back();
    populate_vector(line, s);
    if(s.empty())
    {
        invalid_str.push_back(line);
        return false;
    }
    radix::radixsort(&s[0], s.size());
    
    int n_added = root->add_path(s);
    if(n_added > 1) // First time adding this string?
    {
        n_duplicated++;
        if( n_added > most_frequent_n )
        {
            most_frequent = line;
            most_frequent_n = n_added;
        }
    }
    else
        n_unique++;
    return (n_added == 1);
}

vector<string>& UniqueSets::get_invalids()
{
    return invalid_str;
}
string UniqueSets::get_most_repeated( int& number_repeated ) const
{
    if(most_frequent_n > 1)
        number_repeated = most_frequent_n-1;
    else
        number_repeated = 0;
    return most_frequent;
}
vector<int> UniqueSets::get_most_repeated_vec( int& number_repeated )
{
    vector<int> vec;
    number_repeated = most_frequent_n; 
    if(most_frequent_n==0)
        return vec;
    number_repeated--; // 5 equal sets means 1 unique and 4 duplicate, so we decrement 1 here.
    populate_vector(most_frequent, vec);
    if(vec.size() > 1)
        radix::radixsort(&vec[0], vec.size());
    return vec;
}
void UniqueSets::get_n_duplicates(unsigned int& duplicates, unsigned int& unique) const
{
    duplicates = n_duplicated;
    unique = n_unique;
}
inline bool UniqueSets::is_integer(const std::string &s)
{
    // I'm not sure if I should handle signs -/+
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
        return false;

    char* p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}
/* Why am I using the ol' strtok here?
 * Well, long story short, I was running into problems using ifstringstream, so at one point
 * I got so upset that I just switched to strtok, but only after I did this, I realized that
 * the problem was the lame window's line-endings like \r\n instead of just \n.
 * I could have moved back to ifstringstream, but there is no point if this is already working.
 * */
void UniqueSets::populate_vector(string line, vector<int>& s)
{
    if(line.empty())
        return;
    const char c[2] = ",";
    char *token;
    char* str = new char[line.size() + 1];
    int i;
    for(i=0; i<line.size(); ++i)
        str[i] = line[i];
    str[i] = '\0';

    token = strtok(str, c);
    while( token != NULL ) 
    {
        if(token[0]==' ')
            ++token;
        if(is_integer(token))
        {
            s.push_back(atoi(token));
        }
        else
        {
            s.clear();
            break;
        }
        token = strtok(NULL, c);
    }
    free(str);
}

#endif
