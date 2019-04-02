//given an integer output the interger in words using recursion
//ex  2048 = two zero four eight
#include<iostream>
using namespace std;

char spellings[][10] = {"zero","one","two","three","four","five","six","seven","eigth","nine"};

void print(int n){
    if(n==0){
        return;
    }
    print(n/10);
    cout<<spellings[n%10]<<" ";
}

int main(void){
    int n;
    cin>>n;
    print(n);
    cout<<endl;
    return 0;
}