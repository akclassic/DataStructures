//implement binary search recursively
#include<iostream>
using namespace std;

bool bins(int *a,int l,int h,int target){
    //base case
    if(a[l]==target){
        return true;
    }

    //recursive case
    if(l<=h){
        int mid = (l+h)/2;
        if(a[mid]==target){
            return true;
        }else if(target>a[mid]){
            return bins(a,mid+1,h,target);
        }else{
            return bins(a,l,mid-1,target);
        }
    }
    return false;
}

int main(void){
    int arr[] = {2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(int);
    if(bins(arr,0,n-1,12)){
        cout<<"target found";
    }else
    {
        cout<<"target not found";
    }
    
    cout<<endl;
    return 0;
}