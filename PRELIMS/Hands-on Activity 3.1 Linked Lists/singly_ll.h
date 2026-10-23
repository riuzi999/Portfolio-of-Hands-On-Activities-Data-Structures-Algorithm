#ifndef SINGLY_LL_H
#define SINGLY_LL_H

template <typename T> 
class SinglyList{
public:
    T data;
    SinglyList<T>* next;
};

template <typename T>
void ListTraversal(SinglyList<T>* node){
    // WHILE n IS NOT EQUAL TO NULL:
    while(node != nullptr){
        std::cout << node -> data;
        
        if(node -> next != nullptr){
            // Go to the next node:
        std::cout << " -> ";}

        node = node -> next;
    }

    // Print the next line
    std::cout << std::endl;
}

template <typename T>
void sllInsertHead(T newData, SinglyList<T>** currentHead)
{
    // 1. Allocate memory for the new node
    SinglyList<T>* newNode = new SinglyList<T>;

    // 2. Put our data into the new node
    newNode->data = newData;

    // 3. Set NEXT of the new node to point to the previous HEAD
    newNode->next = *currentHead;

    // 4. Reset HEAD to point to the new node
    *currentHead = newNode;
}

template <typename T>
void sllGeneralinsert(T newData, SinglyList<T>* prevNode){

    //1. Allocate memory for the new node
    SinglyList<T>* newNode = new SinglyList<T>;

    // 2. Put our data into the new node
    newNode->data = newData;

    // 5. Point new node to the node previous node was pointing to
    newNode->next = prevNode->next;

    //6. Point previous node to the new node
    prevNode->next = newNode;
};

template <typename T>
void sllInsertEnd(T newData, SinglyList<T>** head)
{

    // Allocate new node
    SinglyList<T>* newNode = new SinglyList<T>;

    // Dereference to the new node
    SinglyList<T>* currentNode = *head;

    // Store data in new node:
    newNode->data = newData;

    // Point the new node to null:
    newNode->next = nullptr;

    // Traverse the list of the current node to the new node:
    while(currentNode -> next != nullptr){
        currentNode = currentNode -> next;
    }

    // Point the next of the current node to the new node
    currentNode -> next = newNode;
}

template <typename T>
void sllDeleteNode(T findData, SinglyList<T>** head){
    // Check 
    if(*head == nullptr) return;

    SinglyList<T>* currNode = *head;
    SinglyList<T>* prevNode = nullptr;

    // Search for the node. What if the data we are looking for is not in the list.
    // 2. The data was not found
    while(currNode != nullptr && currNode -> data != findData){
        prevNode = currNode;
        currNode = currNode -> next;
    }

    // Data was not found. 
    if(currNode == nullptr) return;

    if (prevNode == nullptr) {
        *head = currNode -> next;
    }
    
    else{ 
        prevNode -> next = currNode -> next;
    }

    delete currNode;
}

#endif
