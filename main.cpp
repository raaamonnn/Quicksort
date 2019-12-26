//1) alwasys chose the firsst element of the array
//3) always choose a random element
// 2) alwas choose the middle element

#include "QuickSort.h"
#include "RadixSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <time.h>
using namespace std;
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
//	int *arr = createOrderedArray(3000);
//    int arr[8] = {110, 5, 10,3 ,22, 100, 1, 23}; // need a function to create 3000,5000,10000 values in array



    //****FOR RANDOM ARRAY WITH SIZE 3000
    //first pivot
    int size = 10000;
    cout << "*** ARRAY SIZE: " << size << " ***"<<endl;
    int arr3000[size];
    random_device rd;
    default_random_engine dre(rd());
    uniform_int_distribution<int> uid(0, 9); //GENERATES AN ARRAY WITH RANDOM NUMBERS


    generate(arr3000, arr3000 + sizeof(arr3000) / sizeof(int), [&]() { return uid(dre); });


    int sz = sizeof(arr3000) /
             sizeof(arr3000[0]);          //that function should be able to either have the array already ordered
    //reverse ordered or randomly ordered
    int pivotPoint = 1;
    clock_t tStart = clock();                                //need to get a random and also middle middle:  left + (right - left) / 2;

    cout << "First 10 and Last 10 digits before quicksort: ";
    print(arr3000, sz);
    quicksort(arr3000, 0, sz - 1, sz,
              pivotPoint); // quicksort(int *arr, const int left, const int right, const int sz, int pivotPoint){
    cout << "First 10 and Last 10 digits after quicksort: ";
    print(arr3000, sz);
    printf("First Pivot: %.2fs\n", (double) (clock() - tStart) /
                                   CLOCKS_PER_SEC);                                                //need to measure the execution time somehow in quicksort

    //middle pivot
    generate(arr3000, arr3000 + sizeof(arr3000) / sizeof(int), [&]() { return uid(dre); });


    sz = sizeof(arr3000) /
         sizeof(arr3000[0]);          //that function should be able to either have the array already ordered
    //reverse ordered or randomly ordered
    pivotPoint = 1;                                    //need to get a random and also middle middle:  left + (right - left) / 2;
    tStart = clock();                                //need to get a random and also middle middle:  left + (right - left) / 2;

    quicksort(arr3000, 0, sz - 1, sz,
              pivotPoint); // quicksort(int *arr, const int left, const int right, const int sz, int pivotPoint){

              printf("Middle Pivot: %.2fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    //random pivot
    generate(arr3000, arr3000 + sizeof(arr3000) / sizeof(int), [&]() { return uid(dre); });

    mt19937 rng(rd());
    uniform_int_distribution<mt19937::result_type> dist6(1, 6); // distribution in range [1, 6]

    sz = sizeof(arr3000) /
         sizeof(arr3000[0]);          //that function should be able to either have the array already ordered
    //reverse ordered or randomly ordered
    pivotPoint = 1;                                    //need to get a random and also middle middle:  left + (right - left) / 2;
    tStart = clock();                                //need to get a random and also middle middle:  left + (right - left) / 2;
    quicksort(arr3000, 0, sz - 1, sz,
              pivotPoint); // quicksort(int *arr, const int left, const int right, const int sz, int pivotPoint){
    printf("Random Pivot: %.2fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    //************************************************************************************************************

    cout << endl << endl;

    int hmSize = 75000;
    cout << "*** HEAPSORT AND MERGESORT WITH ARRAY SIZE: " << hmSize << " ***" << endl;
    int arr[hmSize];
    int n = sizeof(arr)/sizeof(arr[0]);

    generate(arr, arr + sizeof(arr) / sizeof(int), [&]() { return uid(dre); });

    cout << "First 10 and Last 10 digits before HeapSort: ";
    print(arr, n);

    heapSort(arr, n);

    cout << "First 10 and Last 10 digits after HeapSort: ";
    print(arr3000, sz);

    //************************************************************************************************************

    cout << endl << endl;
    int mArr[hmSize];
    generate(mArr, mArr + sizeof(mArr) / sizeof(int), [&]() { return uid(dre); });

    cout << "First 10 and Last 10 digits before MergeSort: ";
    print(arr, n);

    int z =0;
    mergeSort(arr, 0, n - 1,z);
    cout << "MERGESORT TOOK " << z << " STATEMENTS\n";

    cout << "First 10 and Last 10 digits after MergeSort: ";
    print(arr3000, sz);

    //***********************************************************************************************************

        int x, i;
        RadixSort obj;
        x=10;

        string arrString[] = {"acdes", "asdsd", "ksjtr",  "kerpt", "absqa", "zabaa", "rkdsb", "qqqqq", "kdfaa", "zedsd"};
        obj.radixsort_stringInc(arrString, x);
        //Printing the sorted data
        cout << "\nSorted Data \n";
        for (i = 0; i < x; i++)
            cout << "-> " << arrString[i] << endl;

        return 0;
}