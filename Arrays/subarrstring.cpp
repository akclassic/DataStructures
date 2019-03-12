#include<iostream>
// #include<cstring>

using namespace std;

void printAllSubstr(char *a){

    for(int i=0;a[i]!='\0';i++){
        for(int j=i;a[j]!='\0';j++){
            for(int k=i;k<=j;k++){
                cout<<a[k];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}
int main(void){
    char a[] = "abcd";
    printAllSubstr(a);
    cout<<endl;
    return 0;
}