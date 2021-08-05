#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

//globaVariable
int ans=0;

void knapSack(vector<int> &w, vector<int> &p, int kw, int i, int n, int curr){

    if(i==n){
        if(kw>=0){
            ans = max(ans, curr);
        }
        return;
    }

    knapSack(w, p, kw, i+1, n, curr);
    knapSack(w, p, kw-w[i], i+1, n, curr+p[i]);

}


int KnapSackMemoization(vector<int> &wt, vector<int> &val, int w, int n, vector<vector<int>> &dpm){
    
    if(n==0 || w==0){
        return 0;
    }
        
    if(dpm[n][w]!=-1){
        return dpm[n][w];
    }

    if(wt[n-1]<=w){
        return dpm[n][w] = max(val[n-1]+KnapSackMemoization(wt, val, w-wt[n-1], n-1, dpm), 
                                KnapSackMemoization(wt, val, w, n-1, dpm));
    }
    else if(wt[n-1]>w){
        return dpm[n][w] = KnapSackMemoization(wt, val, w, n-1, dpm);
    }

    return dpm[n][w];
    
}

int  knapSackDp(vector<int> &wt, vector<int> &val, int kw){

    int n = wt.size();
    vector<vector<int>> dp(n+1, vector<int>(kw+1));

    //intitalization

    for(int i=0; i<=n; i++){
        for(int j=0; j<=kw; j++){
            if(i==0 || j==0){
                dp[i][j]==0;
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=kw; j++){

            if(wt[i-1]<=j){
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }

            else{
                dp[i][j] = dp[i-1][j];
            }
            
        }
    }

    print2DArray(dp);

    return dp[n][kw];


}



int main(){

    int n;
    cin>>n;
    vector<int> p(n);
    vector<int> w(n);

    inputArray(p, n);
    inputArray(w, n);

    int kw;
    cin>>kw;

    knapSack(w, p,kw, 0, n, 0);

    cout<<"Recursion solution:  "<<ans<<endl<<endl;

    vector<vector<int>> dpm(n+1, vector<int>(kw+1, -1));
    cout<<"Recursion Memoized version:  " <<KnapSackMemoization(w, p, kw, n, dpm)<<endl;
    print2DArray(dpm);

    cout<<"DP Solution: \n"<<knapSackDp(w, p, kw)<<endl;


    return 0;
}