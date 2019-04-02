//to implement linear search recursively

#include<iostream>

using namespace std;

bool lsearch(int *a, int i,int n,int target){
    //base case
    if(i==n){
        return false;
    }
    if(a[i]==target){
        return true;
    }
    //recursive case
    return lsearch(a,i+1,n,target);
}

int main(void){
    int arr[] = {2,3,4,5,6,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    if(lsearch(arr,0,size,11)){
        cout<<"Target found";
    }else{
        cout<<"target not found";
    }
    cout<<endl;
    return 0;
}