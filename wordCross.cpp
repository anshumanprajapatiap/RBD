#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;

bool isValid(vector<vector<char>> &cross, int n, int m,
            int i, int j, vector<vector<bool>> &v, string word, int word_index){
    

    if(word_index==word.length())
        return true;


    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    
    if(v[i][j]){
        return false;
    }

    if(cross[i][j]!=word[word_index])
        return false;
    
    v[i][j]=true;

    bool res = isValid(cross, n, m, i, j+1, v, word, word_index+1) ||
                isValid(cross, n, m, i, j-1, v, word, word_index+1) ||
                isValid(cross, n, m, i+1, j, v, word, word_index+1) ||
                isValid(cross, n, m, i-1, j, v, word, word_index+1);

    v[i][j]= false;

    return res;
}

bool solve(vector<vector<char>> &cross, int n, int m,
            int i, int j, string word){
    

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            vector<vector<bool>> v(n, vector<bool>(m, false)); 

            if(isValid(cross, n, m, i, j, v, word, 0)){
                return true;
            }
            
        }
    }

    return false;

}


int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<char>> cross(n, vector<char>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>cross[i][j];
        }
    }


    
    
    string word;
    cin>>word;

    bool res = solve(cross, n, m, 0, 0, word);

    if(res){
        cout<<"Find";
    }
    else{
        cout<<"Didn't find";
    }

    return 0;
}