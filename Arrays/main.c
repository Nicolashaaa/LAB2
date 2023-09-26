#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void BubbleSort(int a[],int n){
int i, j, temp, flag;
for(i=n-1; i>0; i--)/*This loop will be executed n times after each changed array in the next loop*/
{
flag = 1;/*The variable is needed to interrupt the
             loop prematurely in the future*/

for(j=0; j<i; j++)/*This is the second loop that goes through the array once in the end of which the
                    largest variable of the array is assigned to the last index of the array */
{
if(a[j]>a[j+1]) /*This is the condition by which the array variables are swapped,
                   thanks to the third variable temp*/
{
flag = 0;
temp = a[j];
a[j] = a[j+1];
a[j+1] = temp;
}
}
/*out this block when flag is true
i.e. inner loop performed no swaps, so the list is already sorted*/
if(flag)
break;
}
}
void SelectionSort(int a[], int n){
int i, j, min, imin;
for (i = 0; i < n-1; i++)
{
min = a[i];/*assign the first element of the array to the minimum number
               (then to the second element of changed array and    etc. : i++)*/
imin = i; /*same with index*/

for (j = i+1; j < n; j++) /*The loop starts from the second element,
                                because the first is assigned like min*/
{
if (a[j] < min)   /*The condition: when true change min element and min index*/
{
min = a[j];
imin = j;
}
}
a[imin] = a[i];/*swap elements min goes to the head,
                    but a[i] goes to the j element after condition*/
a[i] = min;
}
}
void InsertionSort(int a[ ], int n) {
int i, j, value;
for(i = 1; i < n; i++) { /*Start iterating from the second element (index 1)
                                 to the last element in the array*/
value = a[i];  /*use value which will be shifted and
                 be compared with other elements of array */
for (j = i - 1; (j >= 0) && (value< a[j]); j--) {
a[j + 1] = a[j];
}
a[j+1] = value;
}
}
void QuickSort(int number[], int first, int last) {
   int i, j, pivot, temp;

   /* Check if there is more than one element in the subarray.*/
   if (first < last) {
      /* Choose the first element as the pivot.*/
      pivot = first;
      i = first;
      j = last;

      /* Partitioning phase: Rearrange elements such that elements smaller than the pivot
         are on the left side, and elements greater than the pivot are on the right side.*/
      while (i < j) {
         /*Find an element greater than or equal to the pivot from the left.*/
         while (number[i] <= number[pivot] && i < last)
            i++;

         /* Find an element less than the pivot from the right.*/
         while (number[j] > number[pivot])
            j--;

         /* Swap elements if they are out of place.*/
         if (i < j) {
            temp = number[i];
            number[i] = number[j];
            number[j] = temp;
         }
      }

      /* Swap the pivot element with the element at index 'j'.*/
      temp = number[pivot];
      number[pivot] = number[j];
      number[j] = temp;

      /* Recursively apply QuickSort to the left and right subarrays.*/
      QuickSort(number, first, j - 1);
      QuickSort(number, j + 1, last);
   }
}
void printArray(int a[], int size) {int i;
  for (i = 0; i < size; ++i) {
    printf( "a[%d]=%d ",i,a[i]);
  }
  printf("\n");
}
void randArray(int a[],int n){int i;
    for (i = 0; i < n; i++) {
            a[i]=rand()% 101 - 50;
}
}
int main()
{
     clock_t start, end;
     double cpu_time_used;
     int n;
n=10;
    int a[n];
randArray(a,n);
printf( "Unsorted array: ");
printArray(a,n);
start = clock();
BubbleSort(a,n);
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("BubbleSort usage time: %f sec\n",cpu_time_used);

printf( "\n\nSorted by BubbleSort array: ");
printArray(a,n);
randArray(a,n);
printf( "\n\nUnsorted array: ");
printArray(a,n);
start = clock();
SelectionSort(a,n);
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("SelectionSort usage time: %f sec\n",cpu_time_used);


printf( "\n\nSorted by SelectionSort array: ");
printArray(a,n);
randArray(a,n);
printf( "\n\nUnsorted array: ");
printArray(a,n);
start = clock();
InsertionSort(a,n);
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("InsertionSort usage time: %f sec\n",cpu_time_used);
printf( "\n\nSorted by InsertionSort array: ");
printArray(a,n);
randArray(a,n);
printf( "\n\nUnsorted array: ");
printArray(a,n);
start = clock();
QuickSort(a,0,n-1);
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("QuickSort usage time: %f sec\n",cpu_time_used);
printf( "\n\nSorted by QuickSort array: ");
printArray(a,n);

return 0;
}
