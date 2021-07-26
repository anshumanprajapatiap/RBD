#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

void subSet(vector<vector<int>> &result, vector<int> arr, vector<int> temp, int i, int n){

    if(i==n){
        result.push_back(temp);
        return;
    }

    subSet(result, arr, temp, i+1, n);
    temp.push_back(arr[i]);
    subSet(result, arr, temp, i+1, n);
}

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);
    vector<vector<int>> result;


    inputArray(arr, n);

    subSet(result, arr, {}, 0, n);

    print2DArray(result);
    

    return 0;
}