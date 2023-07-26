#include <iostream>
using namespace std;

// Function to search a nearly sorted array
int search(int *arr, int size, int target){
    int start = 0, end = size - 1;

    while(start <= end){
        int mid = start + (end - start) / 2;

        // Check if mid element is the target
        if(arr[mid] == target){
            return mid;
        }
        // Check if the next element is the target
        if(mid + 1 < size && arr[mid + 1] == target){
            return mid + 1;
        }
        // Check if the previous element is the target
        if(mid - 1 >= 0 && arr[mid - 1] == target){
            return mid - 1;
        }
        // If target is smaller, ignore right half
        else if(arr[mid] > target){
            end = mid - 1;
        }
        // If target is greater, ignore left half
        else{
            start = mid + 1;
        }
    }
    // Return -1 if target not found
    return -1;
}

int main() {
    int n;
    cin >> n;
    int arr[100];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;

    // Print the index of the target
    cout << search(arr, n, target);

    return 0;
}
