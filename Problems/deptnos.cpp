/*
Department numbers
-fire
-police
-sanitation
each assigned a number in the range of 1-7
Fire #, Police #, Sanitation # all different
Fire #+ Police # + Sanitation # =12
Police # must be eve

Problem: write a program t o diaplay all valid department number permutations
 */

#include<iostream>
using namespace std;

bool isValidNo(int f,int p,int s){
    if(f != p && p!= s && s!=f && p%2==0){
        return true;
    }else
    {
        return false;
    }
    
}

int main(void){
    for(int fNO=1;fNO<=7;fNO++){
        for(int PNO=0;PNO<=7;PNO++){
            for(int sNO=0;sNO<=7;sNO++){
                if(isValidNo(fNO,PNO,sNO)){
                    cout<<"Fire dept No: "<<fNO<<" "<<"Police Dept No: "<<PNO<<" "<<"Sanitation dept NO: "<<sNO<<endl;
                }
            }
        }
    }
    return 0;
}