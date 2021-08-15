#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

int dp[1000][1000];

int eggDropping(int e, int f){
    if(f==1 ||f==0)
    return f;

    if(e==0)
    return f;

    //////////////////////////////
    if(dp[e][f] != -1){
        return dp[e][f];
    }
    /////////////////////////////

    int ans = INT_MAX;

    for(int k=1; k<=f; k++){
        int temp = 1;
        
        //temp += max(eggDropping(e-1, k-1), (e, f-k));

        //Optimization//
        int broken, nobroken;

        if(dp[e-1][k-1]!=-1){
            broken = dp[e-1][k-1];
        }
        else{
            broken = eggDropping(e-1, k-1);
        }
        if(dp[e][f-k]!=-1){
            nobroken = dp[e][f-k];
        }
        else{
            nobroken = eggDropping(e, f-k);
        }
        temp += max(nobroken, broken);
        //Optimization//

        ans = min(ans, temp);
    }

    return dp[e][f] = ans;
    

}

int main(){

    int e,f;
    e = 3;
    f = 5;
    memset(dp, -1, sizeof(dp));
    cout<<eggDropping(e, f);

    return 0;
}