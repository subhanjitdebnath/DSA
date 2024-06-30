#include <stdio.h>
#include <stdio.h>

//Swap
void Swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Partition Function
int Parttion(int a[],int low, int high)
{
    int i = low -1;
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
void quicksort(int a[],int low, int high)
{
    if(low<high)
    {
        int p = Parttion(a, low, high);
        quicksort(a, p+1, high);
        quicksort(a, low , p-1);
    }
}

//Utility
void PrintArray(int a[],int len)
{
    for(int i=0;i<len;i++)
    {
        printf(" %d",a[i]);
    }
}

int main()
{
    int a[]={8,5,7,9,6,4,2,1,5,8,9,6,4,7,1,2},len;
    len = sizeof(a)/sizeof(int);

    printf("Before Sort\n");
    PrintArray(a, len);
    quicksort(a, 0,len-1);
    printf("\nAfter Sort\n");
    PrintArray(a, len);


    return 0;
}