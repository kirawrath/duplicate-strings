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
        n_duplicated++;
    else
        n_unique++;
    if( n_added > most_frequent_n )
    {
        most_frequent = line;
        most_frequent_n = n_added;
    }
    return (n_added == 1);
}

void UniqueSets::print_vec(const vector<int>& v) const
{
    for(auto& i : v)
        cout << i << " ";
    cout << endl;
}
vector<string>& UniqueSets::get_invalids()
{
    return invalid_str;
}
string UniqueSets::get_most_repeated( int& number_repeated ) const
{
    number_repeated = most_frequent_n;
    return most_frequent;
}
vector<int> UniqueSets::get_most_repeated_vec( int& number_repeated )
{
    number_repeated = most_frequent_n;
    vector<int> vec;
    populate_vector(most_frequent, vec);
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
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
        return false;

    char* p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}
void UniqueSets::populate_vector(string line, vector<int>& s)
{
    const char c[3] = " ,";
    char *token;
    char* str = new char[line.size() + 1];
    int i;
    for(i=0; i<line.size(); ++i)
        str[i] = line[i];
    str[i] = '\0';

    token = strtok(str, c);
    while( token != NULL ) 
    {
        if(is_integer(token))
        {
            s.push_back(atoi(token));
        }
        else
        {
            free(str);
            s.clear();
            break;
        }
        token = strtok(NULL, c);
    }
}
int UniqueSets::invalid_count() const
{
    return invalid_str.size();
}

#endif
