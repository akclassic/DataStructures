#include<iostream>
#include<cstring>

using namespace std;

int main(void){
    char a[10][100];

    //take input of n strings
    int n;
    cin>>n;
    cin.ignore(); //ignore the enter after n

    for(int i=0;i<n;i++){
        //each row of the character array has length of 100 characters
        //a[i] = ith strings
        //a[i][j] = jth character of ith string
        cin.getline(a[i],100); 
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }

}