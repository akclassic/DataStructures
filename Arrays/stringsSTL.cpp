#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;


bool compare(string a,string b){
    return a.length()>b.length();
} 

int main(void){

    string s("hello ankit");
    cout<<s<<endl;
    cout<<s.length()<<endl;

    string g = "hello world !!!";
    cout<<g<<endl;
    cout<<g.length()<<endl;

    // string s3;
    // getline(cin,s3);
    // cout<<s3<<endl;

    string s4[] = {"mac", "samsung s10","msi"};
    sort(s4,s4+3,compare);
    for(int i=0;i<3;i++){
        cout<<s4[i]<<", ";
    }

    cout<<endl;
    return 0;
}