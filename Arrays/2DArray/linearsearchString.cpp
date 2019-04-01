#include<iostream>
#include<cstring>
#include<stdlib.h>

using namespace std;

int main(void){
    int n;
    cin>>n;
    cin.ignore();

    char str[n][100];
    for(int i=0;i<n;i++){
        cin.getline(str[i],100);
    }

    char key[100];
    cout<<"enter a string to search: ";
    cin.getline(key,100);

    int i=0;
    for(;i<n;i++){
        //compare arra using strcmp() function
        if(strcmp(key,str[i])==0){
            cout<<"Found at index "<<i<<endl;
            break;
        }
    }
    if(i==n){
        cout<<"not found";
    }

    cout<<endl;
    return 0;
}