#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int setbits=0;
    while(n>0){
        setbits+=n&1;
        n=n>>1;
    }
    cout<<setbits<<endl;
    return 0;
}