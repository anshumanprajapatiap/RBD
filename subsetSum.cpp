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
int main(){

    int n;
    cin>>n;

    vector<int> arr(n);
    inputArray(arr, n);
    int s;
    cin>>s;

    vector<vector<int>> dp(n+1, vector<int>(s+1));

    bool res = subsetSumDp(arr, n, s, dp);

    cout<<res<<endl;
    print2DArray(dp);

    return 0;
}