#include <random>
#include <iostream>
#include <vector>

using namespace std;

vector<int> random_array(int size) {
    vector<int> array;

    random_device rd;
    mt19937 rng(rd());
    int minNum = 1;
    int maxNum = 100;
    uniform_int_distribution<int> uni(minNum, maxNum);

    for (int i = 0; i < size; i++) {
        array.push_back(uni(rng));
    }
    return array;
}

void swapIndexes(vector<int> &array, int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

int partition(vector<int> &array, int startIndex, int endIndex) {
    int pivot = endIndex; 
    int smallestIndex = startIndex;

    for (int currentIndex = startIndex; currentIndex < endIndex; currentIndex++) {
        if (array[currentIndex] < array[pivot]) {
            smallestIndex++;
            swapIndexes(array, smallestIndex, currentIndex);
        }
    }

    swapIndexes(array, smallestIndex, pivot);
    return smallestIndex;
}


void quickSort(vector<int> &array, int low, int high) {
    if (low < high) {
        int pivot = partition(array, low, high);
        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}

void printIntVector(vector<int> array) {
    for (int i = 0; i < array.size(); i++) {
        cout << "Index: " << i << " Value: " << array[i] << endl;
    }   
}

int main() {
    vector<int> array = random_array(20);
    quickSort(array, 0, array.size() - 1);
    printIntVector(array);
    return 0;
}
