#include <stdio.h>

//Swap
void Swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Max Heap Function
void Heapify(int a[],int len,int i)
{
    int large = i;
    int l = 2*i+1 , r=2*i+2 ;

    if(l<len && a[large] < a[l])
    {
        large = l;
    }
    if(r<len && a[large] < a[r])
    {
        large = r;
    }
    if(large != i)
    {
        Swap(&a[i], &a[large]);
        Heapify(a, len, large);
    }
}
//HeapSort
void Heapsort(int a[],int len)
{
    for(int i=(len/2)-1;i>=0;i--)
    {
        Heapify(a, len, i);
    }
    for(int i=len-1;i>0;i--)
    {
        Swap(&a[i], &a[0]);
        Heapify(a, i, 0);
    }
}

//Utility
void PrintArray(int a[],int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%d ",a[i]);
    }
}

int main()
{
    int a[]={8,7,5,4,2,9,4,7,3,5,16},len;
    len = sizeof(a)/sizeof(int);
    printf("Before Swap\n");
    PrintArray(a, len);
    Heapsort(a, len);
    printf("\nAfter Swap\n");
    PrintArray(a, len);


    return 0;
}