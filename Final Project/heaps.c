#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void printArray(int *arr,int n){
int i=0;
while(n--) printf("[%d] ",arr[i++]);
printf("\n");
}
void showHeap(int arr[],int n){
char format[]=" %3d/%d";int y=6,i,j,jj;
printf("\n--------\n");
int levels=(int)log2(n)+1;
int ls=1,k=0;int st=1<<(levels-1);
printf("Number of levels %d\n",levels);
for ( i=0;i<levels;i++){printf("level %d",i);
for ( j=0;j<(st-1)*y/2;j++) printf(" ");
for ( j=0;j<ls;j++) {printf(format,arr[k],k);k++;
for ( jj=0;jj<(st-1)*y;jj++) printf(" ");

if (k==n)break;}

printf("\n");
ls<<=1; st>>=1;
}
printf("\n--------\n");
}
#define swap(x,y) {int temp=x;x=y;y=temp;}
void heapifyDown(int *arr,int n){
int i;
for ( i = 1; i < n; i++)
// if child is bigger than parent
if (arr[i] > arr[(i-1)/2])
{ int j = i;
// swap child and parent until parent is smaller
while (arr[j] > arr[(j-1)/2])
{
swap(arr[j], arr[(j-1)/2]);
j = (j-1)/2;
}
}
}
void heapSort(int arr[],int n){ // 0 base indexing
int i;heapifyDown(arr, n);
printArray(arr,n);
showHeap(arr,n);
for (i = n - 1; i > 0; i--)
{
// swap value of first indexed with last indexed
swap(arr[0], arr[i]);
// maintaining heap property after each swapping


int j = 0, index;
do
{
index = (2 * j + 1);
// if left child is smaller than right child point to right
if (arr[index]<arr[index + 1] && index < (i - 1))index++;
// if parent is smaller than child then swap parent with child
if (arr[j]<arr[index] && index < i) swap(arr[j], arr[index]);
j = index;
} while (index < i);
}
}

