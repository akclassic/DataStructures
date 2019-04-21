//to print all the subsequecnces of a string
#include<iostream>
using namespace std;

void subsequences(char *in,char *out, int i,int j){
    //base case
    if(in[i] == '\0'){
        out[j] = '\0';
        cout<<out<<",";
        return;
    }

    //recurence case
    //1.Include the current char
    out[j] = in[i];
    subsequences(in,out,i+1,j+1);
    //2.exclude the current char
    subsequences(in,out,i+1,j);
}

int main(){
    char in[100];
    cin>>in;

    char out[100];
    subsequences(in,out,0,0);
    cout<<endl;
}