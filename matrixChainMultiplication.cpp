#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;
#define N 1001

/* Format of MCM problem */
int solve(int arr[], int i, int j){

    int ans=INT_MAX;
    // Base
    if(i>j){
        return 0;
    }

    for(int k=i; k<j; k++){
        //calculate temp ans

        int tempans = solve(arr, i, k) +solve(arr, k+1, j);

        // ans
        ans = min(ans, tempans);
    }

    return ans;
}
/* Format of MCM problem */

int dp[N][N];

int mcm(int arr[], int i, int j){
    if(i>=j){
        return 0;
    }
    int ans = INT_MAX;

    ///////////////////////////
    if(dp[i][j]!= -1){       //
        return dp[i][j];     //
    }                        //
    ///////////////////////////

    for(int k=i; k<=j-1; k++){
        int temp = mcm(arr, i, k) + mcm(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];

        ans = min(ans, temp);
    }

    ///////////////////////////
    return dp[i][j] = ans;   //
    ///////////////////////////

}


int main(){

    //Given array of matrix
    //find minimum cost to for multiplication
    int arr[] = {40, 20, 30, 10, 30};
    int n =  5;
    memset(dp, -1, sizeof(dp));
    cout<<mcm(arr, 0, n-1)<<endl;

    return 0;
}