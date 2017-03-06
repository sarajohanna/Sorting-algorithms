//
//  main.cpp
//  SortingAlgorithms
//
//  Created by Sara Lindström on 2017-03-06.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <iterator>

using namespace std;

void selectionSort(int A[], int n)
{
    for(int j = 0; j < n-1; ++j)
    {
        int iMin = j;
        for (int i = j+1; i < n; ++i)
        {
            if (A[i] < A[iMin])
            {
                iMin = i;
            }
        }
        if (iMin != j)
        {
            int temp = A[iMin];
            A[iMin] = A[j];
            A[j] = temp;
        }
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
    A[rand] = A[left];
    A[left] = p;
    
    int i = left + 1;
    for (int j = left + 1; j < right; ++j)
    {
        if (A[j] < p)
        {
            int temp = A[j];
            A[j] = A[i];
            A[i] = temp;
            ++i;
        }
    }
    A[left] = A[i-1];
    A[i-1] = p;
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
    
    // Copy B back to A
    while(i <= iMiddle)
        A[curr++] = B[i++];
}

void splitMerge(int A[], int B[], int iBegin, int iEnd)
{
    if(iEnd - iBegin < 2)
        return;
    int iMiddle = (iEnd + iBegin) / 2;
    splitMerge(A, B, iBegin, iMiddle); // sort left part
    splitMerge(A, B, iMiddle+1, iEnd); // sort right part
    merge(A, B, iBegin, iMiddle, iEnd);
}

void mergeSort(int A[], int n)
{
    int B[n];
    splitMerge(A, B, 0, n);
}

int main(int argc, const char * argv[]) {
    
    int A[] = {12, 18, 1, 5, 2, 16, 11, 8, 88, 200, 12, 11};
    int n = 12;
    
    for (int i : A)
        cout << i << endl;
    cout << endl;
    
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    quickSort(A, 0, n);
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    cout << "Time: " << elapsed_seconds.count() << "s\n";
    cout << endl;
    
    for (int i : A)
        cout << i << endl;
    cout << endl;
    
    return 0;
}

