//to print the largest sum of a row or column in a 2D array
#include <iostream>

using namespace std;

void initarr(int arr[][10], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }
}

void largestSum(int arr[][10],int r,int c){
    int rowLargest=0,colLargest=0, rowno=0,colno=0;
    for(int i=0;i<r;i++){
        int sum = 0;
        for(int j=0;j<c;j++){
            sum += arr[i][j]; 
        }
        if(rowLargest<sum){
            rowLargest = sum;
            rowno=i;
        }
    }
    for(int i=0;i<c;i++){
        int sum = 0;
        for(int j=0;j<r;j++){
            sum += arr[j][i]; 
        }
        if(colLargest<sum){
            colLargest = sum;
            colno=i;
        }
    }
    
    if(rowLargest>colLargest){
        cout<<"max sum is: "<<rowLargest<<" of row: "<<rowno+1;
    }else{
        cout<<"max sum is: "<<colLargest<<" of col: "<<colno+1;
    }
}

void printarr(int arr[][10],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int arr[10][10], r, c;
    cin >> r >> c;
    initarr(arr, r, c);
    printarr(arr,r,c);
    largestSum(arr,r,c);
    cout<<endl;
    return 0;
}