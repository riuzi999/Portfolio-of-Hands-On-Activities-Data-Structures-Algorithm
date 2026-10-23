#include <iostream>
#include "queueLL.h"

int main() {

    Printer printer;

    std::cout << "===== Morning: initial jobs come in =====\n";
    printer.AddJob(101, "Wrio", 12);
    printer.AddJob(102, "Carlo", 5);
    printer.AddJob(103, "Wrenna", 8);

    printer.DisplayJobs();

    std::cout << "\n===== Printer starts working, one job at a time =====\n";
    printer.ProcessNextJob();   // prints Wrio's job

    std::cout << "\n----- Meanwhile, more people submit jobs -----\n";
    printer.AddJob(104, "Rhy", 20);
    printer.AddJob("Walurich", 4);   

    printer.DisplayJobs();

    std::cout << "\n===== Printer keeps working -----\n";
    printer.ProcessNextJob();   
    printer.ProcessNextJob();   

    std::cout << "\n----- One more late submission arrives -----\n";
    printer.AddJob("Late Submitter", 2);

    std::cout << "\n===== Printer finishes off everything remaining =====\n";
    printer.ProcessAllJobs();

    printer.DisplayJobs();   

    ExplainDesignChoice();   

    return 0;
}