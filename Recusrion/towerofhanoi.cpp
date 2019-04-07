#include<iostream>
using namespace std;

void towerOfHanoi(int n,char src,char dest,char helper){
    //base case
    if(n==0){
        return;
    }
    //recursive case
    //1st case: move n-1 discs from src to helper
    towerOfHanoi(n-1,src,helper,dest);
    //move 1 disc from source to destination
    cout<<"Move "<<n<<" from "<<src<<" to "<<dest<<endl;
    //move n-1 discs from helper to destination
    towerOfHanoi(n-1,helper,dest,src);
}

int main(void){
    int n;
    cin>>n;
    towerOfHanoi(n,'A','C','B');
    cout<<endl;
    return 0;
}