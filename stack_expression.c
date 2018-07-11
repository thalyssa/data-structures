#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 100

typedef struct stack stack;

struct stack{
	int size;
	char items[MAX_STACK];	
};

stack* create_stack(){
	stack *new_stack = (stack*) malloc(sizeof(stack));
	new_stack->size = 0;

	return new_stack;
}

void push(stack *stk, char item){
	if(stk->size == MAX_STACK){
		printf("STACK OVERFLOW!!\n");
	}else{
		stk->items[stk->size++] = item;
	}	
}

void pop(stack *stk){
	if(stk->size == 0){
		printf("ERRO: Pilha vazia!\n");
	}else{
		stk->size--;
	}
	
}

int main(){
	
}
