#include <iostream>
#include "queueLL.h"
#include "queueArr.h"

int main() {

    qNode<int>* front = nullptr;
    qNode<int>* back = nullptr;

    enqueue(1, &front, &back);
    std::cout<< "front: " << front->data <<" back: "<< back->data<<"\n"; 
    enqueue(2, &front, &back);
    enqueue(3, &front, &back);
    std::cout<< "front: " << front->data <<" back: "<< back->data<<"\n";    
    
    displayQueue(front);
    dequeue(&front, &back);
    std::cout<< "front: " << front->data <<" back: "<< back->data<<"\n"; 
    dequeue(&front, &back);
    std::cout<< "front: " << front->data <<" back: "<< back->data<<"\n";
    dequeue(&front, &back);
    dequeue(&front, &back);
    displayQueue(front);



    //object creation
    queueArr<int> q(5);
    
    q.Enqueue(1);
    std::cout<< "front: " << q.front() <<" back: "<< q.back()<< " size: " << q.Size() << "\n";
    q.Enqueue(2);
    std::cout<< "front: " << q.front() <<" back: "<< q.back()<< " size: " << q.Size() << "\n";
    q.Enqueue(3);
    std::cout<< "front: " << q.front() <<" back: "<< q.back()<< " size: " << q.Size() << "\n";
    q.Enqueue(4);
    std::cout<< "front: " << q.front() <<" back: "<< q.back()<< " size: " << q.Size() << "\n";
    q.Enqueue(5);
    std::cout<< "front: " << q.front() <<" back: "<< q.back()<< " size: " << q.Size() << "\n";
    q.Enqueue(6);
    std::cout<< "front: " << q.front() <<" back: "<< q.back()<< " size: " << q.Size() << "\n";

    return 0;
}