#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

//Doublelist Node
template <typename T>
class DoubleList{
public:
T data;
DoubleList<T>* next;
DoubleList<T>* prev;
};

//create a new node
template <typename T>
DoubleList<T>* createNode(T newData){
DoubleList<T>* newNode = new DoubleList<T>;
newNode->data = newData;
newNode->prev = nullptr;
newNode->next = nullptr;
return newNode;
}

//traverse forward then backward
template <typename T>
void dllTraverse(DoubleList<T>* currentNode){
if(currentNode == nullptr){
std::cout<<"The list is empty";
return;
}

DoubleList<T>* tail;
std::cout<<"FORWARD"<<std::endl;
while(currentNode != nullptr){
std::cout<<currentNode->data<<" ";
tail = currentNode;
currentNode = currentNode->next;
}
std::cout<<std::endl;

std::cout<<"REVERSE"<<std::endl;
while(tail != nullptr){
std::cout<<tail->data<<" ";
tail = tail->prev;
}
std::cout<<std::endl;
}

//insert at the head
template <typename T>
void dllInsertHead(T newData, DoubleList<T>** currentNode){
DoubleList<T>* newNode = createNode(newData);
newNode->next = *currentNode;
(*currentNode)->prev = newNode;
*currentNode = newNode;
}

//insert at the end
template <typename T>
void dllInsertEnd(T newData, DoubleList<T>* currentHead){
DoubleList<T>* newNode = createNode(newData);

while(currentHead->next != nullptr){
currentHead = currentHead->next;
}

newNode->prev = currentHead;
currentHead->next = newNode;
}

//insert at any position (0-indexed) - recursive, no temp
template <typename T>
void dllInsert(T newData, DoubleList<T>** currentNode, int position){
    if(position == 0){
    dllInsertHead(newData, currentNode);
    return;
    }
    dllInsert(newData, &((*currentNode)->next), position-1);
}

//delete from any position (0-indexed) - recursive, no temp
template <typename T>
void dllDelete(DoubleList<T>** currentNode, int position){
    if(position == 0){
    DoubleList<T>* toDelete = *currentNode;
    *currentNode = toDelete->next;
    if(*currentNode != nullptr){
    (*currentNode)->prev = nullptr;
    }
    delete toDelete;
    return;
}
dllDelete(&((*currentNode)->next), position-1);
}
#endif
