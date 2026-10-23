#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

#include "node.h"
#include <iostream>

// =====================================================================
// TABLE 6-2a: linearSearch - sequential search for ARRAYS
// =====================================================================
template <typename T>
void linearSearch(int maxSize, T dataFind, T data[]) {
    int i = 0;
    while (i <= maxSize - 1) {
        if (dataFind == data[i]) {
            std::cout << "Search element is found! (found at index " << i << ")\n";
            return;
        }
        i++;
    }
    std::cout << "Search element is not found\n";
}

// =====================================================================
// TABLE 6-2b: linearLS - the SAME sequential search algorithm,
// modified to operate on a linked list instead of an array.
// Takes the head node of the linked list and the value to search for.
// =====================================================================
template <typename T>
void linearLS(Node<T> *head, T dataFind) {
    Node<T> *node = head;
    while (node != nullptr) {
        if (node->data == dataFind) {
            std::cout << "Search element is found!\n";
            return;
        }
        node = node->next;
    }
    std::cout << "Search element is not found\n";
}

// =====================================================================
// TABLE 6-3a: binarySearch - for ARRAYS
// BINARY SEARCH ALGORITHM
// Step 1: low := 0, up := n-1
// Step 2: Repeat while low <= up
//     mid = int((low+up)/2)
//     if (no == arr[mid]) print "found"; exit
//     else if (no < arr[mid]) up = mid - 1
//     else low = mid + 1
// Step 3: print "not found"
// Step 4: exit
// (list must be sorted)
// =====================================================================
template <typename T>
void binarySearch(T dataFind, T data[], int maxSize) {
    int low = 0, up = maxSize - 1, mid;
    while (low <= up) {
        mid = (int)((low + up) / 2);
        if (dataFind == data[mid]) {
            std::cout << "Search element is found! (found at index " << mid << ")\n";
            return;
        } else if (dataFind < data[mid]) {
            up = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    std::cout << "Search element is not found\n";
}

// =====================================================================
// TABLE 6-3b: Binary Search for LINKED LIST
// =====================================================================

// getMiddle: finds the middle node of the range [start, last) using the
// slow/fast pointer approach:
//   1. Traverse the singly linked list using two pointers.
//   2. Move one pointer by one step ahead and the other by two steps.
//   3. When the fast pointer reaches the end of the range, the slow
//      pointer will be at the middle.
//   4. Return the slow pointer's address.
template <typename T>
Node<T> *getMiddle(Node<T> *start, Node<T> *last) {
    Node<T> *slow = start;
    Node<T> *fast = start;

    while (fast != last && fast->next != last) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// binarySearchLL: binary search over a SORTED (ascending) linked list.
//   1. Start node = head of the list, last node = NULL.
//   2. Middle element is calculated using getMiddle().
//   3. If the middle element equals the key, we found it.
//   4. If the middle element is greater than the key, the key must be in
//      the LEFT half, so we move "last" to the middle node.
//   5. If the middle element is less than the key, the key must be in
//      the RIGHT half, so we move "start" to middle->next.
//   6. Loop ends when the key is found or start meets last (fully traversed).
template <typename T>
void binarySearchLL(Node<T> *start, T dataFind) {
    Node<T> *last = nullptr;

    while (start != last) {
        Node<T> *middle = getMiddle(start, last);

        if (middle->data == dataFind) {
            std::cout << "Search element is found!\n";
            return;
        } else if (middle->data > dataFind) {
            last = middle;         // search the left (lower) half next
        } else {
            start = middle->next;  // search the right (upper) half next
        }
    }
    std::cout << "Search element is not found\n";
}

#endif