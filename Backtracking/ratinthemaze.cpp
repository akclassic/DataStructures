/*
Given a MxN matrix, with some ccellsas blocked find
1)find path from source to destinations
2)count the no of paths from destinations
3)print all possible paths

The rat can move only in forward direction to either right or down
*/
#include <iostream>
using namespace std;

bool ratInMaze(char maze[10][10], int soln[][10], int i, int j, int m, int n)
{
    //base case
    if (i == m && j == n)
    {
        soln[m][n] = 1;
        //print the solution
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << soln[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    //rat should be inside the grid
    if (i > m || j > n)
    {
        return false;
    }
    //return false if path is blocked
    if (maze[i][j] == 'X')
    {
        return false;
    }

    //assume solution exists through current cell
    soln[i][j] = 1;

    bool rightSuccess = ratInMaze(maze, soln, i, j + 1, m, n);
    bool lefSuccess = ratInMaze(maze, soln, i + 1, j, m, n);

    //backtrack
    //since we have to print all the possible paths
    soln[i][j] = 0;

    if (rightSuccess || lefSuccess)
    {
        return true;
    }
    return false;
}

int main(void)
{
    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0X00"};

    int soln[10][10] = {0};

    int m = 4, n = 4;
    bool ans = ratInMaze(maze, soln, 0, 0, m - 1, n - 1);
    if (!ans)
    {
        cout << "Path does not exits" << endl;
    }
    cout << endl;
    return 0;
}
