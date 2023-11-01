#include <iostream>
#include <vector>
#include <random>
#include <unordered_maps>

using namespace std;

int hashFunction(int number) {

}

vector<int> populateArray(int size) {
    // Create a random number generator
    random_device rd;
    mt19937 rng(rd());
    // Define the range for the random number
    int minNumber = 1;
    int maxNumber = 100;
    // Create a uniform distribution
    uniform_int_distribution<int> uni(minNumber, maxNumber);

    vector<int> array;
    for (int i = 0; i < size; i++) {
        array.push_back(uni(rng));
    }
    return array;
}

void printIntVector(vector<int> vec) {
    for (int i : vec) {
        cout << i << endl;
    }
}

int main() {
    vector<int> intVectorArray = populateArray(110);
    printIntVector(intVectorArray);
    return 0;
}
