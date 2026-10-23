#include <iostream>

//global variables:
#define maxSize 10
int stackArr[maxSize];
int top = -1, newData;

//function prototypes:
//top, push , pop , isEmpty , isFull , displayAll
void Top();
void push();
void pop();
bool isEmpty();
bool isFull();
void displayAll();

int main(){
int choice;
std::cout<<"==============================\n";
std::cout<<" Stack Operations:"<<std::endl;
std::cout<<"[1] push [2] pop [3] isEmpty [4] isFull [5] Top [6] Display All"<<std::endl;
std::cin >> choice;
switch(choice){
case 1: push ();
break;
case 2: pop ();
break;
case 3: std::cout<<"is the stack empty"<< isEmpty()<<std::endl;
break;
case 4: std::cout<<"is the stack full"<< isFull()<<std::endl;
break;
case 5: Top();
break;
case 6: displayAll();
break;
default: std::cout<<"Invalid Choice! "<<std::endl;
break;

}
return 0;
}

//funtion definition
bool isEmpty(){
return(top == -1);
}
bool isFull(){
return(top == maxSize-1);
}
void Top(){
if(isEmpty()) return;

std::cout<<"The top element is: "<< stackArr[top]<<std::endl;
}
void push(){
if(isFull()) return;

std::cout<<"What character do you want to push? ";
std::cin >> newData;
stackArr[++top] = newData;

}

void pop(){
if(isEmpty()) return;

std::cout<<"Popping"<< stackArr[top]<<std::endl;
top--;
}

void displayAll(){
if(isEmpty()){
std::cout<<"The stack is empty."<<std::endl;
return;
}

std::cout<<"Stack elements (top to bottom): ";
for(int i = top; i >= 0; i--){
std::cout<<stackArr[i]<<" ";
}
std::cout<<std::endl;
}
