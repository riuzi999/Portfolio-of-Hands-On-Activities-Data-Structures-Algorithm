#ifndef STACK_H
#define STACK_H
#include <iostream>

/* ======================================================
STACK USING ARRAYS
====================================================== */
#define MAX_SIZE 100

template <typename T>
class StackArray {
private:
T arr[MAX_SIZE];
int top;

public:
StackArray() : top(-1) {}

bool isEmpty() {
return top == -1;
}

bool isFull() {
return top == MAX_SIZE - 1;
}

void push(T val) {
if (isFull()) {
std::cout << " Stack overflow.\n";
return;
}
arr[++top] = val;
}

T pop() {
if (isEmpty()) {
std::cout << " Stack underflow.\n";
return T();
}
return arr[top--];
}

T peek() {
if (isEmpty()) {
std::cout << " Stack underflow.\n";
return T();
}
return arr[top];
}
};

/* ======================================================
STACK USING LINKED LIST
====================================================== */
template <typename T>
class Node {
public:
T data;
Node* next;
Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class StackList {
private:
Node<T>* head;

public:
StackList() : head(nullptr) {}

bool isEmpty() {
return head == nullptr;
}

void push(T val) {
Node<T>* newNode = new Node<T>(val);
newNode->next = head;
head = newNode;
}

T pop() {
if (isEmpty()) {
std::cout << " Stack underflow.\n";
return T();
}
Node<T>* temp = head;
T val = temp->data;
head = head->next;
delete temp;
return val;
}

T peek() {
if (isEmpty()) {
std::cout << " Stack underflow.\n";
return T();
}
return head->data;
}

~StackList() {
while (!isEmpty()) pop();
}
};

#endif

