#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

void permutation(string s, int i, int n){

    if(i==n){
        cout<<s<<" ";  
    }
    for(int j=i; j<n; j++){
       
        swap(s[i], s[j]);
        permutation(s, i+1, n);
        swap(s[i], s[j]);

    }

}

void permutationSet(string s, int i, int n, set<string> &st){
    if(i==n){
        st.insert(s);  
    }
    for(int j=i; j<n; j++){
       
        swap(s[i], s[j]);
        permutationSet(s, i+1, n, st);
        swap(s[i], s[j]);

    }
}


void permutationWithoutSet(string s, int i, int n){
    if(i==n){
       cout<<s<<" ";  
    }

    for(int j=i; j<n; j++){
       
       permutationWithoutSet(s, i+1, n);
    }
}

int main(){

    string s;
    cin>>s;
    int n = s.size();

    //permutation(s, 0, n);

    set<string> st;

    permutationSet(s, 0, n, st);

    for(auto e:st){
        cout<<e<<" ";
    }
    cout<<endl;

    cout<<"permutations without rep:\n";

    //optimized way 
    permutationWithoutSet(s, 0, n);

    return 0;
}