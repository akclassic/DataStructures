#include<iostream>

using namespace std;

int main(void){
    int arr[] = {2,4,6,-2,-8,-2};
    //size of the array
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxSum =0, currsum = 0;
    //store the left and right index of the subarray
    int left = -1, right=-1;
    int cumSum[10] = {0};
    //calculate the cummulative sum 
    cumSum[0] = arr[0];
    for(int i=0;i<n;i++){
        cumSum[i] = cumSum[i-1]+arr[i];
    }

    //calculate the max subarr
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            currsum=0;
            currsum = cumSum[j] - cumSum[i-1];

            if(currsum > maxSum){
                maxSum = currsum;
                left=i;
                right=j;
            }
        }
    }

    cout<<"Max sum is: "<<maxSum;
    cout<<"\nSubarray is: ";
    for(int i=left;i<=right;i++){
        cout<<arr[i]<<" ";
    }


    cout<<endl;
    return 0;
}