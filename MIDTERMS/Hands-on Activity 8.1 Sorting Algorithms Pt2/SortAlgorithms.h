#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H

#include <iostream>
using namespace std;

// ============================================================
// A.1 SHELL SORT
// ============================================================
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

// ============================================================
// A.2 MERGE SORT
// ============================================================
void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) return; // 0 or 1 element = already sorted

    int middle = left + (right - left) / 2;
    mergeSort(arr, left, middle);       // sort first half
    mergeSort(arr, middle + 1, right);  // sort second half
    merge(arr, left, middle, right);    // merge sorted halves
}

// ============================================================
// A.3 QUICK SORT
// ============================================================
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1; // pivot's final sorted position
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);   // sort left sub-list
        quickSort(arr, pivotIndex + 1, high);  // sort right sub-list
    }
}

// ============================================================
// UTILITY: print array (only first/last few if large)
// ============================================================
void printArray(int arr[], int n) {
    int limit = (n > 20) ? 10 : n;
    for (int i = 0; i < limit; i++)
        cout << arr[i] << " ";
    if (n > 20) {
        cout << "... ";
        for (int i = n - 10; i < n; i++)
            cout << arr[i] << " ";
    }
    cout << endl;
}

#endif