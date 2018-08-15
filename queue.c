#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*1 - Procurar um elemento na fila
2 - Inverter a fila
3 - Ordenar a fila por prioridade*/

typedef struct node node;
typedef struct queue queue;

struct node{
	int data;
	int priority;
	node *next;
};

struct queue{
	node *first;
};

queue *create_queue();
bool isEmpty(queue *q);
node *create_node(int data, int priority);
void enqueue(queue *q, int data, int priority);
void print_queue(queue *q);
int qsize(queue *q);
void front(queue *q);
void dequeue(queue *q);
int search(queue *q, int item); //Não funciona no primeiro número

int main(){

	queue *q = create_queue();
	bool teste;
	int size, seek;

	enqueue(q, 1, 0);
	enqueue(q, 2, 0);
	enqueue(q, 3, 0);

	teste = isEmpty(q);

	print_queue(q);

	size = qsize(q);

	front(q);

	dequeue(q);
	front(q);

	seek = search(q, 1);

	return 0;
}

queue *create_queue(){
	queue *q = (queue*)malloc(sizeof(queue));
	q->first = NULL;

	return q;
}

bool isEmpty(queue *q){
	if(q->first == NULL){
		return true;
	}else{
		return false;
	}
}

node *create_node(int data, int priority){
	node *new_node = (node*)malloc(sizeof(node));
	new_node->data = data;
	new_node->priority = priority;
	new_node->next = NULL;

	return new_node;

}

void enqueue(queue *q, int data, int priority){
	if(q->first == NULL){
		q->first = create_node(data, priority);
	}else{
		node *aux = q->first;
		while(aux->next!=NULL){
			aux = aux->next;
		}
		aux->next = create_node(data, priority);
	}
}

void print_queue(queue *q){
	if(isEmpty(q)){
		printf("Fila Vazia!!\n");
	}else{
		queue *aux = (queue*)malloc(sizeof(queue));
		aux->first = q->first;
		while(aux->first!=NULL){
			printf("%d \n", aux->first->data);
			aux->first = aux->first->next;
		}
	}
}

int qsize(queue *q){
	queue *aux = (queue*)malloc(sizeof(queue));
	int cont=0;

	aux->first = q->first;

	while(aux->first!=NULL){
		aux->first = aux->first->next;
		cont++;
	}

	printf("Tamanho da fila: %d\n", cont);

	return cont;
}

void front(queue *q){
	if(isEmpty(q)){
		printf("Fila vazia!\n");
	}else{
		node *first = q->first;
		printf("Primeiro elemento: %d\n", first->data);
	}
}

void dequeue(queue *q){
	if(isEmpty(q)){
		printf("Fila vazia!\n");
	}else{
		node *aux = q->first;
		aux = aux->next;
		q->first = aux;
	}
}

int search(queue *q, int item){
	if(isEmpty(q)){
		printf("Fila vazia!\n");
		return -1;
	}else{
		node *aux = q->first;
		while(aux!=NULL){
			if(aux->data == item){
				printf("%d encontrado!\n", aux->data);
				return aux->data;
			}
			aux = aux->next;
		}
		printf("Item não encontrado\n");
		return -1;
	}	
}
