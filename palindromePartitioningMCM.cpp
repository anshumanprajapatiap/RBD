#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;
#define N 1001


int dp[N][N];

bool isPalindrome(string str){
    int n = str.size();
    for(int i=0; i<n/2; i++){
        if(str[i] != str[n-i-1]){
            return false;
        }
    }

    return true;
}

int palindromePartitioning(string a, int i, int j){

    if(i>=j){
        return 0;
    }

    string t = a.substr(i, j);
    //cout<<t<<endl;
    if(isPalindrome(t)){
        return 0;
    }
    //////////////////////////
    if(dp[i][j] != -1){     //
        return dp[i][j];    //
    }                       //
    //////////////////////////

    int ans = INT_MAX;

    for(int k=i; k<=j-1; k++){

        int temp = 1;

        /* un optimized */
        // temp = 1+ palindromePartitioning(a, i, k) + palindromePartitioning(a, k+1, j);
        /* un optimized */


        /* optimization */
        int left; 
        int right;

        if(dp[i][k] != -1){
            left = dp[i][k];
        }
        else{
            left = palindromePartitioning(a, i, k);
        }

        if(dp[k+1][j]!= -1){
            right = dp[k+1][j];
        }
        else{
            right = palindromePartitioning(a, k+1, j);
        }

        temp = right + left;

        /* Optimization */

        ans = min(ans, temp);

    }

    //return ans;
    return dp[i][j] = ans;
    // store and return

}

int main(){

    string a = "tenin";
    int n = a.length();

    memset(dp, -1, sizeof(dp));


    if(isPalindrome(a)){
        cout<<"It is palindrome"<<endl;
    }
    else{
        cout<<palindromePartitioning(a, 0, n)<<endl;
    }

    return 0;
}