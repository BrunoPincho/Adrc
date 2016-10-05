#include <stdio.h>
#include <stdlib.h>
int level;
int lvlcount;
struct node{
	int key_value;
	int level;
	struct node*left;
	struct node*right;
	struct node*up;
	

};

void destroy_tree(struct node* leaf)
{
	if(leaf!=0)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		free(leaf);
	}
} 

void insert(int key, struct node **leaf,struct node **leaf_up)
{
	int aux;
	struct node **tempnode;
	level = 0;
    if( *leaf == 0 )
    {

        *leaf = (struct node*) malloc( sizeof( struct node ) );
        (*leaf)->key_value = key;
        /* initialize the children to null */
        (*leaf)->left = 0;    
        (*leaf)->right = 0;
        
        if(*leaf_up == NULL){
        	(*leaf)->level = 0;
        } 

        if(*leaf_up != NULL){
        	(*leaf)->up = *leaf_up;
        	(*leaf)->level = (*leaf_up)->level+1;
        	lvlcount++;
        }  
    } 

    	if((*leaf)->level<)

    ////esta parte troca o filho da esquerda com o da direita
    	if((*leaf)->left!=NULL && (*leaf)->right== NUL){
    		if(((*leaf)->left)->key_value>key){
    			aux=((*leaf)->left)->key_value;
    			((*leaf)->left)->key_value = key;
    			insert(aux,&(*leaf)->right,&(*leaf));
    		}
    	}
    ///////////////////////////////////////////////////////////

    	if((*leaf)->right!= NULL && (*leaf)->left!=NULL){
    		tempnode = (*leaf)->left;
	
    	}
    

    if(key < (*leaf)->key_value)
    {
    	
        insert( key, &(*leaf)->left,&(*leaf));
    }
    if(key > (*leaf)->key_value)
    {
    	
        insert( key, &(*leaf)->right,&(*leaf));
    }




    
}

struct node *search(int key, struct node*leaf){
	if(leaf!=0)
	{
		if(key == leaf->key_value){
			return leaf;
		}
		else if(key < leaf->key_value)
		{
			return search(key,leaf->left);
		}
		else{
			return search(key, leaf->right);
		}
	}
	else return 0;
}

void Printree(struct node*leaf){
	if(leaf!=0){
		printf("%d \n",leaf->key_value);
		Printree(leaf->right);
		Printree(leaf->left);
	}	
}

int main(){
	struct node *root=0;
	struct node *doot = NULL;
	

	insert(10,&root,&doot);
	insert(7,&root,&doot);
	insert(5,&root,&doot);
	
	Printree(root);


}