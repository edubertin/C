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


/*Declaracoes*/
void interfacePr(void);
void interfaceCa(void);
int interfacePn(void);
void interfaceAv(void);
void interfaceVo(void);



int rtn;
char opcc; 


/* Interface do Topo */
void interfacePr(void){
    system("cls");
    printf("-------------------------------------------------------------------"
                                                                 "---------\n");
    printf("-- VoeBem - Sistema de Gerenciamento de Voos                       "
                                                                 "       --\n");
    printf("-- V1.0 - by edubertin                                             "
                                                                 "       --\n");
    printf("-------------------------------------------------------------------"
                                                                 "---------\n");
}

void interfaceCa(void){
     
    printf("--                                                                 "
                                                                 "       --\n");
    printf("--    1- Cadastro                                                  "
                                                                 "       --\n");        
    printf("--    2- Consultar                                                 "
                                                                 "       --\n");
    printf("--    3- Excluir                                                   "
                                                                 "       --\n");
    printf("--    4- Sair                                                      "
                                                                 "       --\n");
    printf("--                                                                 "
                                                                 "       --\n");
    printf("-------------------------------------------------------------------"
                                                                 "---------\n");
     
}


int interfacePn(){
    int i=0;

    while(opcc != '3'){
    
    /*Interface Painel principal*/

    interfacePr();
    printf("--                                                                 "
                                                                 "       --\n");
    printf("--                                                                 "
                                                                 "       --\n");
    i = dataUniVo();

    printf("--                                                                 "
                                                                 "       --\n");
    printf("--                                                                 "
                                                                 "       --\n");
    printf("-------------------------------------------------------------------"
                                                                 "---------\n");
    printf("-- 1 Aviao | 2 Voo | 3 Sair                                        "
                                                                 "       --\n");
    printf("-------------------------------------------------------------------"
                                                                 "---------\n");

    /* Entrada */
    
    opcc = getch();
    
    /* Switch de chamada para tela de cadastro */
    
    switch(opcc){
                 case '1':
                      interfaceAv();
                      break;
                 case '2':
                      interfaceVo();
                      break;
                 default:
                      rtn = 1;
                      break;
                 }
    
    
    }
    return rtn;
}


void interfaceAv(void){
     int opccN = 0;

    /*Interface Painel principal*/

    interfacePr();
    interfaceCa();
    
    /* Entrada */
    
    opcc = getch();
    
    /* Switch de chamada para tela de cadastro */
    
    switch(opcc){
                 case '1':
                      while(opccN == 0){
                      opccN = cadAv();            
                      }                            
                      break;
                 case '2':
                      opccN = lisAv();
                      break;
                 case '3':
                      opccN = lisAv();
                      opccN = delAv();
                      break;
                 case '4':
                      break;
                 default:
                      rtn = 1;
                      break;
                 }
}

void interfaceVo(void){
     int opccN = 0;

       
    /*Interface Painel principal*/

    interfacePr();
    interfaceCa();

    /* Entrada */
    
    opcc = getch();
    
    /* Switch de chamada para tela de cadastro */
    
    switch(opcc){
                 case '1':
                      while(opccN == 0){
                      opccN = cadVo();            
                      }                            
                      break;
                 case '2':
                      opccN = lisVo();
                      break;
                 case '3':
                      opccN = lisVo();
                      opccN = delVo();
                      break;
                 case '4':
                      break;
                 default:
                      rtn = 1;
                      break;
                 }
}
