//Given a brick wall of 4xN size and tile of 4x1 size find the no of total ways to arrange the tiles on the wall
#include<iostream>

using namespace std;

int findWays(int n){
    //base case
    if(n==1 || n==4){
        return n;
    }
    //recurrence relation
    return findWays(n-1)+findWays(n-4);
}

int main(void){
    cout<<"Total no of ways to arrange the 4x1 tiles horizontally or vertically: "<<findWays(4);
    cout<<endl;
    return 0;
}