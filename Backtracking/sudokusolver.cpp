#include<iostream>
#include<cmath>

using namespace std;

bool canPlace(int mat[][9],int i,int j,int n,int number){
    //check the row and column
    for(int x=0;x<n;x++){
        if(mat[x][j] == number || mat[i][x] == number){
            return false;
        }
    }
    //check in the subgrid if the number can be placed
    int rootn = sqrt(n);
    int sx = (i/rootn)*rootn;
    int sy = (j/rootn)*rootn;

    for(int x=sx;x<sx+rootn;x++){
        for(int y=sy;y<sy+rootn;y++){
            if(mat[x][y]==number){
                return false;
            }
        }
    }
    //if the number can be plcaed here return true
    return true;
} 

bool sudokuSolve(int mat[][9],int i,int j,int n){
    //base case
    if(i==n){
        //print the solution
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    //case: row end
    if(j==n){
        return sudokuSolve(mat,i+1,0,n);
    }
    //cell is prefilled
    if(mat[i][j] != 0){
        return sudokuSolve(mat,i,j+1,n);
    }

    //recursive case
    //fill the current cell with possible options
    for(int number =1 ;number<=n;number++){
        if(canPlace(mat,i,j,n,number)){
            //assumning the right number is placed in the current cell
            mat[i][j] = number;
            bool couldWeSolve = sudokuSolve(mat,i,j+1,n);
            if(couldWeSolve == true){
                return true;
            }
        }
    }
    //backtrack if the the number placed in the current cell is not correct
    mat[i][j] = 0;
    return false;
}

int main(void){
    int mat[9][9] = {
        {0,0,0,6,0,0,1,0,7},
        {6,8,0,9,5,1,3,0,0},
        {0,0,3,0,0,2,5,6,8},
        {0,4,0,8,1,0,0,2,0},
        {0,0,0,0,0,0,8,5,0},
        {0,9,0,0,6,5,0,7,3},
        {4,0,9,0,0,3,0,8,5},
        {1,6,2,0,0,9,0,3,0},
        {5,0,0,7,0,6,0,0,0}
    };
    sudokuSolve(mat,0,0,9);
    cout<<endl;
    return 0;
}