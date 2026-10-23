#ifndef QUEUELL_H
#define QUEUELL_H
#include <iostream>

template <typename T>
class qNode {
public:
    T data;
    qNode<T> *next;
};

//creating the new node
template <typename T>
qNode<T> *new_node(T newDATA){
    qNode<T> *newNode = new qNode<T>;
    newNode->data = newDATA;
    newNode->next = NULL;
    return newNode;
}

template <typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr){
   //create a node node;
   qNode<T>* newNode = new_node(newData);

   //inserting into an empty queue
   //how do we know that the queue is empty?
   if((*frontPtr)== nullptr && (*backPtr)== nullptr){
      //assign the frontPtr to the newNode
      (*frontPtr)= newNode;
      //assign the backPtr to the newNode
      (*backPtr)= newNode;
      return;
   }
    //point the back next to the newNode:
    (*backPtr)->next = newNode;
    // the newNode will be the new backPtr'
    (*backPtr) = newNode;
    return;
}

template <typename T>
void dequeue(qNode<T> **frontPtr, qNode<T> **backPtr){
    //how to determine if the queue is empty?
    if((*frontPtr) == nullptr && (*backPtr) == nullptr) {
        std::cout<< "The queue is empty. Nothing to dequeue.\n";
        return;
    }
    
    //creating temporary pointer:
    qNode<T>* tempPtr = nullptr;
    //store the frontptr to the temptr;
    tempPtr = (*frontPtr);

    //check if queue has only 1 node left
    if ((*frontPtr) == (*backPtr)){
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete tempPtr;
        return;
    }

    //update the frontptr
    (*frontPtr) = (*frontPtr)->next;
    //point the temptr -> next to null
    tempPtr->next = nullptr;
    delete tempPtr;
}

//display all items the queue: check the traverse in singlyLL
template <typename T>
void displayQueue(qNode<T> *frontPtr){
    //check if the queue is empty
    if(frontPtr == nullptr){
        std::cout<< "The queue is empty.\n";
        return;
    }
    //temp pointer to store the front Ptr
    qNode<T>* current = frontPtr;
    
    //create a loop that will print the tempPtr->data
    while(current != nullptr){
        std::cout<< current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif