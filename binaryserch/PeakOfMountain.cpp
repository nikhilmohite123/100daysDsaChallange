#include<iostream>

using namespace std;

/*
Question: Find the peak of a mountain in an array.
Concept: The peak of the mountain is the maximum element in the array. We use Binary Search
to find this peak by comparing the middle element with the next element. 
If the middle element is less than or equal to the next element, move the start to mid+1.
Otherwise, move the end to mid. 
The peak is found when start equals end and we return that element.
*/

// Function to find the peak of the mountain in the array







int  peackOfmountain(int *a,int n){
    // Initialize start and end points of the array
    int s=0, e=n-1;
    
    // Binary search for the peak
    while(s<e){
        // Calculate mid point
        int m = s+(e-s)/2;
        
        // If middle element is less than or equal to next element, move the start to mid + 1
        if(a[m]<=a[m+1]){
            s = m + 1;
        }
        // Otherwise, move the end to mid
        else{
            e = m;
        }
    }

    // Return the peak of the mountain
    return a[s];
}

int main() {
    // Read size of the array
    int n;
    cin>>n;

    // Initialize array
    int a[100];
    
    // Read elements of the array
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    // Print the peak of the mountain
    cout<< peackOfmountain(a,n);
}
