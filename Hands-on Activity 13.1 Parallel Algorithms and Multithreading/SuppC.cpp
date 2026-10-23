#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <random>
#include <chrono>

void merge_sort(std::vector<int>& a, int l, int r, int depth) {
    if (l >= r) return;
    int m = l + (r - l) / 2;

    if (depth > 0) {   // spawn a new thread for the left half
        std::thread left([&] { merge_sort(a, l, m, depth - 1); });
        merge_sort(a, m + 1, r, depth - 1);
        left.join();
    } else {           // sequential below the depth limit
        merge_sort(a, l, m, 0);
        merge_sort(a, m + 1, r, 0);
    }
    std::inplace_merge(a.begin() + l, a.begin() + m + 1, a.begin() + r + 1);
}

double run(std::vector<int> data, int depth) {
    auto start = std::chrono::high_resolution_clock::now();
    merge_sort(data, 0, (int)data.size() - 1, depth);
    auto end = std::chrono::high_resolution_clock::now();
    if (!std::is_sorted(data.begin(), data.end())) std::cout << "NOT SORTED!\n";
    return std::chrono::duration<double, std::milli>(end - start).count();
}

int main() {
    const int N = 5000000;
    std::vector<int> data(N);
    std::mt19937 rng(42);
    for (auto& x : data) x = rng();

    std::cout << "Single thread (depth 0): " << run(data, 0) << " ms\n";
    std::cout << "2 levels  (~4 threads):  " << run(data, 2) << " ms\n";
    std::cout << "3 levels  (~8 threads):  " << run(data, 3) << " ms\n";
}