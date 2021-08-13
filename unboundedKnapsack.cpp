#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;


int unboundedKnapSack(vector<int> arr, int n, int sum){

    vector<vector<int>> dp(n+1, vector<int>(sum+1));

    for(int j=0; j<sum+1; j++)
        dp[0][j] = 0;
    for(int i=0; i<n+1; i++)
        dp[i][0] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){

            if(arr[i-1]<=j){
                dp[i][j] = max( dp[i-1][j], arr[i-1]+dp[i][j-arr[i-1]] );
            }
            else{
                dp[i][j] = dp[i-1][j];
            }

        }
    }

    print2DArray(dp);

    return dp[n][sum];
}


int main(){

    //multiple accurance are allowed
    vector<int> arr = {1,2,3,5};
    int sum = 5;
    int n=4;
    int res = unboundedKnapSack(arr, n, sum);
    cout<<res<<endl;

    return 0;
}