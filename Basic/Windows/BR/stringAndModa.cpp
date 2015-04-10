// Eduardo Bertin
// http:\\www.eduardobertin.com.br
// Contador de Strings: Iniciando com o basico.
// 1- fase: Fazer User interface. (pronto)
// 2- fase: implementar contagem de letras. (pronto)
// 3- fase: implementar contagem de palavras. (pronto)
// 4- fase: implementar moda exibindo qual do char mais exibido. (pronto)
// 5- fase: implementar moda com estastistica em ordem alfabeticas utilizando um array dentro de struct. (pronto)
// 6- fase: implementar moda com estastistica em ordem de vezes.(implementando)
// 7- fase: Criar painel com informações de menor e maior numero de vezes por letra e palvras.(implementando)
//----------------------------------------------------------------------------------------------------------------
// Versão Beta
// Estudos sobre Strings e Moda
//----------------------------------------------------------------------------------------------------------------
#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"


// Definindo funções

void interf();
void contadorLetra();
void contadorPalavra();
void modaLetras();
void modaStat();


// Variaveis globais
char texto[200];


// Moda entre letras com estatistica
// Irá exibir quais letras foram usadas no texto e quantas vezes ela
// foi repetida. eu usei 256 para poder conver int em char e char em int
// ou seja na posição que eu guardar as vezes essa posicao convertida em
// em char será a própria letra, evitando o uso de 2 array.
void modaStat(){

	struct letras{
		int vezes[256];   // 256 posições
	} letr;

	int modaCont = 0, modaRef= 0;
	char rtn;
	
	system("cls");
	fflush(stdin);

	for(int i = 0;i<256;i++)
	{
		letr.vezes[i] = 0;  // zerando todas posições
	}

	printf("-----------------------------------------------------\n");
	printf("Digite o texto de no maximo 200 letras:\n(Enter para terminar)\n");
	gets(&texto[0]);


	for (int i=0;i<strlen(texto);i++)
	{
		
		for(int j=0;j<strlen(texto); j++)
		{

				if(texto[i] == texto[j]){
					modaCont++;
		     }
		}
		
		letr.vezes[(int)texto[i]] = modaCont;   // Ficará letr.vezes[numerodaletraemascii] = modaCont
		modaCont = 0;
		
	}
	printf("\n");
	printf("-----------------------------------------------------\n");

	for (int i = 0;i<256; i++){
		
		if(letr.vezes[i] != 0){
		printf("Letra \"%c\" , %d vezes.\n", (char)i, letr.vezes[i]);  // Ficará Letra convertida pelo char i e a posicao de i.
		}
	}
	printf("-----------------------------------------------------\n");
	printf("\n(Deseja denovo ? s/n)");
	gets(&rtn);
	
	switch (rtn){

	case 's':
		modaStat();
	case 'S':
		modaStat();
	default:
	    interf();
		
	}
}


// Moda entre as letras
// Moda e qual letra mais se repetiu no texto
// São dois for com um contador, lembrando que essa função ainda
// não funciona empate, provavelmente ficará o ultimo como maior
void modaLetras()
{
	int modaCont = 0, modaRef= 0;
	char modaLetra[20] = "";
	char rtn;
	
	system("cls");
	fflush(stdin);

	printf("-----------------------------------------------------\n");
	printf("Digite o texto de no maximo 200 letras:\n(Enter para terminar)\n");
	gets(&texto[0]);


	for (int i=0;i<strlen(texto);i++)             // Para pegar todas as strings
	{
		
		for(int j=0;j<strlen(texto); j++)         // Para comparar todas as strings
		{
			if(texto[i] == texto[j]){             // Se ambos for igual guarda o numero
					modaCont++;
		     }
		}
		
		if(modaCont > modaRef){
		modaRef = modaCont;	                      // Se for a maior guarda ou vai para outra
		modaLetra[0] = texto[i];

		}
		modaCont = 0;
		
	}
	printf("\n");
	printf("-----------------------------------------------------\n");
	printf("Repetiu %d vezes a letra \"%c\".(Deseja denovo ? s/n)", modaRef, modaLetra[0]);
	gets(&rtn);
	
	switch (rtn){

	case 's':
		modaLetras();
	case 'S':
		modaLetras();
	default:
	    interf();
		
	}

}

// Contador de palavras
// Essa função procura todos os espaços se supõe quantas palavras são.
// No final incremento a contaPalavra para ficar o mais realistico.
void contadorPalavra(){

	int contaPalavra = 0;
	char rtn;
	system("cls");
	fflush(stdin);

	printf("-----------------------------------------------------\n");
	printf("Digite o texto de no maximo 200 letras:\n(Enter para terminar)\n");
	gets(&texto[0]);
	
	for (int i=0;i<strlen(texto);i++)
	{
		if(texto[i] == ' '){      // a cada espaço, incrementa a variável
			contaPalavra++;		 
		}

	}
	
	contaPalavra++; // faz mais um incremento para a palavra do final.
	
	printf("\n");
	printf("-----------------------------------------------------\n");
	printf("Seu texto possui %d palavras. (Deseja denovo ? s/n)", contaPalavra);
	gets(&rtn);
	
	switch (rtn){  // switch para voltar
	case 's':
		contadorPalavra();
	case 'S':
		contadorPalavra();
	default:
	    interf();
		
	}
}

// Contador de Letra 
// Função que le todos os caracteres digitados, retira os espaços
// e conta quantas letras tem
void contadorLetra(){

	int contaLetra = 0;
	char rtn;
	system("cls");
	fflush(stdin);

	printf("-----------------------------------------------------\n");
	printf("Digite o texto de no maximo 200 letras:\n(Enter para terminar)\n");
	gets(&texto[0]);
	
	for (int i=0;i<strlen(texto);i++)
	{
		if(texto[i] != ' '){   // Para não contar os espaços
			contaLetra++;
		}
	}
	
	printf("\n");
	printf("-----------------------------------------------------\n");
	printf("Seu texto possui %d letras. (Deseja denovo ? s/n)", contaLetra);
	gets(&rtn);
	
	switch (rtn){  // switch para voltar

	case 's':
		contadorLetra();
	case 'S':
		contadorLetra();
	default:
	    interf();
		
	}

}

// interf - User interface do programa
void interf()
{
		int opc = 0;
		system("cls");
		fflush(stdin);

		// Interface
		printf("-----------------------------------------------------\n");
		printf("-                                                   -\n");
		printf("-                                                   -\n");
		printf("-  1- Contador de Letra                             -\n");
		printf("-  2- Contador de Palavras                          -\n");
		printf("-  3- Moda Entre as Letras                          -\n");
		printf("-  4- Moda com estatistica                          -\n");
		printf("-                                                   -\n");
		printf("-                                                   -\n");
		printf("------------------------------------by edubertin-----\n");
		printf("Selecione a opcao desejada:");
		scanf("%d", &opc);

		// Switch para chamar as funções
		switch(opc){

		case 1:
			contadorLetra();
			break;
		case 2:
			contadorPalavra();
			break;
		case 3:
			modaLetras();
			break;
		case 4:
			modaStat();
		default:
			interf();
		}
}

// Main - inicialização do programa
int main()
{
		system("cls");
		fflush(stdin);
		interf();  // chama interface
		return 0;
}

// Eduardo Bertin - www.eduardobertin.com.br