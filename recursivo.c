#include <stdio.h>

//Soma recursiva de um vetor
int vet_sum(int vet[], int size){
	if(size == 0){
		return vet[0];
	}else{
		return vet_sum(vet, size-1) + vet[size];
	}

}

//Elemento maximo de um vetor
int maxi(int vet[], int size, int max){
	if(size == 0){
		return max;
	}else{
		if(vet[size] > max){
			max = vet[size];
		}
		return maxi(vet, size-1, max);
	}
}

//Elemento minimo de um vetor
int mini(int vet[], int size, int min){
	if(size == 0){
		return min;
	}else{
		if(vet[size] < min){
			min = vet[size];
		}
		return mini(vet, size-1, min);
	}
}

//Função de Ackermann
int ackermann(int m, int n){
	if(m == 0){
		return n+1;
	}else if(m!=0 && n == 0){
		return ackermann(m-1, 1);
	}else if(m!=0 && n!=0){
		return ackermann(m-1, ackermann(m, n-1));
	}
}

//Ordenação recursiva de vetor


int main(){

	int vet[5] = {5, 3, 2, 4, 1};
	int sum = vet_sum(vet, 4);
	int a = ackermann(1, 2);
	int max = maxi(vet, 4, 0);

	printf("%d\n", sum);
	printf("%d\n", a);
	printf("%d\n", max);

	return 0;
}
