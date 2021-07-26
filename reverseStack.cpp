#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

void insertReverse(stack<int> &st, int ele){
    if(st.size()==0){
        st.push(ele);
        return;
    }

    int temp = st.top();
    st.pop();
    insertReverse(st, ele);

    st.push(temp);

}

void reverseStack(stack<int> &st){
    if(st.size()==1){
        return;
    }

    int val = st.top();
    st.pop();

    reverseStack(st);

    insertReverse(st, val);
}


int main(){

    int n;
    cin>>n;

    stack<int> st;

    for(int i=0;  i<n; i++){
        int x;
        cin>>x;
        st.push(x);
    }
    
    reverseStack(st);

    while (!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}