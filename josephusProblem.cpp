#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

void josephusProblem(vector<int> vect, int k, int index, int &ans){
    if(vect.size()==1){
        ans = vect[0];
        return;
    }

    index = (index+k)%vect.size();
    vect.erase(vect.begin()+index);

    josephusProblem(vect, k, index, ans);
}

int main(){

    int n, k;
    cin>>n>>k;
    vector<int> vect(n);
    for(int i=0; i<n; i++){
        vect[i] = i+1;
    }
    k--;
    int ans;
    int index=0;
    josephusProblem(vect, k, index, ans);
    cout<<ans<<endl;

    return 0;
}