#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>

// ---------- Problem 1 ----------
bool unique(std::vector<int>& A){
    int n = A.size();
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(A[i] == A[j]) return false;
    return true;
}

// ---------- Problem 2 ----------
double rpower(double x, int n){
    if(n == 0) return 1;
    else return x * rpower(x, n - 1);
}

double brpower(double x, int n){
    if(n == 0) return 1;
    if(n % 2 == 1){
        double y = brpower(x, (n - 1) / 2);
        return x * y * y;
    } else {
        double y = brpower(x, n / 2);
        return y * y;
    }
}

int main(){
    using clock = std::chrono::steady_clock;
    using us = std::chrono::microseconds;

    // Problem 1: worst case (all values unique)
    std::cout << "--- Problem 1: Unique ---\n";
    for(int n : {1000, 2000, 4000, 8000}){
        std::vector<int> A(n);
        std::iota(A.begin(), A.end(), 1);   // 1..n, all unique
        auto b = clock::now();
        bool r = unique(A);
        auto e = clock::now();
        std::cout << "n = " << n << " result = " << r << " time = "
                  << std::chrono::duration_cast<us>(e - b).count() << " microseconds\n";
    }

    // Problem 2: rpower vs brpower
    std::cout << "\n--- Problem 2: Power ---\n";
    for(int n : {10, 100, 1000, 10000}){
        auto b1 = clock::now();
        double r1 = rpower(1.0001, n);
        auto e1 = clock::now();

        auto b2 = clock::now();
        double r2 = brpower(1.0001, n);
        auto e2 = clock::now();

        std::cout << "n = " << n
                  << " | rpower = " << std::chrono::duration_cast<us>(e1 - b1).count() << " microseconds"
                  << " | brpower = " << std::chrono::duration_cast<us>(e2 - b2).count() << " microseconds"
                  << " | results " << r1 << " / " << r2 << "\n";
    }
    return 0;
}