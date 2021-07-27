// N-bit binary number more than & equal to 1's and 0's for any prefix
#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

void nBit(int n, int one, int zero, vector<int> temp, vector<vector<int>> &res){

    if(n==0){
        res.push_back(temp);
        return;
    }

    //vector<int> temp1 = temp;
    temp.push_back(1);
    nBit(n-1, one+1, zero, temp, res);

    temp.pop_back();

    if(zero<one){
        //vector<int> temp2 = temp;

        temp.push_back(0);
        nBit(n-1, one, zero+1, temp, res);
    }

}

int main(){

    int n;
    cin>>n;
    int one = 0;
    int zero= 0;

    vector<vector<int>> res;

    nBit(n, one, zero, {}, res);

    print2DArray(res);

    return 0;
}