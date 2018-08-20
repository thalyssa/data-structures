#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
typedef struct circular_queue circular_queue;

struct node{
	int item;
	node *next;	
};

struct circular_queue{
	node *first;
	node *last;
};

circular_queue* create_queue(); //Funciona
node* create_node(int item);
void enqueue(circular_queue *q, int item);
void dequeue(circular_queue *q);
void print_queue(circular_queue *q);

int main(){

	circular_queue *q = create_queue();
	
	enqueue(q, 1);
	enqueue(q, 2);
	//enqueue(q, 3);

	//dequeue(q);

	//print_queue(q);

	return 0;
}

circular_queue* create_queue(){
	circular_queue *q = (circular_queue*)malloc(sizeof(circular_queue));
	
	q->first = NULL;
	q->last = NULL;

	return q;
}

node *create_node(int item){
	node *new_node = (node*)malloc(sizeof(node));

	new_node->item = item;
	new_node->next = NULL;
	
	printf("Criado\n");
	
	return new_node;
}

void enqueue(circular_queue *q, int item){
	if(q->first == NULL){
		q->first = create_node(item);
		q->last = q->first;
		printf("Adicionado\n");
	}else{
			q->last->next = create_node(item);
			//q->last = q->last->next;
		}
}

void dequeue(circular_queue *q){
	if(q->first == NULL){
		printf("Fila vazia! Nada para retirar\n");
	}else{
		node *aux;
		aux = q->first->next;
		q->first = aux;
	}
}

void print_queue(circular_queue *q){
		if(q->first == NULL){
		printf("Fila vazia! Nada para printar\n");
	}else{
			circular_queue *aux;
			aux->first = q->first;
			while(aux->first!=q->last){
			printf("%d", aux->first->item);
			aux->first = aux->first->next;
		}
	}
}
