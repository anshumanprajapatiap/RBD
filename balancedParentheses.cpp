#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

void balancedParentheses(int open, int close, string op, vector<string> &res){

    if(open==0 && close==0){
        res.push_back(op);
        return;
    }

    if(open!=0){
        string op1 = op;
        op1 += "(";
        balancedParentheses(open-1, close, op1, res);
    }

    if(close>open){
        string op2 = op;
        op2 += ")";
        balancedParentheses(open, close-1, op2, res);
    }
}

int main(){

    int n;
    cin>>n;
    int open = n;
    int close= n;

    vector<string> res;

    balancedParentheses(open, close, "", res);

    printArray(res);  

    return 0;
}