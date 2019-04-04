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

#define strMax 20

/* Tipos */

typedef struct sav{
        int avCod, avPas, avMot;
        float avComp, avLar, avVel, avAlt;
        char avMod[strMax], avFab[strMax];
} av;

typedef struct svo{
       int voNum, avCod, voPas, voRot, voTem;
       char voDat[strMax], voHor[strMax], voAsa[strMax], voAch[strMax];
} vo;

/* Declarações */
void tratarStr(av *aviao);
void tratarStr2(vo *voo);
int cadAv(void);
int lisAv(void);
int delAv(void);
int cadVo(void);
int lisVo(void);
int delVo(void);


/* Função para tratamento da string antes de incluir a struct aviao no bd */
void tratarStr(av *aviao) {
     
     int i;
     
     for(i = 0;i < strMax;i++){
           if(aviao->avMod[i] == '\n')
           aviao->avMod[i] = ' ';
           
           if(aviao->avFab[i] == '\n')
           aviao->avFab[i] = ' ';
     }
}

/* Função para tratamento da string antes de incluir a struct voo no bd */
void tratarStr2(vo *voo) {
     
     int i;
     
     for(i = 0;i < strMax;i++){
           if(voo->voDat[i] == '\n')
           voo->voDat[i] = ' ';
           
           if(voo->voHor[i] == '\n')
           voo->voHor[i] = ' ';
           
           if(voo->voAsa[i] == '\n')
           voo->voAsa[i] = ' ';

           if(voo->voAch[i] == '\n')
           voo->voAch[i] = ' ';
           
     }

}


/* Função de Cadastrar Avião (SET) */
int cadAv(void){
    int i, salvo = 0, opcBus = 1;
    char opc = 'x';
    
/* Aloca memoria para o ponteiro da struct aviao */
    av *aviao = (av *) calloc(1,sizeof(av));
    
    while(opcBus == 1){
    interfacePr();
        printf("Insira o codigo do Aviao (Int):");
        scanf("%d", &aviao->avCod);
        opcBus = dataBusAv(aviao->avCod);
           if(opcBus == 1){
           printf("O aviao com o codigo %d ja esta cadastrado\n", aviao->avCod);
           system("PAUSE>nul");
           }
    }
    interfacePr();
        printf("Insira o modelo do Aviao (String):");
        fflush(stdin);
        fgets(aviao->avMod, strMax, stdin);
     interfacePr();
        printf("Insira o fabrincante (String):");
        fflush(stdin);
        fgets(aviao->avFab, strMax, stdin);
    interfacePr();
        printf("Insira a capacidade de passageiros (Int):");
        scanf("%d", &aviao->avPas);
    interfacePr();
        printf("Insira o comprimento da aeronave (Float):");
        scanf("%f", &aviao->avComp);
    interfacePr();
        printf("Insira a largura da aeronave (Float):");
        scanf("%f", &aviao->avLar);
    interfacePr();
        printf("Insira a velocidade de cruzeiro da aeronave (Float):");
        scanf("%f", &aviao->avVel);
    interfacePr();
        printf("Insira a altitude maxima da aeronave (Float):");
        scanf("%f", &aviao->avAlt);
    interfacePr();
        printf("Insira a potencia da aeronave (Int):");
        scanf("%d", &aviao->avMot);
 
        tratarStr(aviao);
 
    interfacePr();
        printf("Codigo: %d\n", aviao->avCod);
        printf("Modelo: %s | Fabricante: %s\n", aviao->avMod, aviao->avFab);
        printf("Capacidade: %d passageiros\n", aviao->avPas);
        printf("Comprimento: %4.2f metros | Largura: %4.2f\n", aviao->avComp,
                                                               aviao->avLar);
        printf("Velocidade Max: %5.2f km/h | Alt: %4.2f\n", aviao->avVel,
                                                            aviao->avAlt);        
        printf("Motor: %d\n", aviao->avMot);
        
 
        salvo = dataInAv(aviao);
        if(salvo == 1)
                 printf("Arquivo salvo com sucesso!!\n");
        
        free(aviao);
        
        printf("Deseja incluir mais dados ?");

    opc = getch();
    if(opc == 's' || opc == 'S')
           return 0;
   
    return 1;    
}

/* Funcao responsavel por chamar o bd para listar as informacoes (GET) */
int lisAv(void){
                
     int list = 0;
     interfacePr();     
     list = dataListAv(); 
     return 1; 
}

/* Metodo para deletar um registro aviao*/
int delAv(void){

     int codAviao = 0, check = 0;
     
/* Aloca memoria para o ponteiro da struct aviao */
     av *aviao = (av *) calloc(1,sizeof(av));
         
     printf("Insira o codigo do aviao para excluir:");
     scanf("%d", &codAviao);
     
     check = dataDelAv(codAviao, aviao);
     free(aviao);
     return 1;
}

/* Função de Cadastrar o Voo (SET) */
int cadVo(void){
    int i, salvo = 0, opcBus = 1;
    char opc = 'x';
    
/* Aloca memoria para o ponteiro da struct voo */
     vo *voo = (vo *) calloc(1,sizeof(vo));
    
    while(opcBus == 1){
    interfacePr();
        printf("Insira o numero do Voo (Int):");
        scanf("%d", &voo->voNum);
        opcBus = dataBusVo(voo->voNum);
           if(opcBus == 1){
           printf("O voo com o codigo %d ja esta cadastrado\n", voo->voNum);
           system("PAUSE>nul");
           }
    }
    interfacePr();
        printf("Insira a data do Voo formatado (11/07/01):");
        fflush(stdin);
        fgets(voo->voDat, strMax, stdin);
    interfacePr();
        printf("Insira o horário do Voo formatado (09:20):");
        fflush(stdin);
        fgets(voo->voHor, strMax, stdin);
    interfacePr();
        printf("Insira o aeroporto de Saida (String):");
        fflush(stdin);
        fgets(voo->voAsa, strMax, stdin);
    interfacePr();
        printf("Insira o aeroporto de Chegada (String):");
        fflush(stdin);
        fgets(voo->voAch, strMax, stdin);
    interfacePr();
        printf("Insira o numero da Rota (Int):");
        scanf("%d", &voo->voRot);
    interfacePr();
        printf("Insira em minutos o tempo estimado (Int):");
        scanf("%d", &voo->voTem);
    while(opcBus == 0){
    interfacePr();
        i = lisAv();
        printf("Insira o codigo da aeronave (Int):");
        scanf("%d", &voo->avCod);
        opcBus = dataBusAv(voo->avCod);
        if(opcBus == 0){
            printf("O aviao com o codigo %d nao esta cadastrado\n", voo->avCod);
            system("PAUSE>nul");
        }
    }
    interfacePr();
        printf("Insira a quantidade de passageiros a bordo (Int):");
        scanf("%d", &voo->voPas);

        tratarStr2(voo);
 
    interfacePr();
        printf("Numero do Voo: %d\n", voo->voNum);
        printf("Data: %s | Horario: %s\n", voo->voDat, voo->voHor);
        printf("Saida: %s | Chegada: %s\n", voo->voAsa, voo->voAch);        
        printf("Rota Num: %d | Tempo Est: %d minutos \n", voo->voRot,
                                                          voo->voTem);
        printf("Codigo do Aviao: %d | Passageiros a Bordo: %d\n", voo->avCod,
                                                                  voo->voPas);        
        salvo = dataInVo(voo);
        if(salvo == 1)
                 printf("Arquivo salvo com sucesso!!\n");
        
        free(voo);
        printf("Deseja incluir mais dados ?");

    opc = getch();
    if(opc == 's' || opc == 'S')
           return 0;
   
    return 1;    
}

/*Funcao responsavel por chamar o bd dos Voos para listar as informacoes (GET)*/
int lisVo(void){
                
     int list = 0;
     interfacePr();     
     list = dataListVo();  
     
     return 1;
}

/* Metodo para deletar um registro do tipo voo */
int delVo(void){

     int numVoo = 0, check = 0;

/* Aloca memoria para o ponteiro da struct voo */
     vo *voo = (vo *) calloc(1,sizeof(vo));
         
     printf("Insira o numero do voo para excluir:");
     scanf("%d", &numVoo);
     check = dataDelVo(numVoo, voo);
     free(voo);
     return 1;
}
