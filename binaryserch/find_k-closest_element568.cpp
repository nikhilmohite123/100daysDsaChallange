#include<iostream>
#include<vector>
using namespace std;

// Function that uses binary search to find the closest index to x in array a
int bs(vector<int>& a, int x){
    int s = 0, e = a.size() - 1;
    int ans = s;
    while(s <= e){
        int m = s + (e - s) / 2;
        if(a[m] <= x){
            ans = m;
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    return ans;
}

// First approach to find the k closest elements to x
vector<int> findClosestElements_1approach(vector<int>& arr, int k, int x) {
    int l = 0, h = arr.size() - 1;
    while(h - l >= k){
        if(x - arr[l] == arr[h] - x){
            h--;
        }
        else if(x - arr[l] > arr[h] - x){
            l++;
        }
        else{
            h--;
        }
    }
    return vector<int>(arr.begin() + l, arr.begin() + h + 1);
}

// Second approach to find the k closest elements to x
vector<int> findClosestElements_2approach(vector<int>& arr, int k, int x) {
    int l = bs(arr, x);
    int h = l + 1;
    while(k--){
        if(l < 0) {
            h++;
        } else if(h >= arr.size()) {
            l--;
        } else if(x - arr[l] == arr[h] - x) {
            l--;
        } else if(x - arr[l] > arr[h] - x) {
            h++;
        } else {
            l--;
        }
    }
    return vector<int>(arr.begin() + l + 1, arr.begin() + h);
}

// Main function to test the code
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;

    // Change this line to test different approaches
    vector<int> ans = findClosestElements_2approach(arr, k, x);

    // Print the results
    for(int i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
