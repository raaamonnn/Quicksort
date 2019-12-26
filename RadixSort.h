#ifndef QUICKSORT_RADIXSORT_H
#define QUICKSORT_RADIXSORT_H

#include <iostream>
#include<time.h>
#include<string>
#include<queue>
#include<vector>
using namespace std;
class RadixSort{
    // Get maximum value from array.
    string getMax_string(string arr[], int n)
    {
        string max = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > max)
                max = arr[i];
        return max;
    }

    // Count sort of arr[].
    void inc_countSort_string(string arr[], int n, int exp)
    {
        // Count[i] array will be counting the number of array values
        // having that 'i' digit at their (exp)th place.
        string *output = new string[n];
        int count[128] = { 0 };		// because maximum 128 ASCII possibilities
        int i;
        // Count the number of times each digit occurred at (exp)th place in every input.
        for (i = 0; i < n; i++)
            // similar to count[(arr[i] / exp) % 10] + 1 for integer type
            count[(int)arr[i].substr(0, exp).back()]++;

        // Calculating their cumulative count.
        for (i = 1; i < 128; i++)
            count[i] += count[i - 1];

        // Inserting values according to the digit '(arr[i].substr(0, exp).back())'
        // and fetched into count[(arr[i].substr(0, exp).back())].
        for (i = n - 1; i >= 0; i--)
        {
            cout << arr[i] << " ";
            output[count[(arr[i].substr(0, exp).back())] - 1] = arr[i];
            count[(int)(arr[i].substr(0, exp).back())]--;
        }
        cout << endl;

        // Assigning the result to the arr pointer of main().
        for (i = 0; i < n; i++)
            arr[i] = output[i];
    }
public:
    // FOR STRING
    // Sort arr[] of size n using Radix Sort.
    void radixsort_stringInc(string arr[], int n)
    {
        cout << "ORDER OF STRINGS EACH PASS\n";
        int exp;
        string m;
        m = getMax_string(arr, n);


        // Calling countSort() for digit at (exp)th place in every input.
        for (exp = m.length(); exp > 0; exp--)
            inc_countSort_string(arr, n, exp);
    }
};

#endif //QUICKSORT_RADIXSORT_H
