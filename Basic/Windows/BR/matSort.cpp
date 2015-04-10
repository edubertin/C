// Eduardo Bertin
// www.eduardobertin.com.br
// Esse código foi feito inteiro do 0, sem nenhum script como base
//
// 1- Inserir matriz dinamica
// 2- Ordernar crescente e decrescente uma linha
// 3- Ordernar crescente e decrescente uma coluna
// 4- Ordernar crescente e decrescente a diagonal 1
// 5- Ordernar crescente e decrescente a diagonal 2
//
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"

void inserir_matriz(int, int);
void interfacem(int);
void ordena_matriz(int, int);

int matriz[50][50];
int imax_global = 0;
int jmax_global = 0;


void ordena_matriz(int ord,int ij){

int aux_matr = 0;

ij--;

		switch(ord){
			case 1:

				for(int i=0;i<imax_global;i++){

				for(int j=0;j<jmax_global;j++){
				
					if(matriz[ij][j] > matriz[ij][j+1] && matriz[ij][j+1] != 0){
					
						aux_matr = matriz[ij][j+1];
						matriz[ij][j+1] = matriz[ij][j];
						matriz[ij][j] = aux_matr;
					
					}
												
				}
			}

			interfacem(1);
			break;
			case 2:

				for(int i=0;i<imax_global;i++){

				for(int j=0;j<jmax_global;j++){
				
					if(matriz[ij][j] < matriz[ij][j+1] && matriz[ij][j+1] != 0){
					
						aux_matr = matriz[ij][j+1];
						matriz[ij][j+1] = matriz[ij][j];
						matriz[ij][j] = aux_matr;
					
					}
												
				}
			}

			interfacem(1);
			break;
			case 3:

				for(int i=0;i<imax_global;i++){

				for(int j=0;j<jmax_global;j++){
				
					if(matriz[j][ij] > matriz[j+1][ij] && matriz[j+1][ij] != 0){
					
						aux_matr = matriz[j][ij];
						matriz[j][ij] = matriz[j+1][ij];
						matriz[j+1][ij] = aux_matr;
					
					}
												
				}
			}

			interfacem(1);
			break;
			case 4:
				for(int i=0;i<imax_global;i++){

				for(int j=0;j<jmax_global;j++){
				
					if(matriz[j][ij] < matriz[j+1][ij] && matriz[j+1][ij] != 0){
					
						aux_matr = matriz[j][ij];
						matriz[j][ij] = matriz[j+1][ij];
						matriz[j+1][ij] = aux_matr;
					
					}
												
				}
			}

			interfacem(1);
			break;
			case 5:
				ij++;
				for(int teste=0;teste<imax_global;teste++){
				
					for(int i=0;i<imax_global;i++){

						for(int j=0;j<jmax_global;j++){
							if(ij == 1){
								if(matriz[i][j] > matriz[i+1][j+1] && matriz[i+1][j+1] != 0){
									if(i==j){
							
										aux_matr = matriz[i+1][j+1];
										matriz[i+1][j+1] = matriz[i][j];
										matriz[i][j] = aux_matr;
									}						
								}
							}		
							if(ij == 2){
								if(matriz[i][j] < matriz[i+1][j-1] && matriz[i+1][j-1] != 0){
										if((i+j)==(imax_global-1)){											
											aux_matr = matriz[i+1][j-1];
											matriz[i+1][j-1] = matriz[i][j];
											matriz[i][j] = aux_matr;
										}
														
								}
							}
						}
					}
				}
			interfacem(1);
			break;
			case 6:
				ij++;
				for(int teste=0;teste<imax_global;teste++){
				
					for(int i=0;i<imax_global;i++){

						for(int j=0;j<jmax_global;j++){
							if(ij == 1){
								if(matriz[i][j] < matriz[i+1][j+1] && matriz[i+1][j+1] != 0){
									if(i==j){
							
										aux_matr = matriz[i+1][j+1];
										matriz[i+1][j+1] = matriz[i][j];
										matriz[i][j] = aux_matr;
									}						
								}
							}		
							if(ij == 2){
								if(matriz[i][j] > matriz[i+1][j-1] && matriz[i+1][j-1] != 0){
										if((i+j)==(imax_global-1)){											
											aux_matr = matriz[i+1][j-1];
											matriz[i+1][j-1] = matriz[i][j];
											matriz[i][j] = aux_matr;
										}
														
								}
							}
						}
					}
				}
			interfacem(1);
			break;
		default:
			printf("Opcao errada\n");
			Sleep(2000);
			interfacem(1);
		break;
	
		}
}

void inserir_matriz(int imax, int jmax){

	imax_global = imax;
	jmax_global = jmax;
	
	fflush(stdin);
	system("cls");
	printf("--------------------------------------------------------------------\n");
	printf("Digite os numeros da matriz:\n");

	for(int i=0;i<imax;i++){
		
		for(int j=0;j<jmax;j++){

			printf("Digite a posicao [%d][%d]:", i, j);
			scanf("%d", &matriz[i][j]);
			
		
		}
		printf("\n");
	
	}

	interfacem(0);

}

void interfacem(int opc){
	
	fflush(stdin);
	system("cls");
	int opc_case0;
	int opc_case1;
	int opc_fc;

	switch(opc){
	
	case 0:
		printf("-----------------------------------by edubertin-------------\n");
		printf("Matrizes 5x5\n\n");
		printf("1- Inserir Matriz\n");
		printf("2- Ordenar Matriz\n");
		printf("Digite a opcao desejada:\n");
		scanf("%d", &opc_case0);

			switch(opc_case0){
				case 1:
				inserir_matriz(5,5);
				break;
				case 2:
				if(imax_global != 0){
				interfacem(1);
				} else {
				printf("Voce necessita inserir a matriz\n");
				Sleep(2000);
				interfacem(0);				
				}
				break;
				default:
					interfacem(0);
				break;
			}
	break;	
	case 1:
		printf("------------------------------------------------\n");
		for(int i=0;i<imax_global;i++){
			
			
			for(int j=0;j<jmax_global;j++){
			
				printf("|  %d  |", matriz[i][j]);
			
			}
		
			printf("\n");
				
		}
		
		printf("------------------------------------------------\n");
		printf("1- Ordernar crescente uma linha\n");
		printf("2- Ordernar decrescente uma linha\n");
		printf("3- Ordernar crescente uma coluna\n");
		printf("4- Ordernar decrescente uma coluna\n");
		printf("5- Ordernar crescente diagonal\n");
		printf("6- Ordernar decrescente diagonal\n");
		printf("Escolha sua opcao:");
		scanf("%d", &opc_case1);
		
		switch(opc_case1){
		
			case 1:
				printf("Qual linha?:\n");
				scanf("%d", &opc_fc);
				ordena_matriz(1,opc_fc);
			break;
			case 2:
				printf("Qual linha ?:\n");
				scanf("%d", &opc_fc);
				ordena_matriz(2,opc_fc);
			break;
			case 3:
				printf("Qual coluna?\n");
				scanf("%d", &opc_fc);
				ordena_matriz(3,opc_fc);
			break;
			case 4:
				printf("Qual coluna?\n");
				scanf("%d", &opc_fc);
				ordena_matriz(4,opc_fc);
			break;
			case 5:
				printf("Qual diagonal?\n");
				scanf("%d", &opc_fc);
				ordena_matriz(5,opc_fc);
			break;
			case 6:
				printf("Qual diagonal?\n");
				scanf("%d", &opc_fc);
				ordena_matriz(6,opc_fc);
			break;
			default:
				interfacem(1);
				printf("Opcao errado\n");
			break;

		
		}

		system("pause");


	break;
	default:
		system("cls");
		printf("Opcao errada\n");
		Sleep(1000);
		interfacem(1);
	break;
		
	}

}

int main()
{

	interfacem(0);


	return 0;
}

