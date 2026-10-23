#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

#include "node.h"
#include <iostream>

// =====================================================================
// PROBLEM 1: Sequential (linear) search - array version
// Returns the index found (or -1) and prints how many comparisons it took.
// =====================================================================
template <typename T>
int linearSearchArr(T data[], int size, T dataFind) {
    int comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (data[i] == dataFind) {
            std::cout << "[Array] Found " << dataFind << " at index " << i
                    << " -> took " << comparisons << " comparison(s).\n";
            return i;
        }
    }
    std::cout << "[Array] " << dataFind << " not found -> took "
            << comparisons << " comparison(s).\n";
    return -1;
}

// =====================================================================
// PROBLEM 1: Sequential (linear) search
// =====================================================================
template <typename T>
void linearSearchLL(Node<T> *node, T dataFind) {
    int comparisons = 0;

    while (node != nullptr) {
        comparisons++;
        // CREATE AN IF CONDITION THAT WILL COMPARE THE SEARCH ITEM TO THE CURRENT NODE DATA
        if (node->data == dataFind) {
            std::cout << "[Linked List] Found " << dataFind << " -> took "
                    << comparisons << " comparison(s).\n";
            return;
        }
        // ITERATOR / MOVING OF NODE
        node = node->next;
    }
    // DISPLAY IF UNSUCCESSFUL
    std::cout << "[Linked List] " << dataFind << " not found -> took "
            << comparisons << " comparison(s).\n";
}

// =====================================================================
// PROBLEM 2: Modified sequential search
// =====================================================================
template <typename T>
int countOccurrencesArr(T data[], int size, T dataFind) {
    int comparisons = 0;
    int occurrences = 0;

    for (int i = 0; i < size; i++) {
        comparisons++;
        if (data[i] == dataFind) {
            occurrences++;
        }
    }

    std::cout << "[Array] " << dataFind << " appears " << occurrences
            << " time(s) -> took " << comparisons << " comparison(s) total.\n";
    return occurrences;
}

// =====================================================================
// PROBLEM 2: Modified sequential search
// =====================================================================
template <typename T>
int countOccurrencesLL(Node<T> *node, T dataFind) {
    int comparisons = 0;
    int occurrences = 0;

    while (node != nullptr) {
        comparisons++;
        if (node->data == dataFind) {
            occurrences++;
        }
        node = node->next;
    }

    std::cout << "[Linked List] " << dataFind << " appears " << occurrences
            << " time(s) -> took " << comparisons << " comparison(s) total.\n";
    return occurrences;
}

// =====================================================================
// PROBLEM 3: Binary search (ITERATIVE) 
// =====================================================================
template <typename T>
int binarySearchArr(T data[], int size, T dataFind) {
    int low = 0, high = size - 1;
    int iteration = 0;

    while (low <= high) {
        iteration++;
        int mid = low + (high - low) / 2;

        std::cout << "Iteration " << iteration << ": low=" << low
                << " high=" << high << " mid=" << mid
                << " data[mid]=" << data[mid] << "\n";

        if (dataFind == data[mid]) {
            std::cout << "Searching is success! Found " << dataFind
                    << " at index " << mid << " in " << iteration
                    << " iteration(s).\n";
            return mid;
        } else if (dataFind > data[mid]) {
            low = mid + 1;   // discard left half
        } else {
            high = mid - 1;  // discard right half
        }
    }

    std::cout << "The search is unsuccessful. (" << iteration << " iteration(s))\n";
    return -1;
}

// =====================================================================
// PROBLEM 4: Binary search (RECURSIVE)
// =====================================================================
template <typename T>
int binarySearchRecursiveArr(T data[], int low, int high, T dataFind, int iteration = 1) {
    if (low > high) {
        std::cout << "The search is unsuccessful. (" << iteration - 1 << " iteration(s))\n";
        return -1;
    }

    int mid = low + (high - low) / 2;

    std::cout << "Iteration " << iteration << ": low=" << low
        << " high=" << high << " mid=" << mid
        << " data[mid]=" << data[mid] << "\n";

    if (dataFind == data[mid]) {
        std::cout << "Searching is success! Found " 
        << dataFind << " at index " << mid << " in " << iteration
        << " iteration(s).\n";
        return mid;
    } else if (dataFind > data[mid]) {
        return binarySearchRecursiveArr(data, mid + 1, high, dataFind, iteration + 1);
    } else {
        return binarySearchRecursiveArr(data, low, mid - 1, dataFind, iteration + 1);
    }
}

#endif