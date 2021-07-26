#include "bits-stdc++.h"
using namespace std;

void Merge(vector<int> &arr, int start, int mid, int end){

    int n = (end-start)+1;

    int left = start;
    int right = mid+1;
    int ecount=0;
    vector<int> temp(n);
    while(left<=mid && right<=end){

        if(arr[left] <= arr[right]){
            temp[ecount] = arr[left];
            left++;
        }
        else{
            temp[ecount] = arr[right];
            right++;
        }

        ecount++;       
    }

    while(left <= mid){
        temp[ecount] = arr[left];
        ecount++;
        left++;
    }

    while(right <= end){
        temp[ecount] = arr[right];
        ecount++;
        right++;
    }

    for(int left=0; left<ecount; left++){
        arr[start+left] = temp[left];
    }
    
}

void mergeSort(vector<int> &arr, int start, int end){
    cout<<"int mergeSort: "<<start<<" - "<<end<<endl;
    if(start>=end){
        return;
    }

    int mid = (start+end)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    Merge(arr, start, mid, end);
}

void printArray(vector<int> arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    printArray(arr, n);

    mergeSort(arr, 0, n-1);
    
    printArray(arr, n);

    return 0;
}