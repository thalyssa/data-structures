#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node* create_list(){
	return NULL;
}

node* add_data_head(node *head, int data){
	node *new_node = (node*) malloc(sizeof(node));
	new_node->data = data;
	new_node->next = head;
	head = new_node;
	//printf("AddH\n");
	return new_node;
}

node* add_data_tail(node *head, int data){
	node *current = head;
	while(current->next != NULL){
		current = current->next;
	}
		node *new_node = (node*) malloc(sizeof(node));
		new_node->data = data;
		new_node->next = NULL;
		current->next = new_node;
		//printf("AddT\n");
	return head;
}

/*node* add_data_order(node *head, int data){
	node *pointer = head;

	if(pointer == NULL || pointer->data > data){
		add_data_head(head, data);
	}else{
		while(pointer->next->data <= data && pointer->next!= NULL){
			pointer = pointer->next;
		}
		node *new_node = (node*) malloc(sizeof(node));
		new_node->data = data;
		new_node->next = pointer->next;
		pointer->next = new_node;
	}
	//printf("AddO\n");
	return head;
}*/

node* search_list(node *head, int data){
	node *current;
	for(current=head; current!=NULL; current = current->next){
		if(current->data == data){
			printf("\n%d\n", current->data);
			return current;
		}
	}
	printf("Not found!");
	return NULL;
}  

void print_list(node *head){
	while(head!=NULL){
		printf("%d\n", head->data);
		head = head->next;
	}
}

int main(){

	node* list = create_list();

	list = add_data_head(list, 90);
	list = add_data_head(list, 80);
	list = add_data_head(list, 70);
	list = add_data_head(list, 60);
	list = add_data_tail(list, 100);
	list = add_data_tail(list, 200);
	list = add_data_tail(list, 300);
	list = add_data_order(list, 75);
	list = add_data_order(list, 85);
	//list = add_data_order(list, 400);
	//list = add_data_order(list, 55);

	print_list(list);

	return 0;
}
