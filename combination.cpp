https://www.interviewbit.com/problems/combinations/
#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

void solve(vector<int> a,int i, int k, vector<vector<int>> &ans, vector<int> temp){

    //printArray(temp);
    if(temp.size()==k || i==a.size()){
        if(temp.size()==k){
            ans.push_back(temp);
        }
        return;
    }

    // else if(i==a.size()){
    //     ans.push_back(temp);
    //     return;
    // }
    

    solve(a, i+1, k, ans, temp);

    temp.push_back(a[i]);
    solve(a, i+1, k, ans, temp);
}

int main(){

    int n, k;
    //cin>>n>>k;
    n=4;
    k=2;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        a[i] = i+1;
    }

    vector<vector<int>> ans;

    solve(a, 0, k, ans, {});

    sort(ans.begin(), ans.end());

    print2DArray(ans);
    

    return 0;
}
