#include <iostream>

using namespace std;

void initarr(int arr[][10], int r, int c)
{
    int value = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arr[i][j] = value++;
        }
    }
}

void spiralprint(int arr[][10], int r, int c)
{
    int startRow = 0, startCol = 0, endRow = r - 1, endCol = c - 1;
    while (startRow <= endRow && startCol <= endCol)
    {
        //print the start row
        for (int j = startCol; j <= endCol; j++)
        {
            cout << arr[startRow][j] << " ";
        }
        startRow++;
        //print the end column
        for (int i = startRow; i <= endRow; i++)
        {
            cout << arr[i][endCol]<<" ";
        }
        endCol--;
        if (endRow>startRow)
        {
            //print the end row
            for (int j = endCol; j >= startCol; j--)
            {
                cout << arr[endRow][j]<<" ";
            }
            endRow--;
        }
        if(startCol<endCol){
            //print the first column
        for (int i = endRow; i >= startRow; i--)
        {
            cout << arr[i][startCol]<<" ";
        }
        startCol++;
        }
    }
}

int main(void)
{

    int arr[10][10], r, c;
    cin >> r >> c;
    initarr(arr, r, c);
    spiralprint(arr, r, c);
    cout << endl;
    return 0;
}