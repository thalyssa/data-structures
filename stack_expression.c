#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMB_SZ 10
#define SMBL_SZ 4
#define STCK_SZ 100

char symbols[SMBL_SZ] = {'+','-','*','/'};
char numbers[NUMB_SZ] = {'0','1','2','3','4','5','6','7','8','9'};

typedef struct stack stack;

struct stack{
	int size;
	char items[STCK_SZ];
};

stack* create_stack(){
	stack *stk = (stack*)malloc(sizeof(stack));
	stk->size = 0;

	//printf("Pilha criada\n");

	return stk;
}

void push(stack *stk, char item){
	if(stk->size == STCK_SZ){
		printf("ERRO: Stack Overflow!!!\n");
	}else{
		stk->items[stk->size++] = item;
	}
}

void pop(stack *stk){
	if(stk->size==0){
		printf("ERRO: Pilha Vazia!\n");
	}else{
		stk->size--;
	}
}

int numSearch(char i){
	int begin = 0;
	int middle;
	int end = NUMB_SZ-1;

	while(begin<=end){

		middle = (begin+end)/2;

		if(numbers[middle]>i){
			end = middle - 1;
		}else if(numbers[middle]<i){
			begin = middle + 1;
		}else if(numbers[middle]==i){
			return middle;
		}
	}

	return -1;
}

int symbSearch(char element){
	int i;

	for(i=0;i<SMBL_SZ;i++){
		if(symbols[i]==element){
			return i;
		}
	}

	return -1;
}

void printStack(stack *stk){
	int i=stk->size-1;

	while(i>=0){
		printf("%c", stk->items[i]);
		i--;
	}
}

void posfix(char *expression){
	stack *stk = create_stack();
	int i;
	for(i=0;i<strlen(expression);i++){
		if(numSearch(expression[i])!=-1){
			printf("%c", expression[i]);
		}else if(symbSearch(expression[i])!=-1){
			push(stk, expression[i]);
		}else{
			printf("Caractere invalido!");
			}
		}

		printStack(stk);
}

void prefix(char *expression){
	stack *stk = create_stack();
	stack *aux = create_stack();
	int i;
	for(i=0;i<strlen(expression);i++){
		if(symbSearch(expression[i])!=-1){
			printf("%c", expression[i]);
		}else if(numSearch(expression[i])!=-1){
			push(stk, expression[i]);
		}else{
			printf("Caractere inválido!");
		}
	}

	//Inverter a pilha
	//Printar os números

}

int main(){
	
	char expression[100];
	int i, op;

	scanf("%s", expression);

	printf("Digite\n1: Prefixa\n2: Posfixa\n");
	scanf("%d", &op);

	switch(op){
		case 1:
			
			break;
		case 2:
			posfix(expression);
			break;
		default:
			printf("Opção inválida!\n");
			break;
	}


	return 0;
}
