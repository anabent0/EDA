#include <stdio.h>
#include <locale.h>

void moverdiscos (int disc, char ori, char dest, char aux){
	if (disc == 1){
		printf ("Mover disco %d de %c para %c\n", disc, ori, dest);
	}
	else {
		moverdiscos (disc - 1, ori, aux, dest);
		printf ("Mover disco %d de %c para %c\n", disc, ori, dest);
		moverdiscos (disc - 1, aux, dest, ori);

	}
}

int main (){
	setlocale(LC_ALL, "Portuguese");
	int discos;
	
	printf ("Insira a quantidade de discos da torre de hanói: ");
	scanf ("%d", &discos);
	
	moverdiscos(discos, 'A', 'B', 'C'); //A = pino de origem; B = pino de destino; C = pino auxiliar
	
	return 0;
}
