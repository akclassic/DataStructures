//quicksort
#include <iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

void randomize(int *arr,int s,int e){
    srand(time(NULL));
    int i,j,temp;
    for(i=e;i>0;i--){
        //create a random index
        j = rand()%(i+1);
        swap(arr[i],arr[j]);
    }
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do 
        {
            j--;
        }while(arr[j] > pivot);
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j; // return the pivot position
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main(void)
{

    int arr[] = {10, 16, 8, 12, 15, 6, 9, 5,INT16_MAX};
    int n = sizeof(arr) / sizeof(int);
    randomize(arr,0,n-1);
    quickSort(arr, 0, n - 1);
    //print the sorted array
    for (int i = 0; i < n-1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}