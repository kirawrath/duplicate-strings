#ifndef UNIQUE_SETS_H
#define UNIQUE_SETS_H

#include<iostream>
#include<set>
#include <locale>
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <map>
#include "radix.h"
#include "tree.h"
class UniqueSets
{
    public:
    UniqueSets();
    ~UniqueSets();
    // Implementation of item 1-a
    bool add_set(string line);
    // Implementation of item 1-b
    void get_n_duplicates(unsigned int& duplicates, unsigned int& unique) const;
    // Implementation of item 1-c
    string get_most_repeated( int& n_repeated ) const;
    vector<int> get_most_repeated_vec( int& n_repeated );
    // Implementation of item 1-d
    vector<string>& get_invalids();

    private:
    void print_vec(const vector<int>& v) const;
    inline bool is_integer(const std::string &s);
    void populate_vector(string line, vector<int>& s);
    int invalid_count() const;

    vector<string> invalid_str;
    Node* root;
    unsigned int n_duplicated, n_unique;
    string most_frequent;
    int most_frequent_n;
};

#endif
