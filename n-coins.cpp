//A -> [10, 20, 2, 10]
//SUM -> 100
#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

/*
bool solve(vector<int>& A, int sum,int i, int n){

    if(sum == 0)
        return true;
    
    if(sum < 0)
        return false;

    if( i == n){
        return false;
    }


    
    bool included = false;
    bool excluded = false;
    if(sum <= A[i] && A[i] > 0)
        included = solve(A,sum-A[i],i,n);
    
    if(included == false)
        excluded = solve(A,sum,i+1,n);
    

    return included || excluded;
}

int main(){

    int n=5;
    //cin>>n;
    vector<int> a = {10, 20, 4, 3, 1};
    int sum = 2;
    //cin>>sum;

    //solve(a, sum, 0, n, ans, {});

    bool ans = solve(a, sum, 0, a.size());
    
    if(ans){
        cout<<"p"<<endl;
    }
    else{
        cout<<"NP"<<endl;
    }
    

    return 0;
}
*/
bool solve(vector<int>& A, int sum, int i, int n){

    if(sum == 0)
        return true;
    
    if(sum < 0)
        return false;

    if( i == n){
        return false;
    }


    
    bool included = false;
    bool excluded = false;
    if(sum <= A[i] && A[i] > 0)
    included = solve(A,sum-A[i],i,n);
    
    if(included == false)
        excluded = solve(A,sum,i+1,n);
    

    return included || excluded;
}


int main(){

    int tc;
    cin>>tc;

    int sum;
    int n;
    while(tc--){
        cin>>n;
        cin>>sum;
        vector<int> A(n);
        for(int i = 0 ; i < n;i++) 
            cin>>A[i];
        
            bool res = solve(A,sum,0,A.size());

            if(res)
                cout<<"Possible\n";
            else 
                cout<<"Not Possible\n";
    }
}