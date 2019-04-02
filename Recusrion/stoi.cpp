//convert string to integer using recursion

#include<iostream>

using namespace std;

int toInteger(const string& str) {
    if(str.length() == 0)
         return 0;
    return str[str.length() - 1] - '0' +
        toInteger(str.substr(0, str.length() - 1)) * 10;
}

int main(void){
    // string str;
    // cin>>str;
    cout<<toInteger("234");
    cout<<endl;
    return 0;
}