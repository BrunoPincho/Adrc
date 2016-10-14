#include "huffman.h"



int main()
{

 int i,j;
 struct stack* codigo;
 char* symbols;
 float* freq;
 //char  symbols[10]={'a','b','c','d','e','f','g','h','i','j'};
 //float freq[6] = {0.25,0.05,0.1,0.15,0.2,0.25};
 //float freq[6] = {0.22,0.03,0.14,0.14,0.41,0.06};
 //float freq[7] = {0.25,0.05,0.05,0.15,0.1,0.3,0.1};
 //float freq[10] = {0.01,0.02,0.04,0.04,0.09,0.1,0.1,0.11,0.11,0.38};
 
//Code = (int*)malloc(tamanh*sizeof(int));

 //Array After Mergesort

	
	char c[256];
	FILE* fp;
	fp = fopen("test.txt","r");
	i=0;
	while(fgets(c,50,fp) != NULL){
		i++;
	}

	fclose(fp);
	fp = fopen("test.txt","r");
	symbols = (char*)malloc(i*sizeof(char));
	freq = (float*)malloc(i*sizeof(float));
	symbols[i] = '\0';
 

	j=0;
	while(fgets(c,50,fp) != NULL){
		sscanf(c,"%c %f",&symbols[j],&freq[j]);
		printf("\n %c %f",symbols[j],freq[j]);
		j++;
	}


 HuffmanCode(symbols,freq,&codigo);
 //struct stack* aux;
 
 while(codigo!=0){
 	printf("\n simbolo: %c, frequencia: %f \n codigo:",codigo->simbolo,codigo->frequencia);
 	
 	for(i=0;i<(codigo->codesize);i++){
 			printf("%d",codigo->codificacao[i]);		
 	}
 	puts("\n");
 	codigo = codigo->next;
 }



 free(symbols);
 free(freq);
 fclose(fp);
 return 0;
}