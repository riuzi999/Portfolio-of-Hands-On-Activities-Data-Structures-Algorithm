#include <iostream>
#include "BST.h"

int main() {
    // Create the root node with the first value in the sequence
    BinarySearchTree<int> tree(2);

    // Insert the remaining values
    tree.insert(3);
    tree.insert(9);
    tree.insert(18);
    tree.insert(0);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);

    std::cout << "preOrder: ";
    tree.preOrder();
    std::cout << std::endl;

    std::cout << "inOrder: ";
    tree.inOrder();
    std::cout << std::endl;

    std::cout << "postOrder: ";
    tree.postOrder();
    std::cout << std::endl;

    return 0;
}