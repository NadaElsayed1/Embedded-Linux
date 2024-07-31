#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <algorithm>

// Shared memory to store results
std::vector<int> results;
std::mutex mtx;
std::condition_variable cv;
bool ready = false;

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void calculateFibonacci(int index, int n) {
    int fib = fibonacci(n);
    {
        std::lock_guard<std::mutex> lock(mtx);
        results[index] = fib;
        std::cout << "Fibonacci(" << n << ") = " << fib << std::endl;
    }
    cv.notify_one();
}

void printResults() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; });

    int sum = 0;
    std::cout << "Results: ";
    for (int num : results) {
        std::cout << num << " ";
        sum += num;
    }
    std::cout << std::endl;
    std::cout << "Sum: " << sum << std::endl;
}

int main() {
    std::vector<int> indices = {4, 9, 14, 17};
    results.resize(indices.size());

    std::vector<std::thread> threads;
    for (size_t i = 0; i < indices.size(); ++i) {
        threads.push_back(std::thread(calculateFibonacci, i, indices[i]));
    }

    // Wait for all threads to complete
    for (auto& t : threads) {
        t.join();
    }

    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_all();
    printResults();

    return 0;
}
