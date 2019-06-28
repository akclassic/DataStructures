/*
Original: This film is the best film of the year.
find: film
replace : Movie
new : This movie is the best movie of the year
 */
#include<iostream>
#include<string>
using namespace std;
int lps[] = {0};
//implement find functionality with kmp algo

void computeTempArr(string substr){
    // int lps[substr.length()] = {0};
    int index=0;
    for(int i=1;i<substr.length();){
        if(substr[i] == substr[index]){
            lps[i]=index+1;
            i++;
            index++;
        }else if(substr[i] != substr[index]){
            index = lps[index-1];
            i++;
        }
    }
    // return lps;
}

int KMP(string str,string substr){
    // int  lps[substr.length()] = 
    computeTempArr(substr);
    
    return -1;
}


int main(void){
    string str = "abcdxyzalmaabcaab";
    string substr = "aabcaab";
    int  result = KMP(str,substr);
    //display result

    return 0;
}