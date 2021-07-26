#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

void stackinsert(stack<int> &stk, int temp){
    if(stk.empty() || stk.top()<=temp){
        stk.push(temp);
        return;
    }

    int val = stk.top();
    stk.pop();
    stackinsert(stk, temp);
    stk.push(val);

}

void sortStack(stack<int> &stk){
    if(stk.size()==1){
        return;
    }

    int temp = stk.top();
    stk.pop();
    sortStack(stk);
    stackinsert(stk, temp);

}


int main(){

    int n;
    cin>>n;

    stack<int> stk;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        stk.push(x);
    }

    sortStack(stk);

    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }  

    return 0;
}