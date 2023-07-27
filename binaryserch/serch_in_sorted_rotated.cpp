#include <iostream>
using namespace std;

/*
Question: Search for a target number in a sorted, rotated array.
Concept: The array is sorted and rotated, so we still use Binary Search but with a slight modification.
We first determine which half of the array is sorted by comparing the middle element with the start. 
Then we check if the target is within the sorted half. If it is, we update our search to that half. 
Otherwise, we update our search to the other half. 
If the target is found, return its index. If not found, return -1.
*/

// Function to search for the target in the array






int search(int *nums, int n, int target){
    int s = 0, e = n - 1;

    while(s <= e){
        int m = s + (e - s) / 2;
        
        // If target found, return its index
        if(nums[m] == target) return m;
        
        // If the first half is sorted
        if(nums[s] <= nums[m]){
            // If target is in the sorted half, move the end to mid - 1
            if(nums[s] <= target && target < nums[m]){
                e = m - 1;
            }
            // Otherwise, move the start to mid + 1
            else{
                s = m + 1;
            }
        }
        // If the second half is sorted
        else{
            // If target is in the sorted half, move the start to mid + 1
            if(nums[m] < target && target <= nums[e]){
                s = m + 1;
            }
            // Otherwise, move the end to mid - 1
            else{
                e = m - 1;
            }
        }
    }
    // If target not found, return -1
    return -1;
}

int main() {
    int a[100];
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int target;
    cin >> target;
    
    // Call the search function and print the result
    cout << search(a, n, target);
}
