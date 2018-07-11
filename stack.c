#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 100

typedef struct stack stack;

struct stack{
	int size;
	int items[MAX_STACK];
};

stack* create_stack();
void push(stack *stk, int newItem);
void pop(stack *stk);
void printStack(stack *stk);
void stackPop(stack *stk);
stack* invertePilha(stack *stk);
void changeFirstLast(stack *stk);

int main(){

	int n;
	stack *stk;

	stk = create_stack();

	push(stk, 1);
	push(stk, 2);
	push(stk, 3);
	push(stk, 4);
	push(stk, 5);
	push(stk, 6);

	printStack(stk);

	stk = invertePilha(stk);

	printf("--- PILHA INVERTIDA ---\n");
	printStack(stk);

	changeFirstLast(stk);

	return 0;
}

stack* create_stack(){
	stack *stk = (stack*)malloc(sizeof(stack));
	stk->size = 0;

	return stk;
}

void push(stack *stk, int newItem){
	if(stk->size == MAX_STACK){
		printf("ERRO: Stack Overflow!!!\n");
	}else{
		stk->items[stk->size++] = newItem;
	}
}

void pop(stack *stk){
	if(stk->size==0){
		printf("ERRO: Pilha Vazia!\n");
	}else{
		stk->size--;
	}
}

void printStack(stack *stk){
	int i=stk->size-1;

	if(i==0){
		printf("Pilha Vazia!\n");
	}
	while(i>=0){
		printf("%d\n", stk->items[i]);
		i--;
	}
}

void stackPop(stack *stk){
	if(stk->size==0){
		printf("ERRO: Pilha Vazia!\n");
	}else{
		printf("Topo da pilha: %d\n", stk->items[stk->size-1]);
	}
}

stack* invertePilha(stack *stk){
	stack *auxStk = create_stack();
	int i, aux;

	for(i=stk->size-1;i>=0;i--){
		aux = stk->items[i];
		push(auxStk, aux);
	}

	return auxStk;

}

void changeFirstLast(stack *stk){
	int topo, fim, aux;
	stack *auxStk = create_stack();
	topo = stk->items[stk->size-1];
	
	pop(stk);

	auxStk = invertePilha(stk);

	fim = auxStk->items[auxStk->size-1];

	pop(auxStk);

	while(stk->size>0){
		pop(stk);
	}

	push(stk, topo);

	while(auxStk->size!=0){
		aux = auxStk->items[auxStk->size-1];
		push(stk, aux);
		pop(auxStk);
	}

	push(stk, fim); 

	printf("--- TROCA DE TOPO E BASE ---\n");
	printStack(stk);
}
