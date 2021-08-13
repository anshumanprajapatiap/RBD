#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;


int LRS(string x, string y, int n, int m){
    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for(int j=0; j<=m; j++){
        dp[0][j] =0;
    }
    for(int i=0; i<=n; i++){
        dp[i][0] =0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){

            if(x[i-1]==y[j-1] && i!=j){
                dp[i][j] = 1+ dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }

        }
    }
    print2DArray(dp);
    return dp[n][m];
}



int main(){

    string x = "AABEBCDD";
    string y = x;


    cout<<LRS(x, y, x.length(), y.length())<<endl;

    
    return 0;
}