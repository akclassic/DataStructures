#include<iostream>
using namespace std;

void bubbleRecurse(int *a, int n){
    //base case
    if(n==1){
        return;
    }

    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            swap(a[i],a[i+1]);
        }
    }

    bubbleRecurse(a,n-1);
}

int main(void){
    int a[] = {5,4,2,3,1};
    int size = sizeof(a)/sizeof(a[0]);
    bubbleRecurse(a,size);

    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}