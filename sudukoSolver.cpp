#include "bits-stdc++.h"
#include "utility_functions.h"
using namespace std;
#define N 9


class Solution 

{
    public:
    //Function to find a solved Sudoku. 
    bool isValid(int grid[N][N], int i, int j, int num){

        //row
        for(int k=0; k<N; k++){
            if(grid[i][k]==num){
                return false;
            }
        }

        //column

        for(int k=0; k<N; k++){
            if(grid[k][j]==num){
                return false;
            }
        }

        //3x3
        int iRow = i - i % 3;
        int iCol = j - j % 3;

        for (int z = 0; z < 3; z++){
            for (int y = 0; y < 3; y++){
                if (grid[z + iRow][y + iCol] == num)
                    return false;  
            }
        }

        return true;

    }

    bool solve(int i, int j, int grid[N][N]){
        if(i==N-1 && j==N){
            return true;
        }

        if (j == N) {
            i++;
            j = 0;
        }

        if (grid[i][j] > 0)
            return solve(i, j + 1, grid);

        for (int num = 1; num <= N; num++){
            if(isValid(grid, i, j, num)){
                grid[i][j] = num;

                if(solve(i, j+1, grid)){
                    return true;
                }
            }

            grid[i][j]=0;
        }

        return false;

    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        int i=0;
        int j=0;
        bool ans = false;
        ans = solve(i, j, grid);

        if(ans){
            return true;
        }
        return false;
        
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
};

int main(){

    int grid[N][N] = {
            {3, 0, 6, 5, 0, 8, 4, 0, 0},
            {5, 2, 0, 0, 0, 0, 0, 0, 0},
            {0, 8, 7, 0, 0, 0, 0, 3, 1},
            {0, 0, 3, 0, 1, 0, 0, 8, 0},
            {9, 0, 0, 8, 6, 3, 0, 0, 5},
            {0, 5, 0, 0, 9, 0, 6, 0, 0},
            {1, 3, 0, 0, 0, 0, 2, 5, 0},
            {0, 0, 0, 0, 0, 0, 0, 7, 4},
            {0, 0, 5, 2, 0, 6, 3, 0, 0}
            };

            /*
            3 1 6 5 7 8 4 9 2
            5 2 9 1 3 4 7 6 8
            4 8 7 6 2 9 5 3 1
            2 6 3 4 1 5 9 8 7
            9 7 4 8 6 3 1 2 5
            8 5 1 7 9 2 6 4 3
            1 3 8 9 4 7 2 5 6
            6 9 2 3 5 1 8 7 4
            7 4 5 2 8 6 3 1 9
            */
    int t=1;
	//cin>>t;
	while(t--)
	{
		//int grid[N][N];
		
		// for(int i=0;i<9;i++)
		//     for(int j=0;j<9;j++)
		//         cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
    return 0;
}