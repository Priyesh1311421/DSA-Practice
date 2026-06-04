#include<bits/stdc++.h>
using namespace std;

// Binary Search
int binarySearch(vector<int>&arr, int key){
    int low = 0;
    int high = arr.size() -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == key) return mid;
        if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}


int lowerBound(vector<int>& arr, int key){
    int low = 0; 
    int high = arr.size() - 1;
    int ans = arr.size();
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] >= key){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}


int upperBound(vector<int>& arr, int key){
    int low = 0; 
    int high = arr.size() - 1;
    int ans = arr.size();
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] > key){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

// minimum in rotated sorted array

int minElement(vector<int>& arr){
    int low = 0; 
    int high = arr.size() - 1;
    int ans = INT_MAX;
    while(low<= high){
        int mid = low + (high - low)/2;
        if(arr[low] <= arr[high]){
            ans = min(ans, arr[low]);
            break;
        }
        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            low = mid + 1;
        }else{
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}



int main(){

}