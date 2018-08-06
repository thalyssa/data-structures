#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 8

typedef struct stack stack;

struct stack{
	int size;
	int items[STACK_SIZE];	
};

stack *create_stack();
void push(stack *stk, int num);
int pop(stack *stk);
void printStack(stack *stk);
void sum(stack *bin1, stack *bin2, int carry, stack *result, int count);

int main(){

	int i, bin;
	stack *bin1 = create_stack();
	stack *bin2 = create_stack();
	stack *result = create_stack();

	printf("Digite os oito digitos do primeiro numero: ");
	for(i=0;i<8;i++){
		scanf("%d", &bin);
		push(bin1, bin);
	}

	printf("Digite os oito digitos do segundo numero: ");
	for(i=0;i<8;i++){
		scanf("%d", &bin);
		push(bin2, bin);
	}

	sum(bin1, bin2, 0, result, 0);

	return 0;
}

stack *create_stack(){
	stack *new_stack = (stack*)malloc(sizeof(stack));
	new_stack->size = 0;

	return new_stack;
}

void push(stack *stk, int num){
	if(stk->size == STACK_SIZE){ //Verifica se a pilha tá cheia
		printf("Stack Overflow!!!\n");
	}else{ 
		if(num == 1 || num == 0){ //Como a pilha não está cheia, verifica se o número empilhado é 0 ou 1 
			stk->items[stk->size++] = num;
		}else{ //Se a entrada for um número inválido
			printf("Entrada inválida!\n");
		}
	}
}

int pop(stack *stk){
	if(stk->size==0){
		printf("Pilha vazia\n");
		return -1;
	}

	int topo = stk->items[stk->size];
	stk->size = stk->size--;
	return topo;
}

void printStack(stack *stk){
	int i = stk->size-1;
	if(i == 0){
		printf("Pilha vazia!\n");
	}else{
		while(i>=0){
			printf("%d", stk->items[i]);
			i--;
		}
	}
}

void sum(stack *bin1, stack *bin2, int carry, stack *result, int count){
	int n1, n2, aux, res;
	if(count==8){
		printStack(result);
		return;
	}else{
		n1 = pop(bin1);
		n2 = pop(bin2);
		
		if(n1==n2){
			switch(n1){
				case 1:
					push(result,0);
					aux = 1;
					break;
			 
				case 0:
					push(result,0);
					aux = 0;
				 	break;
			}
			
		}else{

			res = n1+n2+carry;

			if(res==2){
				push(result, 0);
				aux = 1;
			}else if(res>2){
				push(result, 1);
				aux = 0;
			}else{
				push(result, res);
				aux = 0;
			}
			
		}//Fim ese
	}//Fim else 2

	sum(bin1, bin2, aux, result, count+1);
}
