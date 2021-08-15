#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;


 bool lis(vector<int> arr, int n){
     vector<vector<int>> dp(n+1, vector<int>(n+1));

     for(int i=0; i<n+1; i++){
         dp[i][0] =0;
     }

     for(int j=0; j<n+1; j++){
         dp[0][j]=0;
     }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){

            if(arr[i-1]>arr[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    print2DArray(dp);

    return true;

 }


int main(){

    int n = 8;
    vector<int> arr = {1, 2, 3, 4, 9, 6, 7, 9};

    //cin>>n;
    //vector<int> arr(n);
    //inputArray(arr, n);

    //bool res = solve(arr, 0, n, {});

    bool res = lis(arr, n);
    if(res){
        cout<<"P";
    }
    else{
        cout<<"N";
    }

    return 0;
}