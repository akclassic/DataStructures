#include<iostream>
using namespace std;

int main(void){

    char a[] = {'a','n','k','i','t','\0'};
    cout<<a<<endl;
    cout<<sizeof(a)<<endl;
    
    char b[] = "hello";
    cout<<b<<endl;
    cout<<sizeof(b)<<endl;

    char c[100];
    //1.character array, size, delimiter
    cin.getline(c,100,'.');
    cout<<c<<endl;
    cout<<sizeof(c);

    cout<<endl;
    return 0;
}