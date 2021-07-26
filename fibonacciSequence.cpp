#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;


int fibonacci(int n){
    if(n<=1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}


int main(){

    int n;
    cin>>n;

    //nth number 
    cout<<"nth fibonacci number"<<endl;
    int ans = fibonacci(n);
    cout<<ans<<endl;

    return 0;
}