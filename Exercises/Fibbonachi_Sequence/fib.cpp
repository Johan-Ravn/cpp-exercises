#include <iostream>
#include <chrono>
#include <unordered_map>

using namespace std;

class FibonacciSequence {
public:
    FibonacciSequence(int size) {
        computeFib(size);
    }

    void printFibNumber() {
        cout << "Fib(" << fibSize << "): " << fibValue << endl;
    }

    void printRunTime() {
        cout << "Runtime: " << runtimeMs << " milliseconds" << endl;
    }

private:
    int fibSize;
    unsigned long long fibValue;
    unordered_map<int, unsigned long long> fibCache;
    double runtimeMs;

    void computeFib(int size) {
        auto start = chrono::high_resolution_clock::now();
        // Initialize cache
        fibCache[1] = 0;
        fibCache[2] = 1;
        fibValue = fib(size);

        // Timing the run time
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = end - start;
        runtimeMs = duration.count();
    }

    unsigned long long fib(int n) {
        if (fibCache.find(n) != fibCache.end()) {
            return fibCache[n];
        } if (fibCache.find(n) == fibCache.end()) {
            fibCache[n] = (fib(n - 1) + fib(n - 2));
        }
        return fibCache[n];
    }
};

int main() {
    int fibSize = 100;
    FibonacciSequence fib(fibSize);
    fib.printFibNumber();
    fib.printRunTime();
    return 0;
}
