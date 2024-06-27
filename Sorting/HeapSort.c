#include <stdio.h>

//swap
void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

//Heapify the array -> Max Heap

void MaxHeap(int a[],int len, int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<len && a[l]>a[largest])
    {
        largest = l;
    }
    if(r<len && a[r]>a[largest])
    {
        largest = r;
    }

    if(i!=largest)
    {
        swap(&a[largest], &a[i]);
        MaxHeap(a, len, largest);
    }
}

//Heap Sort

void HeapSort(int a[],int len)
{
    for(int i=(len/2)-1;i>=0;i--)
    {
        MaxHeap(a, len, i);
    }

    for(int i=len-1;i>0;i--)
    {
        swap(&a[i], &a[0]);
        MaxHeap(a, i, 0);
    }
}

void Printarray(int a[],int len)
{
    for(int i=0;i<len;i++)
    {
        printf(" %d",a[i]);
    }
}

int main()
{
    int a[]={6,8,7,9, 4, 5, 1, 2, 3, 6, 5, 2, 4, 7, 8, 9, 8, 4, 7, 1, 0, 2, 5, 8},len;
    len = sizeof(a)/sizeof(int);
    printf("Before Heapsort\n");
    Printarray(a, len);
    HeapSort(a, len);
    printf("\nAfter Heapsort\n");
    Printarray(a, len);
}
