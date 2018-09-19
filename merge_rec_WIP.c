#include <stdio.h>
#include <stdlib.h>

void buildVet(int *vet, int *aux, int *auxind, int *b1, int *b2, int middle, int end);
void mergeLeft(int vet[], int aux[], int *b1, int *middle, int *indAux);
void mergeRight(int vet[], int aux[], int *b2, int *end, int *indAux);
void movElements(int auxVet[], int vet[], int begin, int end, int cont);
void merge(int *vet, int begin, int middle, int end, int aux);
void mergeSort(int *vet, int begin, int end);

int main(){

	int vet[4] = {3, 4, 2, 1};
	int *p = vet;
	int i;

	mergeSort(p, 0, 3);

	for(i=0; i<4;i++){
		printf("%d\n", vet[i]);
	}

	return 0;
}

void buildVet(int *vet, int *aux, int *auxind, int *b1, int *b2, int middle, int end){
	if(b1<=middle && b2<=end){
		if(vet[b1]<vet[b2]){
			aux[auxind] = vet[b1];
			b1++;
		}else{
			aux[auxind] = vet[b2];
			b2++;
		}
		auxind++;
	}else{
		return;
	}
}

/*void mergeLeft(int vet[], int aux[], int *b1, int *middle, int *indAux){
	if(b1<=middle){
		aux[indAux] = vet[b1];
		mergeLeft(vet, aux, *b1++, *middle, *indAux++);
	}else{
		return;
	}
}

void mergeRight(int vet[], int aux[], int *b2, int *end, int *indAux){
	if(b2<=end){
		aux[indAux] = vet[b2];
		mergeRight(vet, aux, *b2++, *end, *indAux++);
	}else{
		return;
	}
	if(b2<=middle){
		aux[indAux] = vet[b2];
		mergeLeft(vet, aux, *b2++, *middle, *indAux++);
	}else{
		return;
	}
}

void movElements(int auxVet[], int vet[], int begin, int end, int cont){
	cont = begin;
	if(cont>=end){
		return;
	}else{
		vet[cont] = auxVet[cont-begin];
		movElements(auxVet, vet, begin, end, cont++);
	}
}*/


void merge(int *vet, int begin, int middle, int end, int aux){
	int b1 = begin, b2 = middle+1, size = end-begin+1;
	int *p1 = &b1, *p2 = &b2;
	int *auxVet = (int*)malloc(size*sizeof(int));

	buildVet(vet, auxVet, aux, p1, p2, middle, end);

	//movElements(auxVet, vet, begin, end, 0);

	free(auxVet);
}

void mergeSort(int *vet, int begin, int end){
	if(begin<end){
		int middle = (begin+end)/2;
		mergeSort(vet, begin, middle);
		mergeSort(vet, begin+1, end);
		merge(vet, begin, middle, end, 0);
	}
}
