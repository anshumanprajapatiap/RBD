#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;


bool isValid( vector<vector<int>> &board, int i, int j){

    //row check

    for(int k=0; k<j; k++){
        if(board[i][k]==1){
            return false;
        }
    }

    //top-back
    int l=i, m=j;
    while(l>=0 && m>=0){
        if(board[l][m]==1){
            return false;
        }
        l--;
        m--;
    }

    //top-front
    l=i, m=j;
    while(l<board.size() && m>=0){
        if(board[l][m]==1){
            return false;
        }
        l++;
        m--;
    }

    return true;
}

bool solve( vector<vector<int>> &board, int j){
    if(j==board.size()){
        return true;
    }

    bool res = false;
    for(int i=0; i<board.size(); i++){

        if(isValid(board, i, j)){
            board[i][j] =1;

            res = solve(board, j+1);

            if(res){
                return true;
            }
            board[i][j]=0;
        }

        

    }

    return false;
}

int main(){

    int n;
    cin>>n;

    vector<vector<int>> board(n, vector<int>(n, 0));
   
    bool res= solve(board, 0);
    if(res){
        print2DArray(board);
    }
    else{
        cout<<"NOT POSSIBLE";
    }

    return 0;
}