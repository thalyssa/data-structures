//Quase nada aqui funciona, preciso arrumar tudo

#include <stdio.h>
#include <stdlib.h>

typedef struct btree btree;


struct btree{
	int number;
	btree *right;
	btree *left;
};

btree *create_node(int n){
	btree *new_tree = (btree*) malloc(sizeof(btree));
	new_tree->number = n;
	new_tree->right = NULL;
	new_tree->left = NULL;

	return new_tree;
}

btree *create_tree(){
	return NULL;
}

void insert_node(btree *tree, int n){
	if(tree == NULL){
		tree = create_node(n);
		printf("Arvore iniciada\n");
	}else if(n>tree->number){
		if(tree->right == NULL){
			tree->right = create_node(n);
			printf("Add no direito\n");
		}else{
			insert_node(tree->right, n);
		}
	}else if(n<tree->number){
		if(tree->left == NULL){
			tree->left = create_node(n);
			printf("Add no esquerdo\n");
		}else{
			insert_node(tree->left, n);
		}
	}
}

void printTree(btree *tree){
	if(tree == NULL){
		printf("Vazia\n");
		return;
	}else{
		printf("%d\n", tree->number);
		printTree(tree->left);
		printTree(tree->right);
	}
}

int main(){

	btree *tree = create_tree();
	insert_node(tree, 2);
	//insert_node(tree, 1);
	//insert_node(tree, 3);

	printTree(tree);

	return 0;
}
