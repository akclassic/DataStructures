#include<iostream>
#include<cstring>

using namespace std;

void strrotate(string &s, int r){
    for(int i=0;i<r;i++){
        char x = s[0];
        // cout<<x<<endl;
        s = s.substr(1,s.length()-1);
        // cout<<s<<endl;
        s.push_back(x);
        // cout<<s<<endl;
    }
}

int main(void){

    string s="ankit";
    int rotate = 3;
    strrotate(s,rotate);
    cout<<s;
    cout<<endl;
    return 0;
}