#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "sorting.h" // Ensure the provided header is in the same directory

const int maxSize = 100;

void displayArr(int arr[]);

int main() {
    int unsortedArr[maxSize];
    srand(time(0));

    // Populate array with 100 random votes (1 to 5)
    for(int i = 0; i < maxSize; i++) {
        unsortedArr[i] = rand() % 5 + 1; 
    }

    // Sort using Insertion Sort
    insertionSort(unsortedArr, maxSize);

    std::cout << "Sorted Voting Array:\n";
    displayArr(unsortedArr);

    // Tally votes
    int voteCounts[5] = {0};
    for(int i = 0; i < maxSize; i++) {
        voteCounts[unsortedArr[i] - 1]++;
    }

    std::string candidates[] = {
        "Bo Dalton Capistrano", 
        "Cornelius Raymon Agustin", 
        "Deja Jayla Banaga", 
        "Lalla Brielle Yabut", 
        "Franklin Relano Castro"
    };

    int winnerIndex = 0;
    std::cout << "\nVote Tally:\n";
    for(int i = 0; i < 5; i++) {
        std::cout << candidates[i] << ": " << voteCounts[i] << "\n";
        if(voteCounts[i] > voteCounts[winnerIndex]) {
            winnerIndex = i;
        }
    }

    std::cout << "\nWINNER: " << candidates[winnerIndex] << " with " << voteCounts[winnerIndex] << " votes!\n";

    return 0;
}

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}