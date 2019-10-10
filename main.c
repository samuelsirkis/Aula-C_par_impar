#define _CRT_SECURE_NO_WARNINGS // para ignorar erro scanf
#include <stdio.h>
#include <locale.h>

#define TAM 20
//chamada das funções
void div(); void head(); void valor(int tam); char vaiSair(char sai);

int main() {

	//define o indioma para português
	setlocale(LC_ALL, "");

	//declaração das variáveis
	int vet[TAM], i = 0, tam = 0, par[TAM], impar[TAM], contPar = 0, contImpar = 0, soma = 0, maior = 0, menor = 0, posicao = 0;
	char sair = 0;
	//int menor2=0;
	//chama o cabeçalho
	head();

	//entrada dos valores digitados
	do {
		printf("Digite o %2.dº número: ", i + 1);
		scanf_s("%d", &vet[i]);
		sair = vaiSair(sair);
		i++;
	} while (sair != 's' && i < TAM);

	//imprime a quantidade de números digitados
	tam = i;
	valor(tam);
	//menor2=vet[0];
	//varrendo o vetor e atribuindo par e impar
	for (i = 0; i < tam; i++) {
		if (vet[i] % 2 == 0) {
			par[contPar] = vet[i];
			contPar++;
		}
		else {
			impar[contImpar] = vet[i];
			contImpar++;
		}
		/*
		if(vet[i]<menor2){
			menor2 =vet[i];		
		}
		*/
	}

	//cálculo da soma
	for (i = 0; i < contPar; i++) {
		soma = soma + par[i];
	}

	printf("\nSoma dos numeros pares = %d\n", soma);
	div();

	//cálculo da media dos pares
	if (soma != 0) {
		printf("\nMédia dos números pares = %d\n", soma / contPar);
		div();
	}

	//encontra maior valor ímpar
	/*forma alternativa de encontrar o maios e o menor
	if (impar[i]!=0){
		maior = impar[0];
		menor = impar[0];
	}
	for (i = 0; i < contImpar; i++) {
		if (impar[i] > maior) {
			maior = impar[i];
		}
		if (impar[i] < menor) {
			menor = impar[i];
		}
	}*/
	maior = vet[0];
	for (i = 1; i < tam; i++) {
		if (vet[i] > maior&& vet[i] % 2 != 0) {
			maior = vet[i];
			posicao = i;
		}
	}

	printf("\nMaior valor ímpar = %d => posição %d\n", maior, posicao + 1);

	//encontra menor valor ímpar
	menor = vet[0];
	for (i = 1; i < tam; i++) {
		if (vet[i] < menor && vet[i] % 2 != 0) {
			menor = vet[i];
			posicao = i;
		}
	}

	div();
	printf("\nMenor valor ímpar = %d => posição %d\n", menor, posicao + 1);
	div();

	// encontra o Menor valor do vetor principal
	menor = vet[0];
	for (i = 1; i < tam; i++) {
		if (vet[i] < menor) {
			menor = vet[i];
			posicao = i;
		}
	}

	printf("\nMenor valor informado = %d", menor);
	if (menor % 2 == 0) {
		printf(" que é par.");
	}
	else {
		printf(" que é ímpar.");
	}

	printf(" => posição %d\n\n", posicao + 1);
	div();
	system("pause");
	return 0;
}

void div() {
	printf("\n===============================\n");
}

void head() {
	div();
	printf("Informe até 20 números!");
	div();
}

void valor(int tam) {
	div();
	printf("\nQuantidade informada: (%d)\n", tam);
	div();
}

char vaiSair(char sai) {
	int contaErro = 0;
	do {
		if (contaErro != 0) {
			//system("cls || clear");
			printf("\n/\\ - Informe corretamente\n");
		}
		printf("Deseja sair (s/n)? ");
		scanf(" %s", &sai);
		contaErro++;
	} while (sai != 's' && sai != 'n');
	return sai;
}
