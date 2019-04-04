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

int dataInAv(av *aviao);
int dataBusAv(int avCod);
int dataListAv(void);
int dataDelAv(int cod, av *aviao);     
int dataInVo(vo *voo);
int dataBusVo(int voNum);
int dataListVo(void);
int dataDelVo(int cod, vo *voo);
int dataUniVo(void);
void dataUniAv(vo *voo);
char avBin[] = "data\\avBin.bin";
char voBin[] = "data\\voBin.bin";
char avBinTmp[] = "data\\avBinTmp.bin";
char voBinTmp[] = "data\\voBinTmp.bin";

/* Recebe a estrutura do core e adiciona ao bd */
int dataInAv(av *aviao){

    FILE *fp;    

    /* Abrindo aqruivo binario para escrita */
    fp = fopen(avBin, "ab");

    /* Verifica se existe fp */
    if(!fp){
            printf("Erro ao abrir arquivo binario\n");
            return 0;
    }
    
    fwrite(aviao, sizeof(av),1,fp);
    
    fclose(fp);
    
/* Retorna 1 se for salvo */
    return 1;
}

/* Busca no bd se o aviao existe retornando 1 se sim */
int dataBusAv(int avCod){
    
    FILE *fp;

/* Aloca memoria para o ponteiro da struct aviao */
    av *aviao = (av *) calloc(1,sizeof(av));
    


/* Abrindo arquivo binário para escrita */     
     fp = fopen(avBin, "rb");

     /*Verifica se é existente*/
     if(!fp){
             printf("Erro ao abrir arquivo binario\n");
             return 0;        
     
     }    
    
    while(fread(aviao,sizeof(av),1,fp) != 0){
           if(avCod == aviao->avCod)
           return 1;
    }   
    
    free(aviao);
    return 0;
}

/*Chamada pelo core, um get do bd*/
int dataListAv(){
     
     FILE *fp;
     
/* Aloca memoria para o ponteiro da struct aviao */
     av *aviao = (av *) calloc(1,sizeof(av));
    
    /* Abrindo arquivo binário para escrita */     
     fp=fopen(avBin, "rb");

     /*Verifica se é existente*/
     if(!fp){
             printf("Erro ao abrir arquivo binario\n");
             return 0;        
     
     }

     /* Busca e imprime informacoes do data */
     printf("Cod.         Modelo                  Fabricante      Capacidade   "
                                                               " Altitude\n\n");
     while(fread(aviao,sizeof(av),1,fp) != 0){
     printf("%4d %20s %20s       %3d           %6.2f \n", aviao->avCod, 
                                                          aviao->avMod,
                                                          aviao->avFab,
                                                          aviao->avPas,
                                                          aviao->avAlt);
     }
     system("PAUSE>nul");
     free(aviao);
     fclose(fp);
     return 0;
}     

/* Metodo que recebe um codigo e uma estrutra e exclui do bd */
int dataDelAv(int cod, av *aviao){
    
    FILE *fp, *fpTmp;
    int avEnc = 0;
    
/* Abrindo arquivo binário para escrita */     
     fp = fopen(avBin, "rb");

     /*Verifica se é existente*/
     if(!fp){
             printf("Erro ao abrir arquivo binario\n");
             return 0;        
     
     }    
    
/* Abrindo arquivo temporario binário para escrita */     
     fpTmp = fopen(avBinTmp, "wb");

     /*Verifica se é existente*/
     if(!fpTmp){
             printf("Erro ao abrir arquivo binario\n");
             return 0;        
     
     }    
    
    while(fread(aviao,sizeof(av),1,fp) != 0){
          if(cod == aviao->avCod){
          printf("Registro deletado com sucesso.\n");
          system("PAUSE>nul");          
          avEnc = 1;
          } else {
          fwrite(aviao, sizeof(av), 1, fpTmp);
          }                          
    }    
    
    if(!avEnc){
       printf("Nenhum registro com o codigo %d foi encontrado.\n", cod);
       system("PAUSE>nul");
    }
    
    fclose(fp);
    fclose(fpTmp);
    
    remove(avBin);
    rename(avBinTmp, avBin);
    
    return 0;
    
    
}

/* Metodo responsavel pela inserçao da strutura voo no banco de dados*/
int dataInVo(vo *voo){

    FILE *fp;    

    /* Abrindo aqruivo binario para escrita */
    fp = fopen(voBin, "ab");

    /* Verifica se existe fp */
    if(!fp){
            printf("Erro ao abrir arquivo binario\n");
            return 0;
    }
    
    fwrite(voo, sizeof(vo),1,fp);
    
    fclose(fp);
    
/* Retorna 1 se for salvo */
    return 1;
}

/* Busca no bd se o voo existe retornando 1 se sim */
int dataBusVo(int voNum){
    
    FILE *fp;

/* Aloca memoria para o ponteiro da struct aviao */
    vo *voo = (vo *) calloc(1,sizeof(vo));
    
/* Abrindo arquivo binário para escrita */     
     fp = fopen(voBin, "rb");

     /*Verifica se é existente*/
     if(!fp){
             printf("Erro ao abrir arquivo binario\n");
             return 0;        
     
     }    
    
    while(fread(voo,sizeof(vo),1,fp) != 0){
           if(voNum == voo->voNum)
           return 1;
    }   
    
    free(voo);
    return 0;
}

/*Chamada pelo core, um get do bd para lista voos*/
int dataListVo(){
     
     FILE *fp;
     
/* Aloca memoria para o ponteiro da struct voo */
     vo *voo = (vo *) calloc(1,sizeof(vo));
    
    /* Abrindo arquivo binário para escrita */     
     fp=fopen(voBin, "rb");

     /*Verifica se é existente*/
     if(!fp){
             printf("Erro ao abrir arquivo binario\n");
             return 0;        
     
     }

     /* Busca e imprime informacoes do data */
     printf("   Num         Data                Saida            Chegada");
     printf("        P.Bordo \n\n");
     while(fread(voo,sizeof(vo),1,fp) != 0){
     printf("  %4d      %8s   %15s    %15s           %3d\n", voo->voNum,
                                                             voo->voDat,
                                                             voo->voAsa,
                                                             voo->voAch,
                                                             voo->voPas);
     }
     system("PAUSE>nul");
     free(voo);
     fclose(fp);
     return 0;
}     

/* Metodo que recebe um codigo e uma estrutra e exclui do bd */
int dataDelVo(int cod, vo *voo){
    
    FILE *fp, *fpTmp;
    int voEnc = 0;
    
/* Abrindo arquivo binário para escrita */     
     fp = fopen(voBin, "rb");

     /*Verifica se é existente*/
     if(!fp){
             printf("Erro ao abrir arquivo binario\n");
             return 0;        
     
     }    
    
/* Abrindo arquivo temporario binário para escrita */     
     fpTmp = fopen(voBinTmp, "wb");

     /*Verifica se é existente*/
     if(!fpTmp){
             printf("Erro ao abrir arquivo binario\n");
             return 0;        
     
     }    
    /* Percorre o arquivo binario do DB copiando todos as structs não       */
    /* selecionadas em um novo arquivo binario, removendo a struct desejada */
    while(fread(voo,sizeof(vo),1,fp) != 0){
          if(cod == voo->voNum){
          printf("Registro deletado com sucesso.\n");
          system("PAUSE>nul");          
          voEnc = 1;
          } else {
          fwrite(voo, sizeof(vo), 1, fpTmp);
          }                          
    }    
    
    if(!voEnc){
       printf("Nenhum registro com o numero %d foi encontrado.\n", cod);
       system("PAUSE>nul");
    }
    
    fclose(fp);
    fclose(fpTmp);
    
    remove(voBin);
    rename(voBinTmp, voBin);
    
    return 0;
    
}

int dataUniVo(void){
    
     FILE *fp;
    

/* Aloca memoria para o ponteiro da struct voo */
     vo *voo = (vo *) calloc(1,sizeof(vo));
     
    /* Abrindo arquivo binário para escrita */     
     fp=fopen(voBin, "rb");

     /*Verifica se é existente*/
     if(!fp){
             printf("--  Nao a dados no banco de dados                         "
                                                        "                --\n");
             return 0;        
     
     }

     /* Busca e imprime informacoes do data */
     printf("--   Num          Mod. Aviao        Data     Hora    Tp.(min)     "
                                                                " Cap.   --\n");
     while(fread(voo,sizeof(vo),1,fp) != 0){
           dataUniAv(voo);           
     }
     free(voo);
     fclose(fp);
     return 0;
}

void dataUniAv(vo *voo){
     
     FILE *fpa;

/* Aloca memoria para o ponteiro da struct aviao */
     av *aviao = (av *) calloc(1,sizeof(av));
     
    /* Abrindo arquivo binário para escrita */     
     fpa=fopen(avBin, "rb");

     /*Verifica se é existente*/
     if(!fpa){
             printf("Erro ao abrir arquivo binario\n");
             return;     
     }

     while(fread(aviao,sizeof(av),1,fpa) != 0){
           if(voo->avCod == aviao->avCod){
           printf("--  %4d %20s   %8s   %s      %3d       %3d%%    --\n",
                                              voo->avCod, 
                                              aviao->avMod,
                                              voo->voDat,
                                              voo->voHor,
                                              voo->voTem,
                                              (voo->voPas * 100)/aviao->avPas);
           }
           
     }
     free(aviao);
     fclose(fpa);
     return;

}
