#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>


template <typename T>
class queueArr{
    private:
        T* q_array;
        size_t q_capacity;
        size_t q_size;
        int q_front;
        int q_back;
    public:
        //constructor
        queueArr(size_t capacity = 10);

        bool Empty() const;
        size_t Size() const;
        void Clear();

        T front() const;
        T back() const;

        void Enqueue(T value);
        void Dequeue();

        //copy constructor:
        queueArr(const queueArr& other);

        //copy assignment operator:
        queueArr& operator=(const queueArr& other);

        //destructor:
        ~queueArr();
};

//constructor
template <typename T>
queueArr<T>::queueArr(size_t capacity){
    q_capacity = capacity;
    q_size = 0;
    q_front = 0;
    q_back = -1;
    q_array = new T[q_capacity];
}

template <typename T>
bool queueArr<T>::Empty() const{
    return (q_size == 0);
}

template <typename T>
size_t queueArr<T>::Size() const{
    return q_size;
}

template <typename T>
void queueArr<T>::Clear(){
    q_size = 0;
    q_front = 0;
    q_back = -1;
}

template <typename T>
T queueArr<T>::front() const{
    //what will happen if the queue is already empty?
    if(Empty()){
        std::cout<< "The Queue is Empty. \n";
        return T();
    }
    return q_array[q_front];
}

//back
template <typename T>
T queueArr<T>::back() const{
    if(Empty()){
        std::cout<< "The Queue is Empty. \n";
        return T();
    }
    return q_array[q_back];
}

template <typename T>
void queueArr<T>::Enqueue(T value){
    //check if the queue is full
    if(q_size == q_capacity){
        std::cout<< "The Queue is Full. \n";
        return;
    }
    //compute for the q_back for circular (use the modulo operator)
    q_back = (q_back + 1) % static_cast<int>(q_capacity);
    //assign the q_array with the updated q_back to the value
    q_array[q_back] = value;
    //increment the q_size
    q_size++;
    return;
}

template <typename T>
void queueArr<T>::Dequeue(){
    //check if it is empty
    if(Empty()){
        std::cout<< "The Queue is Empty. \n";
        return;
    }
    //move q_front circularly
    q_front = (q_front + 1) % static_cast<int>(q_capacity);

    //decrement the q_size
    q_size--;

    //reset index when queue becomes empty
    if(Empty()){
        Clear();
        return;
    }
}

//copy constructor: deep copy
template <typename T>
queueArr<T>::queueArr(const queueArr& other){
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;
    q_array = new T[q_capacity];
    for(size_t i = 0; i < q_capacity; i++){
        q_array[i] = other.q_array[i];
    }
}

//copy assignment operator: deep copy with self-assignment check
template <typename T>
queueArr<T>& queueArr<T>::operator=(const queueArr& other){
    if(this == &other) return *this;   // guard against self-assignment

    delete[] q_array;                  // free existing memory

    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;
    q_array = new T[q_capacity];
    for(size_t i = 0; i < q_capacity; i++){
        q_array[i] = other.q_array[i];
    }
    return *this;
}

template <typename T>
queueArr<T>::~queueArr(){
    delete[] q_array;
}

#endif //QUEUEARR_H