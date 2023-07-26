#include <iostream>

using namespace std;

/*
Question: Find the pivot element in a sorted rotated array.
Concept: A pivot element in a sorted rotated array is the maximum element. We use Binary Search
to find this pivot by comparing the middle element with the start of the array.
If the mid element is greater than the start, we update the start to mid+1. If it's less, we update the end to mid.
*/

// Function to find the pivot in the array
int findPivot(int *a,int n){
    // Initialize start and end points of the array
    int s = 0, e = n - 1;
    
    // Binary search for the pivot
    while(s < e){
        // Calculate mid point
        int m = s + (e - s) / 2;
        // If first element is less than or equal to middle element, move the start to mid + 1
        if(a[0] <= a[m]){
            s = m + 1;
        }
        // Otherwise, move the end to mid
        else{
            e = m;
        }
    }
    // If start equals n-1 and first element is less than last element, return start
    if(s == n - 1 && a[0] < a[n - 1]){
        return s;
    }
    // Otherwise, return start - 1 as the pivot
    return s - 1;
}

int main() {
    // Read size of the array
    int n;
    cin >> n;

    // Initialize array
    int a[100];
    
    // Read elements of the array
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // Print the pivot of the array
    cout << findPivot(a,n);
}
