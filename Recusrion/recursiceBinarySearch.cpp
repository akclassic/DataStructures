//recursive binary search
#include<iostream>

using namespace std;

void recursiveBinarySearch(int *arr,int low,int high,int target){
    //base case
    if(arr[low]==target){
        cout<<"Target found at position "<<(low+1)<<endl;
        return;
    }
    //base case
    if(arr[high] == target){
        cout<<"Target found at position "<<(high+1)<<endl;
        return;
    }
    if(low<=high){
        int mid=(low+high)/2;
        //base case
        if(arr[mid]==target){
            cout<<"Target found at "<<mid+1;
            return;
        }else if(arr[mid]>target){
            return recursiveBinarySearch(arr,low,mid-1,target);
        }else{
            return recursiveBinarySearch(arr,mid+1,high,target);
        }
    }
    cout<<"Target not found "<<endl;    
}

int main(void){
    int arr[]={1,2,3,4,5,8,9,11,13,15};
    int n=sizeof(arr)/sizeof(int);
    int target = 4;
    recursiveBinarySearch(arr,0,n-1,target);
    cout<<endl;
    return 0;
}