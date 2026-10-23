#include <iostream>
#include <thread>
#include <mutex>

int globalValue = 0;          // global integer
std::mutex mtx;               // protects globalValue

void add(int n) {
    std::lock_guard<std::mutex> lock(mtx);
    globalValue += n;
}

void display(const std::string& label) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << label << ": " << globalValue << std::endl;
}

int main() {
    std::thread t1(add, 10);
    std::thread t2(add, 20);
    std::thread t3(add, 30);

    display("Display 1 (before any join)");
    t1.join();
    display("Display 2 (after T1.join)");
    t2.join();
    display("Display 3 (after T2.join)");
    t3.join();
    display("Display 4 (after T3.join)");

    return 0;
}