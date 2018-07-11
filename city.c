#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*COMANDOS PARA OS CARR0S
0 - Cima
1 - Baixo
2 - Esquerda
3 - Direita

O semáforo não pode ter tempo 0
Tempo de pelo menos 2

1000 interações

SEMÁFORO
0 - Vermelho
1 - Verde

CÓDIGOS
+ - Rua Vazia
Z - Semáforo
. - Quarteirão
C - Carro

ORDEM DOS CAMINHOS NA CÉLULA
path = [Cima, Baixo, Esquerda, Direita]
true - Caminho livre
false - Bloqueado*/

typedef struct mainCel mainCel;
typedef struct signal signal;
typedef struct car car;

struct car{
	int posX;
	int posY;
};

struct signal{
	int pos[20][20];
	int status;
	int time;
};

struct mainCel{
	char type[20][20];
	bool paths[4];
};

void moveCar(mainCel *city, car *aut);
void startCity(mainCel *city);
void printCity(mainCel *city);
void setSignalMatrix(mainCel *city, signal *trafic);
signal* createSignal(signal *trafic);

int main(){

	FILE * log;
	mainCel city[19][19];
	signal trafic[19][19];
	int i, j;

	startCity(*city);
	printCity(*city);
	setSignalMatrix(*city, *trafic);
	log = fopen("log.txt", "w+");

	for(i=0;i<1000;i++){
		
	}

	return 0;
}

void moveCar(mainCel *city, car *aut, FILE *file){
	int aux;

	aux = rand()%4;

	switch (aux){
		case 0: //Cima
			if(city->path[0]){
				aut->posY = aut->posY-1;
			}else{

			}
			
		break;

		case 1: //Baixo
			if(city->path[1]){
				aut->posY = aut->posY+1;
			}else{

			}
		break;

		case 2: //Esquerda
			if(city->path[2]){
				aut->posX = aut->posX-1;
			}else{

			}
		break;

		case 3: //Direita
			if(city->path[3]){
				aut->posX = aut->posX+1;
			}else{

			}
		break;

		default: //Não se move
			aut->posX = aut->posX;
			aut->posY = aut->posY;
		break;
	}
}

void startCity(mainCel *city){
	int i, j;
	for(i=0;i<19;i++){
		for(j=0;j<19;j++){
			city->type[i][j] = 'A';
			//Setar os sinais
			if((i%6 == 0) && (j%6 == 0)){
				//printf("Caiu! i: %d, j: %d\n", i, j);
				city->type[i][j] = 'Z';
				city->paths[0] = true;
				city->paths[1] = true;
				city->paths[2] = true;
				city->paths[3] = true;
			// Setar os quarteirões
			}else if(i%6!=0 && j%6!=0){
				city->type[i][j] = '.';
				city->paths[0] = false;
				city->paths[1] = false;
				city->paths[2] = false;
				city->paths[3] = false;
			//Setar as ruas
			}else{
				city->type[i][j] = '+';
				city->paths[0] = true;
				city->paths[1] = false;
				city->paths[2] = true;
				city->paths[3] = false;
			} 
		}//For j
	}//For i
}

void printCity(mainCel *city){
	int i, j;
	for(i=0;i<19;i++){
		for(j=0;j<19;j++){
			printf("%c ", city->type[i][j]);
		}
		printf("\n");
	}
}

void setSignalMatrix(mainCel *city, signal *trafic){
	int i, j;
	for(i=0;i<19;i++){

		for(j=0;j<19;j++){
			if(city->type[i][j]=='Z'){
				trafic->pos[i][j] = createSignal(trafic);
			}
		}//End j
	}//End i
}

signal* createSignal(signal *trafic){
	signal *new_signal = (signal*) malloc (sizeof(signal));
	new_signal->status = 1;
	new_signal->time = rand()%3+1;

	return new_signal;
}
