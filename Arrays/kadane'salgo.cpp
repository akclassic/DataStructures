#include<iostream>
using namespace std;

int main(void){

    int a[] = {-2,4,-3,5,6,-2,-5};
    int n = sizeof(a)/sizeof(a[0]);
    int cs=0,ms=0;
    for(int i=0;i<n;i++){
        cs+=a[i];
        if(cs<0){
            cs=0;
        }
        ms = max(cs,ms);
    }
    cout<<"max sum= "<<ms;

    cout<<endl;
    return 0;
}