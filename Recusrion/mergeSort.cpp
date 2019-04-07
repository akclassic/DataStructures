//to implement mergesort
#include<iostream>

using namespace std;

void merge(int *a,int l,int h){
    int s,k=0;
    int mid = (l+h)/2;
    int j=mid+1;
    int temp[100];

    while(s<=mid && j<=h){
        if(a[s]<a[j]){
            temp[k++] = a[s++];
        }else{
            temp[k++]= a[j++];
        }
    }
    while(s<=mid){
        temp[k++] = a[s++];
    }
    while(j<=h){
        temp[k++] = a[j++];
    }

    //copy the elements to the original array
    for(int i=0;i<=h;i++){
        a[i] = temp[i];
    }
}

void mergeSort(int *a,int l,int h){
   if(l<h){
       int mid = (l+h)/2;
       mergeSort(a,l,mid);
       mergeSort(a,mid+1,h);
       merge(a,l,h);
   }
}

int main(void){
    int arr[] = {8,9,4,7,6,3,2,1,0};
    int size = sizeof(arr)/sizeof(int);
    mergeSort(arr,0,size-1);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
