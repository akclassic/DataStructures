//multiplication of twoo numbers using recursion

#include<iostream>

using namespace std;

//returns a*b
int mult(int a,int b){
    //base case
    if(b==1){
        return a;
    }
    if(b == -1){
        return -a;
    }
    //recusive case
    if(b>0){
        return a+mult(a,b-1);
    }else if(b<0){
        return -a+mult(a,b+1);
    }
}

int main(){
    cout<<mult(5,10);
    cout<<endl;
    return 0;
}