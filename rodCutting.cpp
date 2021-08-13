#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

int rodCutting(vector<int> length, vector<int> price, int n){

    vector<vector<int>> dp(n+1, vector<int>(n+1));

    for(int i=1; i<n; i++){
        dp[0][i]=0;
        dp[i][0]=0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){

            if(length[i-1]<=j){
                dp[i][j] = max(price[i-1]+dp[i][j-length[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }

        }
    }

    print2DArray(dp);

    return dp[n][n];

}

int main(){

    int n;
    cin>>n;
    vector<int> length(n);
    vector<int> price(n);
    for(int i=0; i<n; i++){
        cin>>price[i];
        length[i] = i+1;
    }
    
    int res = rodCutting(length, price, n);
    cout<<res<<endl;

    return 0;
}