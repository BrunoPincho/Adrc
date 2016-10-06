/* Double-Click To Select Code */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void heapsort(float array[], int n);
void heapify(float array[], int n);
void adjust(float array[], int n);
int arraysize;

struct node{
  float key_value;
  int level;
  struct node*left;
  struct node*right;
  struct node*up;
};
  struct node* filho1;
  struct node* filho2;
  struct node* Parente;
  struct node *leaf;
 
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

void removeNodeHeap(float array[],float Toremove,int length){
  int i;
  

  for(i=0;i<length;i++){
    if(array[i]==Toremove){
      array[i] = -1;
      heapsort(array,length);
      break;
    }

  }

}

void huffRecursivo(float array[],struct node *leaf){
  int i,j,k;
  struct node* nodoactual=0;
  struct node* aux=0;
  float minpar1,minpar2,ancestral;

    if( leaf == 0 ){
      minpar1 = array[0];
      minpar2 = array[1];
      removeNodeHeap(array,array[0],6);
      removeNodeHeap(array,array[1],6);
      ancestral = minpar1 + minpar2;
      
      Parente = (struct node*) malloc( sizeof( struct node ) );
      Parente->key_value=ancestral;  
      printf("%f\n",Parente->key_value );

      Parente->left = 0;    
        Parente->right = 0;
        Parente->up = 0;
        

      filho1 = (struct node*) malloc( sizeof( struct node ) );  
      filho2 = (struct node*) malloc( sizeof( struct node ) );
        filho2->left = 0;   
        filho1->left = 0;  
        filho1->right = 0;
        filho2->right = 0;
        filho2->up = Parente;
        filho1->up = Parente;
        filho1->key_value = minpar1;
        filho2->key_value = minpar2;

        Parente->left = filho1;    
        Parente->right = filho2;
        leaf = Parente;
        
        huffRecursivo(array,leaf);
        
    }else{
        for(i=0;i<6;i++){
          if(array[i]<((leaf)->key_value) && array[i+1]>((leaf)->key_value) && array[i]>0){
              ancestral = array[i] + ((leaf)->key_value);
              minpar1 = array[i];
              removeNodeHeap(array,array[i],6);
              Parente = (struct node*) malloc( sizeof( struct node ) );
              Parente->key_value = ancestral;  
              printf("%f\n",Parente->key_value );

              filho1 = (struct node*) malloc( sizeof( struct node ) );
              filho1->left = 0;  
              filho1->right = 0;
              filho1->up = Parente;
              filho1->key_value = minpar1;
              Parente->left = filho1;    
              Parente->right = leaf;

              Parente->up = 0;
              (leaf)->up = Parente;
              leaf = Parente;
              huffRecursivo(array,leaf);
          }
          
          if(array[i] > ((leaf)->key_value) && (array[i]-((leaf)->key_value))<5) {
              ancestral = array[i] + ((leaf)->key_value);
              minpar2 = array[i];
              removeNodeHeap(array,array[i],6);
              Parente = (struct node*) malloc( sizeof( struct node ) );
              Parente->key_value = ancestral;  
              printf("%f\n",Parente->key_value );

              filho2 = (struct node*) malloc( sizeof( struct node ) );
              filho2->left = 0;  
              filho2->right = 0;
              filho2->up = Parente;
              filho2->key_value = minpar2;
              Parente->right = filho2;    
              Parente->left = leaf;
              Parente->up = 0;
              (leaf)->up = Parente;
              leaf = Parente;

              huffRecursivo(array,leaf);
          } 
          
          if(array[i]<((leaf)->key_value) && array[i+1]<((leaf)->key_value) && array[i]>0){
              
              ancestral = array[i] + array[i+1];
              minpar1 = array[i];
              minpar2 = array[i+1];
              removeNodeHeap(array,array[i],6);
              
              Parente = (struct node*) malloc( sizeof( struct node ) );
              Parente->key_value = ancestral;  
              printf("%f\n",Parente->key_value );

              if((i+1)<=arraysize){

              removeNodeHeap(array,array[i+1],6);
              filho1 = (struct node*) malloc( sizeof( struct node ) );
              filho1->left = 0;  
              filho1->right = 0;
              filho1->up = Parente;
              filho1->key_value = minpar1;

                  
                filho2 = (struct node*) malloc( sizeof( struct node ) );
                filho2->left = 0;  
                filho2->right = 0;
                filho2->up = Parente;
                filho2->key_value = minpar2;

                Parente->right = filho2;
                Parente->left = filho1;
              }else{
                  Parente->right = 0;
                  Parente->left = 0;
                }    
              

              ancestral = (leaf->key_value) + (Parente->key_value);

              aux = (struct node*) malloc( sizeof( struct node ) );
              aux->key_value = ancestral;
              leaf->up = aux;
              Parente->up = aux;

                if((leaf->key_value)>(Parente->key_value)){
                    aux->left=Parente;
                    aux->right=leaf;
                }else{
                    aux->left=leaf;
                    aux->right=Parente;  
                }
                leaf = aux;
            }        
        }
    }
}


void huffmanCode(char* symbols,float* freq,int** Code){
  float matrixaux[strlen(symbols)][2];
  float arrayAux[strlen(symbols)];
  struct node* doot=0;
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

     //removeNodeHeap(arrayAux,arrayAux[0],strlen(symbols));
     //removeNodeHeap(arrayAux,arrayAux[5],strlen(symbols));
     puts("\n apos remoção\n");
     for(i = 0; i < strlen(symbols); i++)
     {
      printf("\n %4f", arrayAux[i]);
     }


     huffRecursivo(arrayAux,doot);
}




int main()
{
 int *array;
 int n,i;
 char  symbols[6]={'a','b','c','d','e','f'};
 float freq[6] = {0.22,0.03,0.14,0.14,0.41,0.06};
 arraysize = 6;
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