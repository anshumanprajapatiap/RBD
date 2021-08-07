#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

int countSubsetSum(vector<int> arr, int n, int s){

    vector<vector<int>> dp(n+1, vector<int>(s+1));

    for(int j=0; j<=s; j++)
        dp[0][j] = 0;
    
    for(int i=0; i<=n; i++)
        dp[i][0] = 1;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=s; j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j-1];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    print2DArray(dp);

    return dp[n][s];
}

int main(){

    int n;
    int s;
    cin>>n>>s;
    
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int res = countSubsetSum(arr, n, s);

    cout<<res<<endl;

    return 0;
}