#include <stdio.h>
#include <locale.h>
#define T 7

void HeapSort(int A[], int n);
void Heap(int A[], int t);
void Descer(int A[], int i, int q);
void Troca(int *a, int *b);

void HeapSort(int A[], int n){
	int i;
	Heap(A, T); //Transforma o array em heap
	
	for (i = n - 1; i >= 1; i--){
		Troca(&A[0], &A[i]);
		Descer(A, 0, i - 1);
	}
} 

void Heap(int A[], int t){
	int i;
	
	for (i = (t/2); i >= 0; i--){
		Descer(A, i, t - 1); 
	}
	
	printf ("\n\nO Heap desse array é: ");
	for (i = 0; i < T; i++){
		printf ("%d\t", A[i]);
	}
}

void Descer(int A[], int i, int q){
	int d = 2 * i + 2; //direita
	int e = 2 * i + 1; //esquerda
	int maior = i;
	
	if (d <= q && A[d] > A[i])
		maior = d;
	if (e <= q && A[e] > A[maior])
		maior = e;
	
	if (maior != i){
		Troca(&A[i], &A[maior]);
		Descer(A, maior, q);
	}
}

void Troca(int *a, int *b){
	int aux; 
	
	aux = *a;
	*a = *b;
	*b = aux;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int A[T];
	int i, cont;
	
	for(cont = 0; cont < T; cont++){
		printf ("Insira os valores para Heap: ");
		scanf ("%d", &A[cont]);
	}
	
	HeapSort(A, T);
	printf("\nO HeapSort desse array é: ");
	for(i = 0; i < T; i++){
		printf ("%d\t", A[i]);
	}
	
	return 0;
}
