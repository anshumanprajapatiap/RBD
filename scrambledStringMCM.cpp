#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;


unordered_map<string, int> mp;

bool scrambledString(string a, string b){

    if(a.compare(b)==0){
        return true;
    }

    if(a.length()<=1){
        return false;
    }

    // MOMIZATION //////////////////////////////////
                                              //////
    string key = a + ","  + b;                //////
                                              //////
    if(mp.find(key) != mp.end()){             //////
        return mp[key];                       //////
    }                                         //////
                                              //////
    // MOMIZATION //////////////////////////////////


    int n = a.length();
    bool flag = false;

    for(int i=1; i<=n-1; i++){

        bool case1 =( scrambledString( a.substr(0,i), b.substr(n-i, i) ) 
                   && scrambledString( a.substr(i,n-1), b.substr(0, n-i) ) );

        bool case2 = ( scrambledString( a.substr(0,i), b.substr(0, i) ) 
                   && scrambledString( a.substr(i,n-i), b.substr(i, n-i) ) );


        if(case1 || case2){
            flag = true;
            break;
        }
    }


    return flag;
    // MOMIZATION /////////////////
    return mp[key] = flag;   //////
    // MOMIZATION /////////////////
}

int main(){

    string a = "great";
    string b = "geart";
    
    if(a.length()!=b.length()){
        cout<<"NOT POSSIBLE"<<endl;
    }
    else{
        bool res = scrambledString(a, b);
        if(res){
            cout<<"POSSIBLE"<<endl;
        }
        else{
            cout<<"NOT POSSIBLE"<<endl;
        }
    }

    return 0;
}