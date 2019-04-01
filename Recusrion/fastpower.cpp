//calculate a^b using recursion

#include<iostream>

using namespace std;

int power(int a, int b){
    //base case
    if(b==0){
        return 1;
    }
    //recursive case
    return a*power(a,b-1);
}

int fastPower(int a, int b){
    //base case
    if(b==0){
        return 1;
    }
    //recurrence relation
    int smallAns = fastPower(a,b/2);
    smallAns*=smallAns;

    if(b&1){
        return a*smallAns;
    }

    return smallAns;
}

int main(){
    int a,b;
    cin>>a>>b;
    int result = fastPower(a,b);
    cout<<result<<endl;;
    return 0;
}