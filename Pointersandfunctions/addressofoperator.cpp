#include<iostream>

using namespace std;

int main(){
    // int n=9;
    float y=4.4;
    char s='A';

    // cout<<&n<<endl;
    // cout<<&y<<endl;
    // cout<<&s<<endl;
    // cout<<(void *)&s<<endl;

    //store address in a pointer var
    // int *ptrint = &n;
    float* ptrfloat = &y;
    char* ptrchar = &s;

    // cout<< ptrint<<endl;
    // cout<< ptrfloat<<endl;
    // cout<< ptrchar<<endl;


    int n = 4;
    int* nptr = &n;
    //double pointer
    int** nnptr = &nptr;

    cout<<"&n : "<<&n<<endl;
    cout<<"nptr : "<<nptr<<endl;
    cout<<"&nptr : "<<&nptr<<endl;
    cout<<"nnptr : "<<nnptr<<endl;
    cout<<"*(&nptr) : "<<*(&nptr)<<endl;
    cout<<"&(*nptr): "<<&(*nptr)<<endl;
    cout<<"*nptr: "<<*nptr<<endl;
    cout<<"*nnptr: "<<*nnptr<<endl;


    cout<<endl;
    return 0;
}