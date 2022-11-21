#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
using namespace std;

bool isSortedAsc(int arr[],int leng)
{
    for(int i=0; i<leng-1; i++)
    {
        if(arr[i]>arr[i+1])return false;
    }
    return true;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void quicksort(int arr[], int low, int high)
{
    if(low<high)
    {
        int i=low-1,j=low;
        int p=arr[high];

        for(; j<high; j++)
        {
            if(arr[j]<p)
            {
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[high]);
        int middle = i+1;
        quicksort(arr,low,middle-1);
        quicksort(arr,middle+1,high);
    }
}

void bubblesort(int arr[], int leng)
{
    int iteration=0;
    while(!isSortedAsc(arr,leng))
    {
        iteration++;
        for(int i=0; i<leng; i++)
        {
            if(arr[i+1]<arr[i])
            {
                swap(arr[i+1],arr[i]);
            }
        }
    }
}

int main() {

    int n=20000;
    int losowa[n];
    int posortowana[n];
    int odwrotna[n];
    int tmp[n];

    struct timeval time_now{};
    time_t msecs_time_start;
    time_t msecs_time_end;

    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        losowa[i]=(rand()%1500);
    }
    for(int i=0; i<n; i++)
    {
        posortowana[i]=i;
    }
    for(int i=n-1, j=0; j<n; i--,j++)
    {
        odwrotna[j]=i;
    }

    /////////////////////////////////HEAP_SORT////////////////////////////////////////////////////////////////////////
    for(int i=0; i<n; i++)
    {
        tmp[i]=losowa[i];
    }
    gettimeofday(&time_now, nullptr);
    msecs_time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<"Losowa Heap-sort:";
    heapSort(tmp,n);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<msecs_time_end-msecs_time_start<<endl;

    for(int i=0; i<n; i++)
    {
        tmp[i]=posortowana[i];
    }
    gettimeofday(&time_now, nullptr);
    msecs_time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<"Posortowana Heap-sort:";
    heapSort(tmp,n);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<msecs_time_end-msecs_time_start<<endl;

    for(int i=0; i<n; i++)
    {
        tmp[i]=odwrotna[i];
    }
    gettimeofday(&time_now, nullptr);
    msecs_time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<"Odwrotna Heap-sort:";
    heapSort(tmp,n);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<msecs_time_end-msecs_time_start<<endl;
    ///////////////////////////////////QUICK_SORT////////////////////////////////////////////////////////
    for(int i=0; i<n; i++)
    {
        tmp[i]=losowa[i];
    }
    gettimeofday(&time_now, nullptr);
    msecs_time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<"Losowa Quick-sort:";
    quicksort(tmp,0,n-1);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<msecs_time_end-msecs_time_start<<endl;

    for(int i=0; i<n; i++)
    {
        tmp[i]=posortowana[i];
    }
    gettimeofday(&time_now, nullptr);
    msecs_time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<"Posortowana Quick-sort:";
    quicksort(tmp,0,n-1);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<msecs_time_end-msecs_time_start<<endl;

    for(int i=0; i<n; i++)
    {
        tmp[i]=odwrotna[i];
    }
    gettimeofday(&time_now, nullptr);
    msecs_time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<"Odwrotna Quick-sort:";
    quicksort(tmp,0,n-1);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<msecs_time_end-msecs_time_start<<endl;
    ///////////////////////////BUBLE_SORT/////////////////////////////////////
    for(int i=0; i<n; i++)
    {
        tmp[i]=losowa[i];
    }
    gettimeofday(&time_now, nullptr);
    msecs_time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<"Losowa Buble-sort:";
    bubblesort(tmp,n);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<msecs_time_end-msecs_time_start<<endl;

    for(int i=0; i<n; i++)
    {
        tmp[i]=posortowana[i];
    }
    gettimeofday(&time_now, nullptr);
    msecs_time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<"Posortowana Buble-sort:";
    bubblesort(tmp,n);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<msecs_time_end-msecs_time_start<<endl;

    for(int i=0; i<n; i++)
    {
        tmp[i]=odwrotna[i];
    }
    gettimeofday(&time_now, nullptr);
    msecs_time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<"Odwrotna Buble-sort:";
    bubblesort(tmp,n);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<msecs_time_end-msecs_time_start<<endl;
}



