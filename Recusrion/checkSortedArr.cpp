//check if the given array is sorted or not using recursion
#include<iostream>

using namespace std;

bool isSorted(int *arr, int n){
    //base case
    if(n==1){
        return true;
    }
    else if(arr[0]<arr[1] && isSorted(arr,n-1)){
        return true;
    }else{
        return false;
    }
}

int main(){
    int arr[] = {2,3,4,5,6};
    int arr1[] = {3,2,4,6,1};
    if(isSorted(arr,sizeof(arr)/sizeof(arr[0]))){
        cout<<"Array1 is sorted"<<endl;
    }else{
        cout<<"array 2 is not sorted"<<endl;
    }

    if(isSorted(arr1,sizeof(arr1)/sizeof(arr1[0]))){
        cout<<"Array2 is sorted"<<endl;
    }else{
        cout<<"Array2 is not sorted"<<endl;
    }

    return 0;
}