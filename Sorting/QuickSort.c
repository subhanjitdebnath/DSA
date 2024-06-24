#include <stdio.h>

//Swap
void Swap(int *a,int *b)
{
    int temp =*a;
    *a = *b;
    *b = temp;
}
//Partition Function
int Partition(int a[],int low,int high)
{
    int i=low - 1;
    int pivot = a[high];
    for(int j=low;j<high;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            Swap(&a[i], &a[j]);
        }
    }
    i++;
    Swap(&a[i], &a[high]);
    return i;
}
//Quick Sort
void quickSort(int a[],int low, int high)
{
    if(low<high)
    {
        int p = Partition(a, low, high);
        quickSort(a, p+1, high);
        quickSort(a, low, p-1);
    }
}
//Print Array
void PrintArray(int a[],int len)
{
    for(int i=0;i<len;i++)
    {
        printf(" %d",a[i]);
    }
}

int main()
{
    int a[]={6,8,7,9,4,5,1,2,3,6,5,2,4,7,8,9,8,4,7,1,0,2,5,8},len;
    len = sizeof(a)/sizeof(int);
    printf("Before sort\n");
    PrintArray(a, len);
    quickSort(a, 0, len-1);
    printf("\nAfter sort\n");
    PrintArray(a, len);
}