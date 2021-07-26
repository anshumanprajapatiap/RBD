#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

void deleteMiddleofstack(stack<int> &st, int k){

    if(k==1){
        st.pop();
        return;
    }

    int val = st.top();
    st.pop();
    deleteMiddleofstack(st, k-1);

    st.push(val);
}

int main(){

    int n;
    cin>>n;

    stack<int> st;
    int k;

    for(int i=0;  i<n; i++){
        int x;
        cin>>x;
        st.push(x);
    }
    if(n%2==0){
        k = n/2;
    }
    else{
        k = n/2 +1;
    }

    deleteMiddleofstack(st, k);

    while (!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}