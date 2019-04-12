//mergeSort
#include<iostream>
using namespace std;

void merge(int *arr,int low,int high , int mid){
   // int mid = (low+high)/2;
    int i=low,k=0;
    int j=mid+1;
        int temp[high - low + 1];//int temp[100]={0};
    //merge from the individual array to the temp array
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }

    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=high){
        temp[k++] = arr[j++];
    }

    //copy back the elements to the original array
    for(i = low; i <= high; i += 1) {
        arr[i] = temp[i - low];
    }

}

void mergeSort(int *arr,int low,int high){
    int mid=0;
    if(low<high){
        mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,high,mid);
    }
}

int main(void){
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr,0,n-1);
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}