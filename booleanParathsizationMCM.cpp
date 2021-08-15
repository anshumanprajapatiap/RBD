#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

unordered_map<string, int> mp;

inline const char * const BoolToString(bool b)
{
  return b ? "true" : "false";
}

int booleanParathsis(string a, int i, int j, bool isTrue){

    if(i>j){
        return 0;
    }

    if(i==j){
        if(isTrue){
            return a[i] == 'T';
        }
        else{
            return a[i] == 'F';
        }
    }

    int ans = 0;
    // MOMIZATION //////////////////////////////////
                                              //////
    string key = to_string(i) + ","           //////
                + to_string(j) + ","          //////
                + BoolToString(isTrue);       //////
                                              //////
    if(mp.find(key) != mp.end()){             //////
        return mp[key];                       //////
    }                                         //////
                                              //////
    // MOMIZATION //////////////////////////////////

    for(int k=i+1; k<=j+1; k+=2){
        int lT = (a, i, k-1, true);
        int lF = (a, i, k-1, false);
        int rT = (a, k, j, true);
        int rF = (a, k, j, false);

        if(a[k]=='&'){
            if(isTrue){
                ans = ans + lT*rT;
            }
            else{
                ans = ans + lT*rF + lF*rT + lF*rF;
            }
        }
        else if(a[k]=='|'){

            if(isTrue){
                ans = ans + lT*rT + lT*rF + lF*rT;
            }
            else{
                ans = ans + lF*rF;
            }

        }
        else if(a[k]=='^'){

            if(isTrue){
                ans = ans + lT*rF + lF*rT ;
            }
            else{
                ans = ans + lT*rT + lF*rF;
            }

        }
    }
    
    //return ans;
    // MOMIZATION /////////////////
    return mp[key] = ans;    //////
    // MOMIZATION /////////////////
    
}


int main(){

    string a;
    cin>>a;
    int n= a.size();
    cout<<booleanParathsis(a, 0, n, true);

    return 0;
}