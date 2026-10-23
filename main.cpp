#include <iostream>
#include "singly_ll.h"

int main(){

    // Create Nodes: "W R I O O O"
    SinglyList <char>* head = nullptr;
    SinglyList <char>* second = nullptr;
    SinglyList <char>* third = nullptr;
    SinglyList <char>* fourth = nullptr;
    SinglyList <char>* fifth = nullptr;
    SinglyList <char>* sixth = nullptr;

    // Allocated Memory to the Head
    head = new SinglyList<char>;
    second = new SinglyList<char>;
    third = new SinglyList<char>;
    fourth = new SinglyList<char>;
    fifth = new SinglyList<char>;
    sixth = new SinglyList<char>;

    // Added the data to the mode
    head -> data = 'W';
    second -> data = 'R';
    third -> data = 'I';
    fourth -> data =  'O';
    fifth -> data = 'O';
    sixth -> data = 'O';

    // Assign the next to the node
    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    sixth -> next = nullptr;

    std::cout << "Testing the List Traversal Function: \n";
    ListTraversal(head);

    std::cout << "Testing the Insert at Head Function: \n";
    sllInsertHead('Q', &head);
    ListTraversal(head);

    std::cout << "Testing the Insert at any location Function: \n";
    sllGeneralinsert('X', head -> next -> next);
    ListTraversal(head);

    std::cout << "Testing the delete a nodeFunction: \n";
    sllDeleteNode('X', &head);
    ListTraversal(head);
    sllDeleteNode('S', &head);
    ListTraversal(head);
    sllDeleteNode('O', &head);
    ListTraversal(head);
    
    return 0;
    
}
