#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node node;
typedef struct queue queue;

struct node{
	int data;
	node *next;
};

struct queue{
	node *first;
	node *last;
	int size;
};

queue* create_queue();
bool isEmpty(queue *q);
node* create_node(int data);
void enqueue(queue *q, int data);
int dequeue(queue *q);
void print_queue(queue *q);
queue *positive(queue *q);


int main(){

	char n[1];
	int item;
	queue *initQ = create_queue();
	queue *positiveQueue = create_queue();

	printf("Digite apenas numeros para formar a primeira fila. Digite qualquer letra para encerrar: \n");

	scanf("%s", &n);

	while(isdigit(n)!=0){
		item = atoi(n);
		enqueue(initQ, item);
		scanf("%s", &n);
	}

	positiveQueue = positive(initQ);

	print_queue(positiveQueue);

	return 0;
}

queue *create_queue(){
	queue *q = (queue*)malloc(sizeof(queue));
	q->first = NULL;
	q->last = NULL;
	q->size = 0;

	return q;
}

bool isEmpty(queue *q){
	if(q->first == NULL){
		return true;
	}else{
		return false;
	}
}

node* create_node(int data){
	node *new_node = (node*)malloc(sizeof(node));
	new_node->data = data;
	new_node->next = NULL;

	return new_node;

}

void enqueue(queue *q, int data){
	node *new_node = create_node(data);
	if(isEmpty(q)){
		q->last = new_node;
		q->first = q->last;
	}else{
		q->last->next = new_node;
		q->last = new_node;
	}
	q->size++;
}

int dequeue(queue *q){
	if(isEmpty(q)){
		printf("Fila vazia!\n");
		return -1;
	}else{
		int item = q->first->data;
		node *aux = q->first;

		q->first = q->first->next;
		q->size--;

		if(q->size == 0){
			q->last = NULL;
		}

		free(aux);
		return item;
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

queue* positive(queue *q){
	queue *aux_queue = create_queue();

	while(q->size>0){
		int data = dequeue(q);
		if(data>0){
			enqueue(aux_queue, data);
		}
	}

	return aux_queue;

}
