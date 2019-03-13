#include<iostream>

using namespace std;

void inputarr(int arr[][10], int r, int c){
    for(int i=0;i<r;i++){
        cout<<"i= "<<i<<" ";
        for(int j=0;j<c;j++){
            cout<<"j= "<<j<<" ";
            cin>>arr[i][j];
        }
    }
}

void waveprint(int arr[][10], int r,int c){
    for(int j=0;j<c;j++){
        if(j&1){
            for(int i=r-1;i>=0;i--){
                cout<<arr[i][j]<<" ";
            }
        }else{
            //even col
            for(int i=0;i<r;i++){
                cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

void staircasesearch(int arr[][10],int r,int c, int key){
    int i=0,j=c-1;
    while(i<r && j>=0){
        if(arr[i][j]==key){
            cout<<"element found at "<<i<<" "<<j;
            return;
        }else if(arr[i][j]>key){
            j--;
        }else{
            i++;
        }
    }
    cout<<"element not found";
    return;
}

int main(void){

    int arr[10][10], r,c;
    cin>>r>>c;
    inputarr(arr,r,c);
    waveprint(arr,r,c);
    staircasesearch(arr,2,4,3);
    cout<<endl;
    return 0;
}