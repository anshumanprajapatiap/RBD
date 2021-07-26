#include "bits-stdc++.h"
using namespace std;

void print2DArray(vector<vector<int>> arr){

    for(auto vect:arr){
        for(auto e:vect){
            cout<<e<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void printArray(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void inputArray(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}