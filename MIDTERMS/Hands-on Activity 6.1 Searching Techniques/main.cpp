#include <iostream>
#include "node.h"
#include "searchingAlgo.h"

int main() {
    // =================================================================
    // TABLE 6-2a & 6-2b DATA
    // =================================================================

    // create linked list for linear search
    Node<char> *name1 = new_node('W');
    Node<char> *name2 = new_node('R');
    Node<char> *name3 = new_node('I');
    Node<char> *name4 = new_node('O');

    // link each node to each other
    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = nullptr;

    std::cout << "=========================================================\n";
    std::cout << "TABLE 6-2a: linearSearch (Array version) - name = W R I O\n";
    std::cout << "=========================================================\n";
    char nameArr[] = {'W', 'R', 'I', 'O'};
    std::cout << "Searching for 'I' in array: ";
    linearSearch<char>(4, 'I', nameArr);
    std::cout << "Searching for 'Z' in array (not present): ";
    linearSearch<char>(4, 'Z', nameArr);

    std::cout << "\n=========================================================\n";
    std::cout << "TABLE 6-2b: linearLS (Linked List version) - name = W R I O\n";
    std::cout << "=========================================================\n";
    std::cout << "Searching for 'I' in linked list: ";
    linearLS<char>(name1, 'I');
    std::cout << "Searching for 'Z' in linked list (not present): ";
    linearLS<char>(name1, 'Z');

    // =================================================================
    // TABLE 6-3a: binarySearch
    // =================================================================
    std::cout << "\n=========================================================\n";
    std::cout << "TABLE 6-3a: binarySearch (Array version)\n";
    std::cout << "=========================================================\n";
    int sortedArr[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int arrSize = 10;
    std::cout << "Searching for 8: ";
    binarySearch<int>(8, sortedArr, arrSize);
    std::cout << "Searching for 100 (not present): ";
    binarySearch<int>(100, sortedArr, arrSize);

    // =================================================================
    // TABLE 6-3b: Binary Search for Linked List 
    // =================================================================
    std::cout << "\n=========================================================\n";
    std::cout << "TABLE 6-3b: Binary Search for Linked List\n";
    std::cout << "=========================================================\n";
    std::cout << "Enter SORTED integers one at a time. Type 'n' when done.\n\n";

    // create a linked list for binary search
    // make sure the values are ordered
    char choice = 'y';
    int count = 1, newData;
    Node<int> *temp, *head = nullptr, *node;

    while (choice == 'y') {
        std::cout << "Enter data: ";
        std::cin >> newData;

        if (count == 1) {
            head = new_node(newData);
            std::cout << "Successfully added " << head->data << " to the list.\n";
            count++;
        } else if (count == 2) {
            node = new_node(newData);
            head->next = node;
            node->next = nullptr;
            std::cout << "Successfully added " << node->data << " to the list.\n";
            count++;
        } else {
            temp = head;
            while (true) {
                if (temp->next == nullptr) break;
                temp = temp->next;
            }
            node = new_node(newData);
            temp->next = node;
            std::cout << "Successfully added " << node->data << " to the list.\n";
            count++;
        }

        std::cout << "Continue? (y/n): ";
        std::cin >> choice;
        if (choice == 'n') break;
    }

    // display to verify the data 
    std::cout << "\nCurrent list: ";
    Node<int> *currNode = head;
    while (currNode != nullptr) {
        std::cout << currNode->data << " ";
        currNode = currNode->next;
    }
    std::cout << "\n\n";

    int target;
    std::cout << "Enter the value to binary search for: ";
    std::cin >> target;
    binarySearchLL<int>(head, target);

    return 0;
}   