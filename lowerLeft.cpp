#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

int lowerLeft(vector<vector<int>> arr, int i, int j){
    
    if(i >= arr.size() || j >= arr[i].size())
        return 0;

    int down = lowerLeft(arr, i+1, j);
    int downright = lowerLeft(arr, i+1, j+1);

    return arr[i][j] + max(down,downright);    
}


int lowerLefDp(vector<vector<int>> &arr, int i, int j, unordered_map<string,int> &dp){
    if(i >= arr.size() || j >= arr[i].size())
        return 0;

    string key = to_string(i) + "," + to_string(j);

    if(dp.find(key)!=dp.end())
        return dp[key];

    int down = lowerLefDp(arr,i+1,j,dp);
    int right = lowerLefDp(arr,i+1,j+1,dp);

    dp[key] = arr[i][j] + max(down,right);

    return arr[i][j] + max(down,right);
}

int main(){

    int n;
    cin>>n;

    vector<vector<int>> arr(n, (vector<int> (n, 0)));

    for(int i = 0 ; i < n; i++){
        vector<int> temp(i+1);
        for(int j = 0 ; j <= i; j++)
            cin>>temp[j];
            arr[i] = temp;
    }

    print2DArray(arr);

    cout<<endl<<"sum: "<<endl<<lowerLeft(arr, 0, 0);

    //solving via dyanamic programming
    unordered_map<string,int> dp;

    int res = lowerLefDp(arr, 0, 0, dp);
    cout<<"\n by solving with dp: \n"<<res<<endl;

    return 0;
}
