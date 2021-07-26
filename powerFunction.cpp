#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

int powerFunctionDP(int a, int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }

    if (b % 2 == 0)
    {
        int x = powerFunctionDP(a, b / 2);
        return x * x;
    }
    else
    {
        int x = powerFunctionDP(a, (b - 1) / 2);
        return x * x * a;
    }
}

int powerFunction(int a, int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }

    if(b%2==0){
        return powerFunction(a, b/2)*powerFunction(a, b/2);
    }
    else{
        return powerFunction(a, (b-1)/2)*powerFunction(a, (b-1)/2)*a;
    }
}

int main(){

    int a,b;
    cin>>a>>b;

    cout<< powerFunctionDP(a, b)<<endl;

    cout<<powerFunction(a,b)<<endl;

    return 0;
}