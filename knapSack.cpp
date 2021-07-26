#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

//globaVariable
int ans=0;

void knapSack(vector<int> &w, vector<int> &p, int kw, int i, int n, int curr){

    if(i==n){
        if(kw>=0){
            ans = max(ans, curr);
        }
        return;
    }

    knapSack(w, p, kw, i+1, n, curr);
    knapSack(w, p, kw-w[i], i+1, n, curr+p[i]);

}

int main(){

    int n;
    cin>>n;
    vector<int> p(n);
    vector<int> w(n);

    inputArray(p, n);
    inputArray(w, n);

    int kw;
    cin>>kw;

    knapSack(w, p,kw, 0, n, 0);

    cout<<ans<<endl;

    return 0;
}