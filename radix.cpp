// C++ implementation of Radix Sort
// http://www.geeksforgeeks.org/radix-sort/
#include<vector>
#include"radix.h"
using namespace std;

namespace radix
{

int getMax(int arr[], int n)
{
    if(!n) return 0;
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
 
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void neg_radix_sort(int arr[], int n)
{
    vector<int> neg;
    vector<int> pos;
    for(int i=0; i<n; ++i)
    {
        if(arr[i] < 0)
            neg.push_back( - arr[i] );
        else
            pos.push_back(   arr[i] );
    }
    if(neg.size()>0)
        radixsort(&neg[0], neg.size());
    if(pos.size()>0)
        radixsort(&pos[0], pos.size());
    
    for(int i=0; i < neg.size(); ++i)
        arr[i] = -neg[ neg.size() - i -1 ];

    for(int i = neg.size(); i<n; ++i)
        arr[i] = pos[ i - neg.size() ];
}

};
