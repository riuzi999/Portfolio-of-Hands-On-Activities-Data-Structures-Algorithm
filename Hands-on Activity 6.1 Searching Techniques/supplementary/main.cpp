#include <iostream>
#include "node.h"
#include "searchingAlgo.h"


template <typename T>
Node<T> *buildLinkedList(T arr[], int size) {
    Node<T> *head = new_node<T>(arr[0]);
    Node<T> *tail = head;
    for (int i = 1; i < size; i++) {
        tail->next = new_node<T>(arr[i]);
        tail = tail->next;
    }
    return head;
}

int main() {
    // =================================================================
    // PROBLEM 1 & 2 DATA:
    // =================================================================
    int list1[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size1 = 10;
    Node<int> *head1 = buildLinkedList(list1, size1);

    std::cout << "=========================================================\n";
    std::cout << "PROBLEM 1: = 18\n";
    std::cout << "List: [15, 18, 2, 19, 18, 0, 8, 14, 19, 14]\n";
    std::cout << "=========================================================\n";
    linearSearchArr<int>(list1, size1, 18);
    linearSearchLL<int>(head1, 18);

    std::cout << "\n=========================================================\n";
    std::cout << "PROBLEM 2: = 18\n";
    std::cout << "=========================================================\n";
    countOccurrencesArr<int>(list1, size1, 18);
    countOccurrencesLL<int>(head1, 18);

    // check:
    std::cout << "\n-- Extra check on other repeating values --\n";
    countOccurrencesArr<int>(list1, size1, 19);
    countOccurrencesArr<int>(list1, size1, 14);

    // ===================
    // Sorted list, searching for key = 8
    // =================================================================
    int list2[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size2 = 10;

    std::cout << "\n=========================================================\n";
    std::cout << "PROBLEM 3: Binary search = 8\n";
    std::cout << "List: [3, 5, 6, 8, 11, 12, 14, 15, 17, 18]\n";
    std::cout << "=========================================================\n";
    binarySearchArr<int>(list2, size2, 8);

    std::cout << "\n=========================================================\n";
    std::cout << "PROBLEM 4: Binary search (RECURSIVE) for key = 8\n";
    std::cout << "=========================================================\n";
    binarySearchRecursiveArr<int>(list2, 0, size2 - 1, 8);

    return 0;
}