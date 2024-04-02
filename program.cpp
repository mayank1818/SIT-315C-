#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

// Generate a vector with random values
vector<int> generateVector(size_t length) {
    srand(static_cast<unsigned int>(time(0)));
    vector<int> vector;
    for (size_t p = 0; p < length; ++p) {
        vector.push_back(rand());
    }
    return vector;
}

// Divide and return the pivot index
int divide(vector<int>& array, int min, int max) {
    int indx = array[max];
    int p = min - 1;

    for (int m = min; m < max; ++m) {
        if (array[m] <= indx) {
            p++;
            swap(array[p], array[m]);
        }
    }
    swap(array[p + 1], array[max]);
    return p + 1;
}

// Implement sequential quicksort algorithm
void sequentialquicksort(vector<int>& array, int min, int max) {
    // Check if further partitioning is needed
    if (min < max) {
        // Partition the array and get the pivot index
        int indx = divide(array, min, max);
        // Recursively sort the left and right partitions
        sequentialquicksort(array, min, indx - 1);
        sequentialquicksort(array, indx + 1, max);
    }
}

int main() {
    // Set the size of the vector
    size_t vectorSize = 20000000;

    // Generate a random vector
    vector<int> array = generateVector(vectorSize);

    // Measure time before sorting
    auto start = high_resolution_clock::now();

    // Perform sequential quicksort
    sequentialquicksort(array, 0, array.size() - 1);

    // Measure time after sorting
    auto end = high_resolution_clock::now();

    // Calculate time based on input size
    auto elapse = duration_cast<milliseconds>(end - start);

    cout << "Vector Size: " << array.size() << endl;
    cout << "Time taken by sequential program is " << elapse.count() << " milliseconds" << endl;

    return 0;
}
