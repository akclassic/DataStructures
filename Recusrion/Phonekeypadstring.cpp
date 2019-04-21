#include<iostream>

using namespace std;

char keypad[][10] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void printKeyPadStrings(char *in, char *out,int i,int j){
    //base case
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<", ";
        return;
    }

    //recursive case
    int digit = in[i]-'0';
    //handle when digit is 1 or 0
    if(digit==1 || digit==0){
        printKeyPadStrings(in,out,i+1,j);
    }
    //itereate over the digit(i.e index) and get all the possible strings
    for(int k=0;keypad[digit][k]!='\0';k++){
        out[j] = keypad[digit][k];
        printKeyPadStrings(in,out,i+1,j+1);
    }
}

int main(void){
    char in[100],out[100];
    cin>>in;
    printKeyPadStrings(in,out,0,0);
    cout<<endl;
    return 0;
}