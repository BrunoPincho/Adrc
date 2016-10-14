#include "huffman.h"




  void heapsort(float array[][2], int n)
{
 int i;
 float t;
 float simbol;
 
 heapify(array,n);
 
 for(i=n-1 ; i>0 ; i--)
 {

  simbol = array[0][0];
  array[0][0] = array[i][0];
  array[i][0] = simbol;
  	
  t = array[0][1];
  array[0][1] = array[i][1];
  array[i][1] = t;
  
  adjust(array,i);
 }
}
 
 
void heapify(float array[][2], int n)
{
 float item;
 float simbol;
 int i,j,k;
 
     for(k=1 ; k<n ; k++)
     {
      item = array[k][1];
      simbol = array[k][0];
      i = k;
      j = (i-1)/2;
     
      while( (i>0) && (item<array[j][1]) )
      {
       array[i][1] = array[j][1];
       array[i][0] = array[j][0];
       i = j;
       j = (i-1)/2;
      }
      array[i][1] = item;
      array[i][0] = simbol;
     }
}
 
void adjust(float array[][2], int n)
{
       float item;
       float simbol;
       int i,j;
       
       j = 0;
       item = array[j][1];
       simbol = array[j][0];
       i = 2*j+1;
       
            while(i<=n-1)
           {
            if(i+1 <= n-1)
             if(array[i][1] > array[i+1][1])
              i++;
            if(item > array[i][1])
            {
             array[j][1] = array[i][1];
             array[j][0] = array[i][0];
             j = i;
             i = 2*j+1;
            }
            else
             break;
           }
       array[j][1] = item;
       array[j][0] = simbol;
}


void encontraActual(struct node *node,int nodeid){
	
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



void Creategraph(float array[][2],int size){
	int i;
	int nodeid=0,ultimoId=0;
	struct node *aux;

	for(i=0;i<size;i++){
		if(i==0 && (2*i+1)<size){ 
		 Parente = (struct node*) malloc( sizeof( struct node ));
		 filho1 = (struct node*) malloc( sizeof( struct node ));  
     	 filho2 = (struct node*) malloc( sizeof( struct node ));
     	 Parente->key_value = array[i][1];  
      	 filho1->key_value = array[2*i+1][1];
      	 filho2->key_value = array[2*i+2][1];

      	 //simbolos
      	 Parente->symbol = array[i][0];  
      	 filho1->symbol = array[2*i+1][0];
      	 filho2->symbol = array[2*i+2][0];
      	 //

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

		 	filho1->key_value = array[2*i+1][1];
		 	filho1->symbol = array[2*i+1][0];
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
				filho2->key_value = array[2*i+2][1];
				filho2->symbol = array[2*i+2][0];
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
void codify(struct node *node,int* codeaux){
	//passar isto para fora da função
	//char *code;
	//code = (char*)malloc(256*sizeof(char));
	int k;
	struct stack* temp;
	
	if (node->left==0 && node->right==0 && node->seen==0)
	{
		
			temp = (struct stack*)malloc(sizeof(struct stack));
			temp->codificacao = (int*)malloc(indexo*sizeof(int));
				//enche o array do codigo
				for(k=0;k<indexo;k++){
					temp->codificacao[k]=codeaux[k];
				}
				

				temp->codificacao[indexo]=-1;
				temp->codesize = indexo;
				//
			temp->simbolo = node->symbol;
			temp->frequencia = node->key_value;
			if(stack!=0){
				temp->next = stack;
				stack = temp;
			}else{
				temp->next = NULL;
				stack = temp;
			}

			node->seen=1;
			indexo--;					
		return;
	}

	if(node->left != 0){
		codeaux[indexo]=0;
		indexo++;
	    codify(node->left,codeaux);
	}

	

	if(node->right != 0){
		codeaux[indexo]=1;
		indexo++;
		codify(node->right,codeaux);
	}
	indexo--;

}

void HuffmanCode(char* symbols,float* freq,struct stack** output){
/* neste contexto as variaveis globais filho1 = nodo mais pequena, filho2 = segundo nodo mais pequena */
struct node* Pai_smallest=0;
struct node* Pai_2nd=0;
actual = 0;
int i,length;
char *code;
code = (char*)malloc(256*sizeof(char));

length = strlen(symbols);
float matrixaux[length][2];
//float arrayAux[length];

for(i=0;i<length;i++){
          matrixaux[i][0] = symbols[i];
          matrixaux[i][1] = freq[i];
          
      }


 heapsort(matrixaux,length);
 Creategraph(matrixaux,length);
minimo = root->key_value;
int lado;//0 para o pai do mais pequeno, 1 para o pai do segundo mais pequeno
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
		Pai_smallest = filho1->up;
		Pai_2nd = filho2->up;
		
		Parente = (struct node*) malloc( sizeof( struct node ));
		Parente->key_value = filho1->key_value + filho2->key_value;

		if(Pai_smallest==0){
			Parente->up = Pai_2nd;
		 	lado=1;
		}
		if(Pai_2nd == 0){
			Parente->up = Pai_smallest;
		 	lado=0;
		}
		if(Pai_smallest !=0 && Pai_2nd !=0){

		//}else{
			 if(Pai_smallest->key_value < Pai_2nd->key_value){
			 	
			 	Parente->up = Pai_2nd;
			 	lado=1;
			 }
			 if(Pai_smallest->key_value > Pai_2nd->key_value){
			 	Parente->up = Pai_smallest;
			 	lado=0;
			 }

			 if(Pai_smallest->key_value == Pai_2nd->key_value){
		 		Parente->up = Pai_smallest;
		 		lado=0;
		 	}
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

		if(root!=Parente){
			if(lado ==1){
				if(Pai_2nd->left == filho2){
					Pai_2nd->left = Parente;
				}else{
					Pai_2nd->right = Parente;
				}

				if(Pai_smallest !=0 && Pai_smallest->left == filho1){
					Pai_smallest->left = 0;
				}else if(Pai_smallest !=0){
					Pai_smallest->right = 0;
				}
				
			}else {
				if(Pai_smallest->left == filho1){
					Pai_smallest->left = Parente;

				}else{
					Pai_smallest->right = Parente;
				}

				if(Pai_2nd!=0 && Pai_2nd->left == filho2){
					Pai_2nd->left = 0;

				}else if(Pai_2nd!=0){
					Pai_2nd->right = 0;
				}

			}
		}else{
			if(Pai_smallest !=0){
				if(Pai_smallest->left == filho1){
					Pai_smallest->left = 0;

				}else{
					Pai_smallest->right = 0;
				}

			}


			if(Pai_2nd!=0){
				if(Pai_2nd->left == filho2){
					Pai_2nd->left = 0;
				}else{
					Pai_2nd->right = 0;
				}
			}


		}
	}

	//fazer o codigo em si
	int codigo[256];

	
	
	
		codify(root,codigo);
		*output=stack;
		
	


	//

}

