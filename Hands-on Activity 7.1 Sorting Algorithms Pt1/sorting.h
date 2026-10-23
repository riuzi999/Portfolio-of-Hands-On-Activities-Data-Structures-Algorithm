#ifndef SORTINGALGO_H
#define SORTINGALGO_H

#include <algorithm> // Included for std::swap

// 1. Bubble Sort (Corrected to standard adjacent comparison)
template <typename T>
void bubbleSort(T arr[], int maxSize) {
    for (int i = 0; i < maxSize - 1; ++i) {
        for (int j = 0; j < maxSize - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 2. Selection Sort & Routine Smallest
template<typename T>
int routineSmallest(T arr[], int K, int maxSize) {
    int position = K;
    T smallestElem = arr[K];
    
    for(int j = K + 1; j < maxSize; j++) {
        if(arr[j] < smallestElem) {
            smallestElem = arr[j];
            position = j;
        }
    }
    return position;
}

template<typename T>
void selectionSort(T arr[], int maxSize) {
    for(int i = 0; i < maxSize - 1; i++) {
        int POS = routineSmallest(arr, i, maxSize);
        std::swap(arr[i], arr[POS]);
    }
}

// 3. Insertion Sort (Corrected to prevent out-of-bounds array access)
template <typename T>
void insertionSort(T arr[], int maxSize) {
    for (int k = 1; k < maxSize; k++) {
        T temp = arr[k];
        int j = k - 1;
        
        // The condition j >= 0 is crucial to stop at the start of the array
        for (; j >= 0 && arr[j] > temp; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

// 4. Merge Sort (Required by ILO A instructions)
template <typename T>
void merge(T arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    T* L = new T[n1];
    T* R = new T[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

template <typename T>
void mergeSort(T arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

#endif