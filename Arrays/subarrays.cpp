#include<iostream>

using namespace std;

int main(void){

    int a[4]={1,2,3,-4};
    int n = sizeof(a)/sizeof(a[0]);
    int maxSum=0;
    int left=0,right=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int currSum=0;
            for(int k=i;k<=j;k++){
                currSum+=a[k];
            }
            if(currSum>maxSum){
                maxSum=currSum;
                left=i;
                right=j;
            }
        }
    }

    cout<<"Max subarray is: ";
    for(int k=left;k<=right;k++){
        cout<<a[k]<<" ";
    }
    cout<<endl<<"sum of max subarray "<<maxSum;
    cout<<endl;
    return 0;
}