/* Double-Click To Select Code */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void heapsort(float array[], int n);
void heapify(float array[], int n);
void adjust(float array[], int n);
 
void heapsort(float array[], int n)
{
 int i;
 float t;
 
 heapify(array,n);
 
 for(i=n-1 ; i>0 ; i--)
 {
  t = array[0];
  array[0] = array[i];
  array[i] = t;
  adjust(array,i);
 }
}
 
 
void heapify(float array[], int n)
{
 float item;
 int i,j,k;
 
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
 
void adjust(float array[], int n)
{
       float item;
       int i,j;
       
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


void huffmanCode(char* symbols,float* freq,int** Code){
  float matrixaux[strlen(symbols)][2];
  float arrayAux[strlen(symbols)];
  int i;

  for(i=0;i<strlen(symbols);i++){
      matrixaux[i][0] = symbols[i];
      matrixaux[i][1] = freq[i];
      arrayAux[i]=freq[i];
  }

  heapsort(arrayAux,6);
  for(i = 0; i < strlen(symbols); i++)
 {
  printf("\n %4f", arrayAux[i]);
 }



}




int main()
{
 int *array;
 int n,i;
 char  symbols[6]={'a','b','c','d','e','f'};
 float freq[6] = {0.22,0.03,0.14,0.14,0.41,0.06};
int * Code;
int tamanh = sizeof(freq)/sizeof(float);
Code = (int*)malloc(tamanh*sizeof(int));

printf("tamanho do code %d",tamanh);

huffmanCode(symbols,freq,&Code);
/*
 array = (int*)malloc(200*sizeof(int)); 
 
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
 printf("size of array %lu",sizeof(array));
 free(array);*/
 
 return 0;
}