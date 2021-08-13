#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

//best -> x + y - LCS(X,Y);
//worst -> x + y;

int lcs(string x, string y, int n, int m){

    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for(int j=0; j<=m; j++)
        dp[0][j] =0;
    
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}



string printlcs(string x, string y, int n, int m){
    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for(int j=0; j<=m; j++){
        dp[0][j] =0;
    }
    for(int i=0; i<=n; i++){
        dp[i][0] =0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){

            if(x[i-1]==y[j-1]){
                dp[i][j] = 1+ dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }

        }
    }

    int i=n, j=m;
    string s;
    while(i>0 || j>0){

        if(x[i-1]==y[j-1]){
            s.push_back(x[i-1]);
            i--, j--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j]){
                s.push_back(x[j-1]);
                j--;
            }
            else{
                s.push_back(x[i-1]);
                i--;
            }
        }
    }

    while(i>0){
        s.push_back(x[i-1]);
        i--;
    }
    while(j>0){
        s.push_back(x[j-1]);
        j--;
    }

    reverse(s.begin(), s.end());
    return s;

}



int main(){

    string x = "acbcf";
    string y = "abcdaf";

    cout<<x.length()+y.length() - lcs( x,y,x.length(),y.length() )<<endl;
    cout<<printlcs( x,y,x.length(),y.length() )<<endl;

    return 0;
}