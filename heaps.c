/* Double-Click To Select Code */
 
#include<stdio.h>

 
void heapsort(int[], int);
void heapify(int[], int);
void adjust(int[], int);
 

 
void heapsort(int array[], int n)
{
 int i,t;
 
 heapify(array,n);
 
 for(i=n-1 ; i>0 ; i--)
 {
  t = array[0];
  array[0] = array[i];
  array[i] = t;
  adjust(array,i);
 }
}
 
 
void heapify(int array[], int n)
{
 int item,i,j,k;
 
 for(k=1 ; k<n ; k++)
 {
  item = array[k];
  i = k;
  j = (i-1)/2;
 
  while( (i>0) && (item>array[j]) )
  {
   array[i] = array[j];
   i = j;
   j = (i-1)/2;
  }
  array[i] = item;
 }
}
 
void adjust(int array[], int n)
{
       int item,i,j;
       
       j = 0;
       item = array[j];
       i = 2*j+1;
       
            while(i<=n-1)
           {
            if(i+1 <= n-1)
             if(array[i] < array[i+1])
              i++;
            if(item < array[i])
            {
             array[j] = array[i];
             j = i;
             i = 2*j+1;
            }
            else
             break;
           }
       array[j] = item;
}

int main()
{
 int array[50],n,i;
 
 
 printf("Enter the no. of elements to be sorted: ");
 scanf("%d",&n);
 
 printf("\nEnter the elements: \n");
 for(i=0 ; i<n ; i++)
 scanf("%d",&array[i]);
 
 printf("\nBefore Heapsort:");  //Array Before Mergesort
 for(i = 0; i < n; i++)
 {
  printf("%4d", array[i]);
 }
 printf("\n");
 
 heapsort(array,n);
 
 printf("\nAfter Heapsort:");  //Array After Mergesort
 for(i = 0; i < n; i++)
 {
  printf("%4d", array[i]);
 }
 printf("\n");
 
 return 0;
}