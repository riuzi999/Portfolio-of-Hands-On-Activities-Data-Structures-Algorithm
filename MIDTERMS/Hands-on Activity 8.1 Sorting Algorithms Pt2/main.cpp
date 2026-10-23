#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "SortAlgorithms.h"
using namespace std;

const int SIZE = 100;

int main() {
    srand(time(0)); 

    int original[SIZE];
    int arrShell[SIZE];
    int arrMerge[SIZE];
    int arrQuick[SIZE];

    // Generate 100 random unsorted values (0 - 999)
    for (int i = 0; i < SIZE; i++) {
        original[i] = rand() % 1000;
    }

    
    memcpy(arrShell, original, sizeof(original));
    memcpy(arrMerge, original, sizeof(original));
    memcpy(arrQuick, original, sizeof(original));

    // ---------- Unsorted array ----------
    cout << "===== Original (Unsorted) Array of 100 Elements =====\n";
    printArray(original, SIZE);

    // ---------- Shell Sort ----------
    cout << "\n===== Shell Sort Result =====\n";
    shellSort(arrShell, SIZE);
    printArray(arrShell, SIZE);

    // ---------- Merge Sort ----------
    cout << "\n===== Merge Sort Result =====\n";
    mergeSort(arrMerge, 0, SIZE - 1);
    printArray(arrMerge, SIZE);

    // ---------- Quick Sort ----------
    cout << "\n===== Quick Sort Result =====\n";
    quickSort(arrQuick, 0, SIZE - 1);
    printArray(arrQuick, SIZE);

    return 0;
}