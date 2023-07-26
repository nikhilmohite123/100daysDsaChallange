#include <iostream>
using namespace std;

// Function to find the number that occurs an odd number of times in a sorted array
int findOddOccurrence(int *array, int size) {

    int start = 0, end = size - 1;

    while (start <= end) {

        int mid = start + (end - start) / 2;
        
        // If mid is even
        if (mid % 2 == 0) {
            // Check if the next element is the same
            if (mid + 1 < size && array[mid] == array[mid + 1]) {
                start = mid + 2;
            }
            // Check if the previous element is the same
            else if (mid - 1 >= 0 && array[mid] == array[mid - 1]) {
                end = mid - 2;
            }
            // If neither next nor previous are same, return the element
            else {
                return array[mid];
            }
        } 
        // If mid is odd
        else {
            // Check if the previous element is the same
            if (mid - 1 >= 0 && array[mid] == array[mid - 1]) {
                start = mid + 1;
            }
            // Check if the next element is the same
            else if (mid + 1 < size && array[mid] == array[mid + 1]) {
                end = mid - 1;
            }
            // If neither next nor previous are same, return the element
            else {
                return array[mid];
            }
        }
    }

    // Return -1 if no odd occurrence was found
    return -1;
}

int main() {
    int arraySize;
    cin >> arraySize;
    
    int array[100];
    for (int i = 0; i < arraySize; i++) {
        cin >> array[i];
    }
    
    cout << findOddOccurrence(array, arraySize);

    return 0;
}
