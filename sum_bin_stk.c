#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 8

typedef struct stack stack;

struct stack{
	int size;
	int items[STACK_SIZE];	
};

stack *push(stack stk, int num){
	if(stk->size == STACK_SIZE){ //Verifica se a pilha tá cheia
		printf("Stack Overflow!!!\n");
	}else{ 
		if(num == 1 || num == 0){ //Como a pilha não está cheia, verifica se o número empilhado é 0 ou 1 
			stk->items[stk->size++] = num;
		}
	}
	
	
}

int main(){

	char n1[8], n2[8];
	int i;

	printf("Digite o primeiro numero: ");
	scanf("%s", n1);



	return 0;
}
