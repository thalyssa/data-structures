#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node node;
typedef struct queue queue;

struct node{
	int data;
	int prior;
	node *next;
};

struct queue{
	node *first;
	node *last;
	int size;
};

queue* create_queue();
bool isEmpty(queue *q);
node* create_node(int data, int p);
void enqueue(queue *q, int data, int p);
int dequeue(queue *q);
queue* print_queue(queue *q);
queue* order_queue(queue *q);


int main(){

	int item, p;
	queue *initQ = create_queue();
	queue *orderedQ = create_queue();

	printf("Digite os atendimentos a serem realizados seguidos de suas prioridades.\nQuando nao houver mais atendimentos, digite -1\n\n");

	while(1){
		scanf("%d", &item);
		if(item==-1){
			break;
		}else{
			scanf("%d", &p);
			if(p==0 || p==1){
				enqueue(initQ, item, p);
			}else{
				printf("Prioridade invalida!!! Favor digitar apenas 0 ou 1\n");
				break;
			}
			
		}
	}

	if(isEmpty(initQ)==false){

		orderedQ = order_queue(initQ);
		printf("\nORDEM DE ATENDIMENTO:\n");
		orderedQ = print_queue(orderedQ);
	}else{
		printf("Ocorreu um erro, por favor tente novamente\n");
	}

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

node* create_node(int data, int p){
	node *new_node = (node*)malloc(sizeof(node));
	new_node->data = data;
	new_node->prior = p;
	new_node->next = NULL;

	return new_node;

}

void enqueue(queue *q, int data, int p){
	node *new_node = create_node(data, p);
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

queue* print_queue(queue *q){
	if(isEmpty(q)){
		printf("Fila Vazia!!\n");
		return -1;
	}else{
		queue *aux = create_queue();
		int item, p;
		while(isEmpty(q) == false){
			printf("Atendimento: %d \n", q->first->data);
			printf("Prioridade: %d \n", q->first->prior);
			p = q->first->prior;
			item = dequeue(q);
			enqueue(aux, item, p);

		}
		return aux;
	}
}

queue* order_queue(queue *q){
	 queue *priorQueue = create_queue();
	 queue *normQueue = create_queue();                                                                                                             
	 queue *ordQueue = create_queue();
	 int cont = 0;
	 int item;

	 while(isEmpty(q) == false){
	 	if((q->first->prior == 0)){ //Atendimento normal
	 		item = dequeue(q);
	 		enqueue(normQueue, item, 0);
	 	}else if(q->first->prior == 1){ //Atendimento prioritário
			item = dequeue(q);
	 		enqueue(priorQueue, item, 1);
	 	}
	 }//End while

	 while(isEmpty(normQueue) == false){
	 	
	 	item = dequeue(normQueue);
	 	enqueue(ordQueue, item, 0);
	 	cont++;

	 	if((cont==3) && (isEmpty(priorQueue)==false)){
	 		item = dequeue(priorQueue);
	 		enqueue(ordQueue, item, 1);
	 		cont = 0;
	 	}

	 }//End while normQ

	 while(isEmpty(priorQueue)==false){
	 		item = dequeue(priorQueue);
	 		enqueue(ordQueue, item, 1);
	 }

	 return ordQueue;

}// End order_queue
