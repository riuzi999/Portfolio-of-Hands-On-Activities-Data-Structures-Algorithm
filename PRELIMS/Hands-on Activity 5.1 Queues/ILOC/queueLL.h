#ifndef QUEUELL_H
#define QUEUELL_H

#include <iostream>
#include <string>

// Job Class
class Job {
public:
    int jobID;
    std::string userName;
    int pages;

    Job() {
        jobID = 0;
        userName = "";
        pages = 0;
    }

    Job(int id, const std::string& user, int p) {
        jobID = id;
        userName = user;
        pages = p;
    }
};


// Display Job

inline std::ostream& operator<<(std::ostream& out, const Job& job) {
    out << "Job ID: " << job.jobID
        << " | User: " << job.userName
        << " | Pages: " << job.pages;
    return out;
}


// Queue Node

template <typename T>
class qNode {
public:
    T data;
    qNode<T>* next;
};


// Create Node

template <typename T>
qNode<T>* new_node(const T& newData) {

    qNode<T>* newNode = new qNode<T>;

    newNode->data = newData;
    newNode->next = nullptr;

    return newNode;
}


// Enqueue

template <typename T>
void enqueue(const T& newData, qNode<T>** frontPtr, qNode<T>** backPtr) {

    qNode<T>* newNode = new_node(newData);

    if ((*frontPtr) == nullptr && (*backPtr) == nullptr) {
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
        return;
    }

    (*backPtr)->next = newNode;
    (*backPtr) = newNode;
}


// Dequeue

template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr) {

    if ((*frontPtr) == nullptr && (*backPtr) == nullptr) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    qNode<T>* temp = (*frontPtr);

    if ((*frontPtr) == (*backPtr)) {
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete temp;
        return;
    }

    (*frontPtr) = (*frontPtr)->next;
    delete temp;
}


// Display Queue

template <typename T>
void displayQueue(qNode<T>* frontPtr) {

    if (frontPtr == nullptr) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    qNode<T>* current = frontPtr;

    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

//========================
// Printer Class
//========================
class Printer {

private:
    qNode<Job>* front;
    qNode<Job>* back;
    int pendingCount; 
    int nextAutoID;
public:

    Printer() {
        front = nullptr;
        back = nullptr;
        pendingCount = 0;
        nextAutoID = 1;
    }

    Printer(const Printer&) = delete;
    Printer& operator=(const Printer&) = delete;

    // Destructor
    ~Printer() {
        while (front != nullptr) {
            dequeue(&front, &back);
        }
    }

    bool IsEmpty() const {
        return front == nullptr;
    }

    int PendingCount() const {
        return pendingCount;
    }

    void AddJob(int id, const std::string& user, int pages) {
        Job newJob(id, user, pages);
        enqueue(newJob, &front, &back);
        pendingCount++;

        std::cout << "[SUBMIT] " << user
                  << " submitted Job " << id
                  << " (" << pages << " pages)" << std::endl;
    }

    void AddJob(const std::string& user, int pages) {
        AddJob(nextAutoID++, user, pages);
    }

    void DisplayJobs() const {
        if (front == nullptr) {
            std::cout << "\nNo pending jobs." << std::endl;
            return;
        }

        std::cout << "\n========== Pending Print Jobs (" << pendingCount << ") ==========\n";
        displayQueue(front);
        std::cout << "========================================\n";
    }


    bool ProcessNextJob() {
        if (front == nullptr) {
            std::cout << "[IDLE] No jobs to process." << std::endl;
            return false;
        }

        Job current = front->data;
        std::cout << "[PRINTING] -> " << current << std::endl;

        dequeue(&front, &back);
        pendingCount--;
        return true;
    }

    // Drains whatever is currently in the queue
    void ProcessAllJobs() {
        if (front == nullptr) {
            std::cout << "\nNo jobs to process." << std::endl;
            return;
        }

        std::cout << "\nProcessing remaining print jobs...\n\n";
        while (front != nullptr) {
            ProcessNextJob();
        }
        std::cout << "\nAll print jobs have been completed." << std::endl;
    }
};

#endif //QUEUELL_H