#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

void towerofHanoi(int n, int s, int d, int h){

    if(n==1){
        cout<<"moving " << n <<" from " <<s<< " to " <<d<<endl;
        return;
    }

    towerofHanoi(n-1, s, h, d);
    cout<<"moving " << n << " from " <<s<< " to "  <<h<<endl;
    towerofHanoi(n-1, h, d, s);
    
}

int main(){

    int n;
    cin>>n;

    towerofHanoi(n, 1, 2, 3);

    return 0;
}