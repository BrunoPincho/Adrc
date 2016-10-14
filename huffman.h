#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void heapsort(float array[][2], int n);
void heapify(float array[][2], int n);
void adjust(float array[][2], int n);
int arraysize;
float minimo;
struct node{
  float key_value;
  char symbol;
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

  //lista fifo 
  struct stack{
  	char simbolo;
  	int *codificacao;
  	int codesize;
  	float frequencia;
  	struct stack* next;
  };struct stack* stack;

  void encontraActual(struct node *node,int nodeid);
  void Creategraph(float array[][2],int size);
  void encontraMinimo(struct node *node);
  void codify(struct node *node,int* codeaux);
  void HuffmanCode(char* symbols,float* freq,struct stack** output);



  #endif