#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

int LCSrecursion(string x, string y, int n, int m){

    if(n==0 || m==0){
        return 0;
    }

    if(x[n-1]==y[m-1]){
        return 1+LCSrecursion(x, y, n-1, m-1);
    }
    else{
        return max( LCSrecursion(x,y, n-1, m), LCSrecursion(x,y, n, m-1) );
    }
}
int LCSmemoized(string x, string y, int n, int m){

    static vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    if(n==0 || m==0){
        return 0;
    }

    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    if(x[n-1]==y[m-1]){
        return dp[n][m] = 1+LCSrecursion(x, y, n-1, m-1);
    }
    else{
        return dp[n][m] = max( LCSrecursion(x,y, n-1, m), LCSrecursion(x,y, n, m-1) );
    }

}


int LCS(string x, string y, int n, int m){
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
    print2DArray(dp);
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
    while(i>0 && j>0){

        if(x[i-1]==y[j-1]){
            s.push_back(x[i-1]);
            i--, j--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }

    reverse(s.begin(), s.end());
    return s;

}


int main(){

    string x = "abcdgh";
    string y = "abedfhr";

    cout<<LCSrecursion(x, y, x.length(), y.length())<<endl;
    cout<<LCSmemoized(x, y, x.length(), y.length())<<endl;
    cout<<LCS(x, y, x.length(), y.length())<<endl;
    cout<<printlcs(x, y, x.length(), y.length())<<endl;
    
    return 0;
}