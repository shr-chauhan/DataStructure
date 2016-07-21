#include<iostream>

using namespace std;

/*
void swap(int x, int y)
{
    int temp=x;
    x=y;
    y=temp;
}
*/

void swap(int *a, int *b)
{
   int temp;

   temp = *b;
   *b   = *a;
   *a   = temp;
}


void heapify(int a[], int i, int n)
{
int largest = i;
int l=2*i + 1;
int r=2*i + 2;

if(l<n && a[largest] < a[l])
largest = l;

if(r<n && a[largest] < a[r])
largest = r;

if(largest!=i)
{
swap(&a[i],&a[largest]);
heapify(a,largest,n);
}

}



void heapSort(int a[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    heapify(a,i,n);

    for(int j=n-1;j>=0;j--)
    {
        swap(&a[0],&a[j]);
        heapify(a,0,j);
    }

}

void printArray(int a[],int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}


int main()
{
    int a[]={2,6,3,1,5};
    printArray(a,5);
    heapSort(a,5);
    cout<<endl;
    printArray(a,5);
}
