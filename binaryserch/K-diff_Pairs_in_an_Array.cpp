#include <iostream>
#include <algorithm>

using namespace std;

// Function to perform binary search on the array
bool binarySearch(int *array, int arraySize, int startIndex, int target) {
    int start = startIndex, end = arraySize - 1;
    
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(array[mid] == target){
            return true;
        }
        else if(array[mid] > target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return false;
}

// Method 1 to find k-diff pairs
int countPairsMethod1(int *array, int arraySize, int k) {
    sort(array, array + arraySize);
    int i = 0;
    int count = 0;

    while(i < arraySize){
        if(i - 1 >= 0 && array[i - 1] == array[i]) {
            i++;
        }
        else{
            int target = array[i] + k;
            int j = i + 1;
            if(j < arraySize && binarySearch(array, arraySize, j, target)) {
                cout << array[i] << " " << array[i] + k << endl;
                count++;
            }
            i++;
        }
    }
    return count;
}

// Method 2 to find k-diff pairs
int countPairsMethod2(int *array, int arraySize, int k) {
    sort(array, array + arraySize);

    int i = 0, j = i + 1;
    int count = 0;

    while(j < arraySize){
        int diff = array[j] - array[i];
        if(i == j) {
            j++;
            continue;
        }
        if(i - 1 >= 0 && array[i] == array[i - 1]) {
            i++;
            continue;
        }
        if(diff == k) {
            cout << array[i] << " " << array[j] << endl;
            i++;
            j++;
            count++;
        }
        else if(diff > k) {
            i++;
        }
        else {
            j++;
        }
    }
    return count;
}

// Main function to input array and k
int main() {
    int arraySize;
    cout << "Enter the size of the array: ";
    cin >> arraySize;

    int array[100];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < arraySize; i++) {
        cin >> array[i];
    }

    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    
    // Display pairs and count using Method 1
    cout << "Method 1:\n";
    cout << "Number of k-diff pairs: " << countPairsMethod1(array, arraySize, k) << endl;
    
    // Display pairs and count using Method 2
    cout << "Method 2:\n";
    cout << "Number of k-diff pairs: " << countPairsMethod2(array, arraySize, k);

    return 0;
}
