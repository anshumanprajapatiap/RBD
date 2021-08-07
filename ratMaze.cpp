// { Driver Code Starts
//https://practice.geeksforgeeks.org/problems/rat-maze-with-multiple-jumps3852/1

#include "bits-stdc++.h"
using namespace std;

 // } Driver Code Ends


class Solution {
public:

    
    bool isValid(int i, int j, vector<vector<int>>& m){

        
        if(i<0 || i>=m.size() || j<0 || j>=m.size() || m[i][j]==0){
            return false;
        }
        
        return true;
    }

    bool sortest(vector<vector<int>>&matrix, int i, int j, vector<vector<int>> &temp){
        
        
        if(i==matrix.size()-1 && j==matrix.size()-1){
            
            temp[i][j] =1;
            return true;

        }
        
        if(isValid(i, j, matrix)){
            
            temp[i][j] = 1;
            
            for(int k=1; k<=matrix[i][j] && k<matrix.size(); k++){
                
                if(sortest(matrix, i, j+k, temp)){ //right
                    return true;
                }
                
                if(sortest(matrix, i+k, j, temp)){ //left
                    return true;
                }
            }
            
            temp[i][j]=0;
            return false;
        }
        
        return false;
    }

	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   // Code here
	   int n = matrix.size();
	   
	   //all possible path will be stored
	   
	   vector<vector<int>> temp(n, vector<int>(n,0));
	   
	   bool res = sortest(matrix, 0, 0, temp);
	   
	   if(res){
	       
	       return temp;
	   }
	   else{
	       return {{-1}};
	   }
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends