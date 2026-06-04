#include<bits/stdc++.h>
using namespace std;

// Bubble sort

void bubbleSort(vector<int>& arr, int n){
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n -i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

// Bubble sort is stable in nature and supports In-Place sorting

// Selection sort

void selectionSort(vector<int>& arr, int n){
    for(int i = 0; i < n; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}

// Selection sort is unstable in nature

// Insertion sort

void insertionSort(int n, vector<int>& arr){
    for(int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i-1;
        for(;j>=0;j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}


// Merge sort

void merge(vector<int> arr, int low , int mid, int high){
    int i = low;
    int j = mid+1;
    vector<int> temp;
    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while( i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= high){
        temp.push_back(arr[j]);
        j++;
    }

    for(int i = low; i <= high; i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(vector<int>arr,int low, int high){
    if(low >= high) return ;
    int mid = (low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1, high);
    merge(arr, low, mid, high);
}

// quick sort

int helper(vector<int> &arr, int low , int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(arr[i]<=pivot && i <= high) i++;
        while(arr[j]> pivot && j >= low) j--;
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int parIdx = helper(arr, low, high);
        quickSort(arr,low,parIdx-1);
        quickSort(arr,parIdx + 1, high);
    }
}

int main(){
    vector<int>arr = {2,3,5,4,1};
    selectionSort(arr,5);
    for(auto it: arr){
        cout<<it<<" ";
    }
    return 0;
}