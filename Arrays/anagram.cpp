#include<iostream>
#include<cstring>

using namespace std;

int main(void){

    string a = "abbac";
    string b = "bbaac";
    bool flag=true;
    int freq[256];
    for(int i=0;i<a.length();i++){
        freq[a[i]-'a']++;
    }
    for(int i=0;i<b.length();i++){
        freq[b[i]-'a']--;
    }
    for(int i=0;i<a.length();i++){
        if(freq[i]!=0){
            flag=false;
        }
    }

    if(flag){
        cout<<"The two string are anagrams";
    }else{
        cout<<"The two strings are not anagrams";
    }
    cout<<endl;
    return 0;
}