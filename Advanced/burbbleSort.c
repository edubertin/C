// Eduardo Bertin
// contato@eduardobertin.com.br
// https://github.com/edubertin

// 1 - Simple BurbbleSort with setted vector.

#include "stdio.h"
#include "stdlib.h"

int main(void){
	int i, j, aux, max = 10;	

// Creating setted vector
	int vector[] = {5,4,6,2,1,3,7,8,9,0};

// Showing original matrix
	printf("Vector without sorting by: \n");
	for(i = 0;i < max;i++) printf("| %i |", vector[i]);

// Put Burbble Loop
	for( j=0; j<max; j++){
		for( i=0; i < max-1; i++){
			if(vector[i] > vector[i+1]){
				aux = vector[i+1];
				vector[i+1] = vector[i];
				vector[i] = aux;
			}  			
		}
	}
	
// Showing modified matrix
	printf("Vector with sorting by: \n");
	for(i = 0;i < max;i++) printf("| %d |", vector[i]);
	
	return 1;
	
};
