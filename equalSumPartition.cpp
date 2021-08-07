#include "bits-stdc++.h"
#include "utility_functions.h"



bool equalSumPartition(vector<int> a, int n){

    int sum=0;
    for(int i=0; i<n; i++){
        sum += a[i];
    }
    if(sum%2!=0){
        return false;
    }

    int s = sum/2;
    vector<vector<bool>> dp(n+1, vector<bool>(s+1));

    //intitalization
    for(int j=0; j<=s; j++){
        dp[0][j] = false;
    }

    for(int i=0; i<=n; i++){
        dp[i][0] = true;
    }


    for(int i=1;i<=n; i++){
        for(int j=1; j<=s; j++){

            if(a[i-1]<=j){
                dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
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
    cin>>n;
    vector<int> a(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    

    bool res = equalSumPartition(a, n);
    if(res){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}