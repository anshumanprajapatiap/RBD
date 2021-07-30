/*
1
30
17 24
26 18
26 34
13 27
2 10
8 3
20 11
17 4
7 21
17 13
9 12
10 8
21 23
14 23
26 28
13 10
19 23
28 30
17 34
23 12
4 30
30 22
8 25
15 39
1 36
17 14
21 12
4 37
21 23
2 27
*/

#include "bits-stdc++.h"
using namespace std;

bool com(const pair<int,int> &a, const pair<int,int> &b){
    
       return a.first>b.first;
}

bool com2(const pair<int,int> &a, const pair<int,int> &b){
    
       return a.second>b.second;
}

void pri(vector<pair<int, int>> v){
    cout<<endl<<"here"<<endl;
    for(auto e:v){
        cout<<e.first<<" "<<e.second<<endl;
    }
    cout<<endl;
}

int solve(int n, vector<pair<int, int>> &v){
    
    
    sort(v.begin(), v.end(), com);
    
    int h = v[0].second;
    
    int sum = h;

    for(int i=1; i<n; i++){
        if(h>v[i].second){
            sum += v[i].second;
            h = v[i].second;
        }
    }

    sort(v.begin(), v.end(), com2);
    int r = v[0].first;
    h = v[0].second;

    int sum2 = h;
    for(int i=1; i<n; i++){
        if(r>v[i].first){
            sum2 += v[i].second;
            r = v[i].first;
        }
    }


    return max(sum, sum2);
}


int main()
{
    int t;
    cin>>t;
    while(t){
        
        int n;
        cin>>n;
        
        vector<pair<int, int>> v;
        
        for(int i=0; i<n; i++){
            int x,y;
            cin>>x>>y;
            
            v.push_back(make_pair(x,y));
        }
        
        
        int ans  = solve(n, v);
        cout<<ans<<endl;
        
        t--;
    }

    return 0;
}