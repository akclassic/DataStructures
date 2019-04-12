//Counting Sort
#include <iostream>
using namespace std;

void countSort(int *arr, int n)
{
    //find max element int the array
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int count[max + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    // for(int i=0;i<(max+1);i++){
    //     cout<<count[i]<<" ";
    // }

    //calculate the next index
    // Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for (int i = 1; i <= n; ++i)
    {
        count[i] += count[i - 1];
    }

    int output[n] = {0};

    for (int i = 0; i < n; ++i)
    {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    for (int i = 0; i < n; ++i)
    {
        arr[i] = output[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main(void)
{
    int arr[] = {5, 5, 2, 3, 9, 9, 9, 7, 6, 4, 1, 1};
    int n = sizeof(arr) / sizeof(int);
    countSort(arr, n);
    return 0;
}