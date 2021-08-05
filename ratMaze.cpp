// { Driver Code Starts
//https://practice.geeksforgeeks.org/problems/rat-maze-with-multiple-jumps3852/1

#include "bits-stdc++.h"
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    void printa(vector<vector<int>>& m){
        cout<<" ------------- \n";
        for(auto v:m){
            for(auto e:v){
                cout<<e<<" ";
            }
            cout<<endl;
        }
    }
    
    bool isValid(int i, int j, vector<vector<int>>& m, vector<vector<int>>& v){
        if(i<0 || i>=m.size() || j<0 || j>=m.size() || m[i][j]==0 || v[i][j]==-1){
            return false;
        }
        
        return true;
    }

    bool sortest(vector<vector<int>>&matrix, int i, int j, vector<vector<int>> &temp, vector<vector<int>> &v){
        
        
        if(i==matrix.size()-1 && j==matrix.size()-1){
           
            if(matrix[i][j]==1){
                temp[i][j] =1;
                printa(temp);
                return true;
            }
            else{
                return false;
            }

        }
        
        int loop = matrix[i][j];
        
        if(loop==0){
            return false;
        }
        
        

        
        //v[i][j]=-1;
        
        //right mai jana hai
        
        bool res=false;
        
        
        for(int z=0; z<loop; z++){
            
            //vector<vector<int>> tempcol = temp;
            
            temp[i][j]=1;
            if(isValid(i, j+loop-z, matrix, v)){
                
                res = sortest(matrix, i, j+loop-z, temp, v);
                
            }
            temp[i][j]=0;

            
        }
        
        
        //niche jana hai
        
        
        
        
        for(int z=0; z<loop; z++){
            
            //vector<vector<int>> temprow = temp;
            temp[i][j]=1;
            
            if(isValid(i+loop-z, j, matrix, v)){
                res = sortest(matrix, i+loop-z, j, temp, v);
                
            }
            temp[i][j]=0;
            
            
        }
        
        
        if(res){
            return true;
        }
        
        
        return false;
        
        
    }

	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   // Code here
	   int n = matrix.size();
	   vector<vector<int>> v(n, vector<int>(n,0));
	   
	   vector<vector<int>> temp(n, vector<int>(n,0));
	   
	   bool res = sortest(matrix, 0, 0, temp, v);
	   
	   if(res){
	       
	       return {{0}};
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