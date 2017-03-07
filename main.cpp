//
//  main.cpp
//  SortingAlgorithms
//
//  Created by Sara Lindström on 2017-03-06.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

void selectionSort(int A[], int n)
{
    for(int j = 0; j < n-1; ++j)
    {
        int iMin = j;
        for (int i = j+1; i < n; ++i)
        {
            if (A[i] < A[iMin])
                iMin = i;
        }
        if (iMin != j)
            swap(A[iMin], A[j]);
    }
}

//QUICKSORT
int subPartition(int A[], int left, int right)
{
    // Randomly pick pivot
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand();
    int rand = (randomNumber % (right-left)) + left;
    int p = A[rand];
    swap(A[left], A[rand]);
 
    int i = left + 1;
    for (int j = left + 1; j < right; ++j)
    {
        if (A[j] < p)
            swap(A[j], A[i++]);
    }
    swap(A[left], A[i-1]);
    return i;
}

void quickSort(int A[], int start, int n)
{
    if (start < n)
    {
        int p = subPartition(A, start, n);
        quickSort(A, start, p-1);
        quickSort(A, p, n);
    }
}

//MERGESORT
void merge(int A[], int B[], int iBegin, int iMiddle, int iEnd)
{
    //Copy A to B
    for (int k = iBegin; k <= iEnd; ++k)
        B[k] = A[k];
    
    int i = iBegin;
    int curr = iBegin;
    int j = iMiddle+1;
    
    // While there are elements in both sub arrays
    while(i <= iMiddle && j <= iEnd)
    {
        if (B[j] > B[i])
            A[curr++] = B[i++];
        else
            A[curr++] = B[j++];
    }
    
    // Copy remaining to A
    while (i <= iMiddle)
        A[curr++] = B[i++];
}

void splitMerge(int A[], int B[], int iBegin, int iEnd)
{
    if(iBegin >= iEnd)
        return;
    int iMiddle = (iEnd + iBegin) / 2;
    splitMerge(A, B, iBegin, iMiddle); // sort left part
    splitMerge(A, B, iMiddle+1, iEnd); // sort right part
    merge(A, B, iBegin, iMiddle, iEnd);
}

void mergeSort(int A[], int n)
{
    int B[n];
    splitMerge(A, B, 0, n-1);
}

int main(int argc, const char * argv[]) {
    
    int A[] = {12, 18, 1, 5, 2, 16, 10, 8, 88, 200, 13};
    int n = 11;
    
    int B[] = {12, 1};
    int m = 2;

    cout << "Array A to be sorted:" << endl;
    for (int i : A)
        cout << i << endl;
    cout << endl;
    
    
    cout << "Array B to be sorted:" << endl;
    for (int i : B)
        cout << i << endl;
    cout << endl;
    
    cout << "Array A w Selection sort:" << endl;
    selectionSort(A, n);
    for (int i : A)
        cout << i << endl;
    cout << endl;
    
    cout << "Array B w Selection sort:" << endl;
    selectionSort(B, m);
    for (int i : B)
        cout << i << endl;
    cout << endl;
    
    cout << "Array A w Quick sort:" << endl;
    quickSort(A, 0, n);
    for (int i : A)
        cout << i << endl;
    cout << endl;
    
    cout << "Array B w Quick sort:" << endl;
    quickSort(B, 0, m);
    for (int i : B)
        cout << i << endl;
    cout << endl;
    
    cout << "Array A w Merge sort:" << endl;
    mergeSort(A, n);
    for (int i : A)
        cout << i << endl;
    cout << endl;
    
    cout << "Array B w Merge sort:" << endl;
    mergeSort(B, m);
    for (int i : B)
        cout << i << endl;
    cout << endl;
    
    return 0;
}

