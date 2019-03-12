#include<iostream>

using namespace std;

int main(){

    char words[10][100] = {
        "ankit",
        "ojha",
        "is",
        "learning",
        "js"
    };
    string strarr[10]={
        "ankit",
        "ojha",
        "is",
        "learning",
        "js"
    };
    for(int i=0;i<10;i++){
        cout<<words[i]<<" ";
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<words[i][j];
        }
        cout<<" ";
    }
    cout<<endl;
    return 0;
}