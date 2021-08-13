#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;



int coinChangeI(vector<int> coin, int n, int sum){

    vector<vector<int>> dp( n+1, vector<int>(sum+1) );

    for(int j=0; j<=sum; j++){
        dp[0][j] = 0;
    }
    for(int i=1; i<=n; i++){
        dp[i][0] = 1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){

            if(coin[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i][j-coin[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }

        }
    }
    print2DArray(dp);

    return dp[n][sum];
}

//minmum number of coins
int coinChangeII(vector<int> coin, int n, int sum){

    vector<vector<int>> dp( n+1, vector<int>(sum+1) );

    for(int i=1; i<=n; i++){
        dp[i][0] = 0;
    
    }
    for(int j=0; j<=sum; j++){
        dp[0][j] = INT_MAX-1;
    }
    
    //second row intialization
    for(int j=1; j<=sum; j++){
        if(j%coin[0]==0){
            dp[1][j] = j/coin[0];
        }
        else{
            dp[1][j] = INT_MAX-1;
        }
    }


    for(int i=2; i<=n; i++){
        for(int j=1; j<=sum; j++){

            if(coin[i-1]<=j){
                dp[i][j] = min( dp[i-1][j] , 1 + dp[i][j-coin[i-1]] );
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

    int n =3;
    int sum =5;
    vector<int> coin ={1,2,3};

    cout<<coinChangeI(coin, n, sum)<<endl;
    cout<<coinChangeII(coin, n, sum)<<endl;

    return 0;
}