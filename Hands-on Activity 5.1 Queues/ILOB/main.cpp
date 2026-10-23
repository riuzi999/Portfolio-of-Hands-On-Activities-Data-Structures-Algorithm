#include <iostream>
#include <queue>
#include <string>

void display(std::queue<std::string> q)
{
    std::queue<std::string> c = q;  

    while (!c.empty())
    {
        std::cout << " " << c.front();
        c.pop();
    }
    std::cout << "\n";
}

int main()
{
    std::string students[] = {"Christine", "Ben", "Isabelle", "Diego", "Ella"};
    int n = sizeof(students) / sizeof(students[0]);

    std::queue<std::string> studentQ;

    // enqueue
    for (int i = 0; i < n; i++)
    {
        studentQ.push(students[i]);
    }

    std::cout << "The student queue is :";
    display(studentQ);

    std::cout << "studentQ.empty() : " << studentQ.empty() << "\n";
    std::cout << "studentQ.size()  : " << studentQ.size() << "\n";
    std::cout << "studentQ.front() : " << studentQ.front() << "\n";
    std::cout << "studentQ.back()  : " << studentQ.back() << "\n";

    std::cout << "After studentQ.pop() : ";
    studentQ.pop();
    display(studentQ);

    studentQ.push("Farah");
    std::cout << "After studentQ.push(\"Farah\") : ";
    display(studentQ);

    return 0;
}