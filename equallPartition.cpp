#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

bool subsetSumDp(vector<int> arr, int n, int s, vector<vector<int>> &dp){

    for(int j=0; j<=s; j++){
        dp[0][j] = false;
    }
    for(int i=0; i<=n; i++){
        dp[i][0]= true;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=s; j++){
            if(arr[i-1]<=j){
                dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][s];
    
}

bool equalParition(vector<int> arr, int n){
    
    int sum =0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    
    if(sum%2!=0){
        return false;
    }

    int s = sum/2;
    
    vector<vector<int>> dp(n+1, vector<int>(s+1));

    return subsetSumDp(arr, n, s, dp);
}


int main(){
    
    int n;
    cin>>n;

    vector<int> arr(n);
    inputArray(arr, n);
   

    bool res = equalParition(arr, n);

    if(res){
        cout<<"Possible"<<endl;
    }
    else{
        cout<<"not possible"<<endl;

    }
    


    return 0;
}