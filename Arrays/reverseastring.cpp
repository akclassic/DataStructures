#include<iostream>
#include<cstring>

using namespace std;

void reverseStr(string& str) 
{ 
    int n = str.length(); 
  
    // Swap character starting from two 
    // corners 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 
  
// Driver program 
int main() 
{ 
    string str = "ankit"; 
    reverseStr(str); 
    cout << str<<endl; 
    return 0; 
} 