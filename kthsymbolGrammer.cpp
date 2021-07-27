#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;


int kthsybolGrammer(int n, int k){

    if(n==1 && k==1){
        return 0;
    }

    int mid = (pow(2, n-1))/2;

    if(mid>=k){
        return kthsybolGrammer(n-1, k);
    }
    else{
        return !kthsybolGrammer(n-1, k-mid);
    }
}

int main(){

    int n,k;
    cin>>n>>k;


    cout<< kthsybolGrammer(k, n) <<endl;

    return 0;
}