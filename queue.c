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

void print_queue(queue *q);
queue *create_queue(); //Funciona
bool isEmpty(queue *q); //Funciona
node *create_node(int data, int priority); //Funciona
void enqueue();
//int qsize();
//int front();
//int dequeue();

int main(){

	queue *q = create_queue();
	bool teste;

	enqueue(q, 1, 0);

	teste = isEmpty(q);

	print_queue(q);

	printf("%d\n", q->first->data);

	return 0;
}

queue *create_queue(){
	queue *q = (queue*)malloc(sizeof(queue));
	q->first = NULL;

	return q;
}

bool isEmpty(queue *q){
	if(q->first == NULL){
		printf("Fila vazia\n");
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
		queue *aux = (queue*)malloc(sizeof(queue));
		aux->first = q->first;
		while(aux->first->next!=NULL){
			aux = aux->first->next;
		}
		aux->first->next = create_node(data, priority);
	}

	printf("Enqueue\n");
}

void print_queue(queue *q){
	queue *aux = (queue*)malloc(sizeof(queue));
		aux->first = q->first;
		do{
			printf("%d \n", aux->first->data);
			aux = aux->first->next;
		}while(aux->first->next!=NULL);
}
