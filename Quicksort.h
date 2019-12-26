#ifndef QUICKSORT_QUICKSORT_H
#define QUICKSORT_QUICKSORT_H

#include <iostream>
#include <algorithm>

//struct Array
//{
//	int *array;
//};

int* createOrderedArray(int size) //creates an array of a given size and returns it as a pointer
{
    int *array = new int[size];

    for(int i =1; i<=size;i++)
    {
        array[i]=i;
    }

    return array;
}
void print(int *array, int size)
{
    array[1]= 0;
    int i = 0;
    while(i < 10){
        std::cout << array[i] << ",";
        i++;
    }

    i= size-10;
    while(i<size)
    {
        std::cout << array[i] << ",";
        i++;
    }
    std::cout << "\n";
}

int partition(int *arr, const int left, const int right, int pivotPoint) //pivotPoint will be first middle or random
{
//   const int pivotPoint = left + (right - left) / 2;
    const int pivot = arr[pivotPoint];
    // move the mid point value to the front.
    std::swap(arr[pivotPoint],arr[left]);
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while(i <= j && arr[i] <= pivot) {
            i++;
        }

        while(i <= j && arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i - 1],arr[left]);
    return i - 1;
}

void quicksort(int *arr, const int left, const int right, const int sz, int pivotPoint)
{

    if (left >= right) {
        return;
    }


    int part = partition(arr, left, right,pivotPoint);
//    std::cout << "QSC:" << left << "," << right << " part=" << part << "\n";
//    print (arr, sz);

    quicksort(arr, left, part - 1, sz,pivotPoint);
//    print(arr,right);


    quicksort(arr, part + 1, right, sz,pivotPoint);
//    print(arr,right);

//    arr[1]=0; // for some reason the 2nd element is always == to a wrong digit
}


#endif //QUICKSORT_QUICKSORT_H
