/*  Voe Bem - sistema de gerenciamento de voos */
/*  Desenvolvido por Eduardo Bertin            */
/*  contato@eduardobertin.com.br               */
/*  www.eduardobertin.com.br                   */
/*                                             */
/*  ui.h : biblioteca user interface.          */
/*  core.h : gerenciamento de estruturas.      */
/*  data.h : arquivamento, banco de dados.     */
/*                                             */
/*---------------------------------------------*/
/**/
/**/
/**/
/**/

/* Includes */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "lib/ui.h"
#include "lib/core.h"
#include "lib/data.h"


int main(){
    
    int i = 0;
    
    while(i==0) {
        system("cls");
        i = interfacePn();                
    };

    return 0;

}
