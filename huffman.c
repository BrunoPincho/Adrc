#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void heapsort(float array[], int n);
void heapify(float array[], int n);
void adjust(float array[], int n);
int arraysize;
float minimo;
struct node{
  float key_value;
  int level;
  int id;
  int used;
  int rootVal;
  int seen;
  struct node*left;
  struct node*right;
  struct node*up;
};
  struct node* filho1;
  struct node* filho2;
  struct node* Parente;
  struct node *leaf;
  struct node *root;
  struct node *actual;
  struct node *lowest;
///maxheap

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
     
      while( (i>0) && (item<array[j]) )
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
             if(array[i] > array[i+1])
              i++;
            if(item > array[i])
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


void encontraActual(struct node *node,int nodeid){
	struct node * aux;
	if (node->id == nodeid)
	{
		actual = node;
	}

	if(node->left != 0){
	    encontraActual(node->left,nodeid);
	}
	if(node->right != 0){
		encontraActual(node->right,nodeid);
	}


}



void Creategraph(float* array,int size){
	int i;
	int nodeid=0,ultimoId=0;
	struct node *aux;

	for(i=0;i<size;i++){
		if(i==0 && (2*i+1)<size){ 
		 Parente = (struct node*) malloc( sizeof( struct node ));
		 filho1 = (struct node*) malloc( sizeof( struct node ) );  
     	 filho2 = (struct node*) malloc( sizeof( struct node ) );
     	 Parente->key_value = array[i];  
      	 filho1->key_value = array[2*i+1];
      	 filho2->key_value = array[2*i+2];

	        Parente->left = filho1;    
	        Parente->right = filho2;
	        Parente->up = 0;
	        
	        filho1->up = Parente;
	        filho2->up = Parente;
	        
	        filho1->left = 0; 
	        filho1->right = 0;
	        
	        filho2->left = 0; 
	        filho2->right = 0;

	        nodeid ++;
	        filho1->id = nodeid;
	        
	        filho2->id = nodeid +1;
	        ultimoId = filho2->id;
	        root = Parente;

     	 } else if((2*i+1)<size && i!=0){
     	 	encontraActual(root,nodeid);
		 	filho1 = (struct node*) malloc( sizeof( struct node ) );

		 	filho1->key_value = array[2*i+1];
		 	filho1->left = 0; 
	        filho1->right = 0;
	        filho1->id = ultimoId + 1;
	        ultimoId++;
	        filho1->up = actual;
	        
	        if(actual->left==0){
	     	   actual->left = filho1;
	    	}else{
	    		aux=actual->left;
	    		if(aux->key_value > filho1->key_value){
	    				actual->right = filho1;
	    		}else{
	    				actual->left = filho1;
	    		}

	    	} 

	    	if((2*i+2)<size && (actual->left == 0 || actual->right == 0)){

	        	filho2 = (struct node*) malloc( sizeof( struct node ) );
				filho2->key_value = array[2*i+2];
		 		filho2->left = 0; 
	        	filho2->right = 0;
	        	filho2->id = ultimoId + 1;
	        	ultimoId++;
	        	filho2->up = actual;
	        	if(filho2->key_value > filho1->key_value){
	    				actual->left = filho2;
	    				actual->right = filho1;
	    		}else{
	    				actual->right = filho2;
	    				actual->left = filho1;
	    		}
	        }
	        nodeid ++;

     	 }

	}
	root->rootVal=1;



}

void encontraMinimo(struct node *node){
	
	if ((node->key_value <= minimo) && (node->used ==0) )
	{
		lowest = node;
		minimo = (lowest)->key_value;
	}
	if(node->left != 0){
	    encontraMinimo(node->left);
	}
	if(node->right != 0){
		encontraMinimo(node->right);
	}


}
int indexo;
int found=0;
void codify(struct node *node,char **code,float freq,int* codeaux){
	//passar isto para fora da função
	//char *code;
	//code = (char*)malloc(256*sizeof(char));
	int i;

	
	if (node->left==0 && node->right==0 && node->seen==0)
	{
		
		
			node->seen=1;
			indexo--;					
		return;
	}

	if(node->left != 0){
		codeaux[indexo]=0;
		indexo++;
	    codify(node->left,code,freq,codeaux);
	}

	

	if(node->right != 0){
		codeaux[indexo]=1;
		indexo++;
		codify(node->right,code,freq,codeaux);
	}
	indexo--;

}

void BuildHuffman(char* symbols,float* freq){
/* neste contexto as variaveis globais filho1 = nodo mais pequena, filho2 = segundo nodo mais pequena */
struct node* aux=0;
struct node* aux2=0;
actual = 0;
int i;
char *code;
code = (char*)malloc(256*sizeof(char));


float matrixaux[strlen(symbols)][2];
float arrayAux[strlen(symbols)];

for(i=0;i<strlen(symbols);i++){
          matrixaux[i][0] = symbols[i];
          matrixaux[i][1] = freq[i];
          
      }


 heapsort(freq,10);
 Creategraph(freq,10);
minimo = root->key_value;
	while(root->key_value != 1){

		//encontra os minimos
		for(i=0;i<2;i++){
			encontraMinimo(root);
			if(i==0){
				filho1 = lowest;
				filho1->used = 1;
			}else{
				filho2 = lowest;
				filho2->used = 1;	
			}
			minimo = 1;
		}
				
		//soma ou faz subgrafo
		aux = filho2->up;
		aux2 = filho1->up;
		Parente = (struct node*) malloc( sizeof( struct node ));
		Parente->key_value = filho1->key_value + filho2->key_value;

		if(aux != filho1){
			Parente->up = aux;
		}else{
			Parente->up = aux2;
		}
		Parente->left = filho1;
		Parente->right = filho2;
		Parente->level=1;
		filho1->up=Parente;
		filho2->up=Parente;

		if(filho2->rootVal==1 || filho1->rootVal==1){
			Parente->rootVal=1;
			root = Parente;
			Parente->up = 0;
			
		}

		if(aux != 0 && aux->left == filho2){
				if(Parente->key_value!=1 && aux->up != Parente){
					aux->left = Parente;
				}else{
					aux->left = 0;
				}
			
			
			if(aux->right == filho1){
				aux->right = 0;
			}
		}else if(aux!=0){
			aux->right = Parente;
		}

		if(aux2 != 0 && aux2->left == filho1){
			if(Parente->up != aux2){
				aux2->left = 0;
			}else if(Parente->key_value!=1 && aux2->up != Parente){
				aux2->left=Parente;
			}
			if(aux2->right > 0){
				aux2->left = aux2->right;
				aux2->right = 0;
			}
		}else if(aux2!=0 && aux2->right == filho1){
			aux2->right = 0;
		}

		
		//update no actual


	}

	//fazer o codigo em si
	int codigo[256];
	
	for(i=6;i>=0;i--){
		codify(root,&code,freq[i],codigo);
		indexo=0;
		found=0;
	}


	//

}



int main()
{

 int n,i;
 char *Code;
 char  symbols[7]={'a','b','c','d','e','f','g'};
 //float freq[6] = {0.25,0.05,0.1,0.15,0.2,0.25};
 //float freq[6] = {0.22,0.03,0.14,0.14,0.41,0.06};
 //float freq[7] = {0.25,0.05,0.05,0.15,0.1,0.3,0.1};
 float freq[10] = {0.01,0.02,0.04,0.04,0.09,0.1,0.1,0.11,0.11,0.38};
 arraysize = 6;

int tamanh = sizeof(freq)/sizeof(float);
//Code = (int*)malloc(tamanh*sizeof(int));

printf("\n antes ");  //Array After Mergesort
  
for(i = 0; i < 10; i++)
 {
  printf("\n%f \n", freq[i]);
 }

 BuildHuffman(symbols,freq);

 printf("\n");
//Array After Mergesort
 for(i = 0; i < 10; i++)
 {
  printf("%f \n", freq[i]);
 }
 
 return 0;
}