// sistema  para  manipula��o de  processo 
	
/*******************************************************************************
Autor: MARCOS DE JESUS RAMOS 
Componente Curricular: Algoritmos I
Concluido em: 11/12/2014
Declaro que este c�digo foi elaborado por mim de forma individual e n�o cont�m nenhum
trecho de c�digo de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e p�ginas ou documentos eletr�nicos da Internet. Qualquer trecho de c�digo
de outra autoria que n�o a minha est� destacado com uma cita��o para o autor e a fonte
do c�digo, e estou ciente que estes trechos n�o ser�o considerados para fins de avalia��o.
******************************************************************************************/
	
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	 
	typedef struct dados // estrutura  para  comporta  o dados que  que seram inseridos na lista
	{
	int  num;
	char forum[50];	
	char advog[50];
	char cliente[50];
	struct dados *prox;
	}Dados; //apelido dessa estrutura 
	
	void cadastromanual(Dados**inicio, Dados**novo,int *pi);        // fun��o  para colocara  itens  na lista  encadeada 
	void cadastroporaquivo(Dados **inicio, Dados**novo,int *pi);     // fun��o para colocara itens na lista  por aquivo 
	void consulta (Dados*inicio);                                 // fun��o  para consulta de processo 
	void editar(Dados**inicio);                                 // fun��o  para  excluir  processos 
	void excluir (Dados**inicio);                               //  fun��o  para exibir os processos 
	void exibir(Dados*inicio);                                //  fun��o  para  exibir  os processos
	void backup (Dados*inicio);                           // fun��o vai gaurda  o processo em um arquivo de texto
	
	int  main ()
 {
	 Dados *inicio=NULL,*novo, *aux; //  variaveis  para  cria  a lista  e   exibir  na fun��o principal
	int  i=0,op ;  // variaveis  para  numero do processo e  para o menu
	
	printf("\n\t===================================================\n\n");
	printf("\a \t SISTEMA  PARA  ARQUIVAMENTOS  DE  PROCESSO \n\n");           // mensagem para usuario 
	printf("\t====================================================\n\n");
	
    do{
    	printf("\a");
    do {
    	system("cls");
        printf("\t################################################\n");
	    printf("\tESCOLHA UMA OPCAO, POR FAVOR!\n");
	    printf("\t-----------------------------------");
	    printf("\n\t1->CADASTRO POR  TECLADO");
        printf("\n \t2->CADASTRO  POR ARQUIVO DE TEXTO\n");
	    printf("\t3->CONSULTA\n");
	    printf("\t4->EDITAR\n");
	    printf("\t5->EXCLUIR\n");
	    printf("\t6->EXIBIR\n");
        printf("\t0->SAIR \n");
        printf("\t##################################################\n");
	    printf("\t");
        scanf("%i", & op );
	  }while(op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6 &&op!=0);
	 
	if(op==1) // sendo a  op�ao escolhida  pelo usario 1  vai fazer o cadastro  e apos isso vai exibir na tela  os dados cadastrados 
	{
	system("cls");
	cadastromanual(&inicio,&novo,&i);
	
	aux=inicio;
	
	while(aux!=NULL) // vai exibir  o processos cadastrado 
	{
	printf("%d\n",aux->num);
	printf("%s\n",aux->forum);
	printf("%s\n",aux->advog);
	printf("%s\n",aux->cliente);
	system("pause");
	
	aux=aux->prox;
	
	}
	
	system("cls");
	
	}	
	else if( op==2) // sendo a   op��o escolhida 2  vai  fazer o cadastro por arquivo de texto
	{ 
	cadastroporaquivo( &inicio, &novo,&i);
	aux=inicio;
	
	while(aux!=NULL) // vai exibir os processos cadastrado
	{
	printf("%d\n",aux->num);
	printf("%s\n",aux->forum);
	printf("%s\n",aux->advog);
	printf("%s\n",aux->cliente);
	aux=aux->prox;
    }
	
	
	system("pause");
	system("cls");
	
	} 
	else if(op==3)
	{
	system("cls");
	consulta (inicio);
	system("cls");
	
	}
	
	
	else if(op==4) // sendo essa  op��o escolhida  vai  realiza  edi��o de alguma processo 
    	 {
	
	        editar(&inicio);
	        system("pause");
	        system("cls");
        	aux=inicio;
	
	      while(aux!=NULL) // vai exibir na  tela todos os processo  incluse o editado com asnovas inforam��es contiddas nele
	       {
	         printf("%d\n",aux->num);
	         printf("%s\n",aux->forum);
	         printf("%s\n",aux->advog);
	        printf("%s\n",aux->cliente);
	        system("pause");
	
	       aux=aux->prox;
 	
        	}   
        	system("cls");
        }
	  else if(op==5)// sendo essa  a op��o escolhida  vai realiza a exclus�o  de alagum processo
	  {
	    excluir (&inicio);
	    system("pause");
	    system("cls");
	    aux=inicio;
	
	      while(aux!=NULL) // vaia exibir  todos  os processo que agora  est�o presente na lista
	       {
	         printf("%d\n",aux->num);
	         printf("%s\n",aux->forum);
	         printf("%s\n",aux->advog);
	        printf("%s\n",aux->cliente);
	        system("pause");
	
	       aux=aux->prox;
 	
        	}   
        	system("cls");
	
	  }
	else if(op==6)	// sendo essa op��o escolhida  vaia realiza a exibi��o seguindo a vontade do usuario 
	  {
	   exibir(inicio); 
	   system("cls");
	  		
	  }	 
    } while (op!=0);	
     
	 backup (inicio); // ap�s  todas  as op��es  ter sindo  escolhida e o sistema  vai amarzenar  o processo  presente nele
	 
	 
	  printf("\a \n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");	
	  printf("\a \n 0BRIGADO, ESTAMOS SEMPRE  AQUI PARA LHE  AJUDAR!\n");       //n sauda��oa ao usuario 
      printf("\a \n------------------------------------------------------------\n");
	
	 free(inicio); // excluir  a lista  para na pesa  a  menoria 

 }
void cadastromanual(Dados**inicio, Dados**novo,int*pi)  // fun��o para cadastro dos processos por teclado
 {
	int op; // variavel para o menu
	Dados*aux; // ponteiro   para auxiliar  na manipula��o da lista
	
	do { 
	
	if(*inicio== NULL) // se  a lista  com os dados  estiver  vazia vai realiza  o bloco de abaixo 
	{
	*inicio= (Dados*)malloc(sizeof(Dados));
	(*pi)++;
	(*inicio)->num=*pi;
	printf("\n \t INFORME O NOME  DO FORUM :\n");
	fflush(stdin);
	gets((*inicio)->forum);
	printf("\n \t  INFORME  O NOME DO ADVOGADO \n Dr(a):");
	fflush(stdin);
	gets((*inicio)->advog);
	printf("\n \t INFORME O NOME DO CLIENTE:\n");
	fflush(stdin);
	gets((*inicio)->cliente);
	
	(*inicio)->prox=NULL;
	
	}
	else // caso lista de dados  esteja  com algo  vai realiza  o bloco de  abaixo  
	{
	system ("cls");
	*novo=(Dados*)malloc(sizeof(Dados));
	(*pi)++;
	(*novo)->num=*pi;
	printf("\n \t INFOME O NOME DO  FORUM:\n");
	fflush(stdin);
	gets((*novo)->forum);
	printf("\n \t  INFORME  O NOME DO ADVOGADO  \n Dr(a):");
	fflush(stdin);
	gets((*novo)->advog);
	printf("\n \t INFOME O NOME DO  CLIENTE:\n");
	fflush(stdin);
	gets((*novo)->cliente);
	
	(*novo)->prox=(*inicio);   // os dados  v�o  sendo colocados  no come�o da lista de dados
	(*inicio)=(*novo);
	}
	system("cls");
	do{
	printf("\n \t  GOSTARIA DE FAZER  MAIS  ALGUM CADASTRO :\n"); // vai  perguntar aoa usuario  se ele  que fazer mais  cadastros 
	printf("\n \t1->SIM \n \t2->NAO\n");
	scanf("%i",&op);
	}while(op!=1 && op!=2); // caso op��o seja  deferente de 1 ou 2 o sistema vai continuar pergunado ao usuario at� que ele  escoolha uma das duas op��es 
	
	}while(op!=2);
	
	system("cls");
	}
	void cadastroporaquivo(Dados **inicio,Dados**novo, int*pi) // fun��oa pra  cadastro dos processos por arquivo de texto
	{

	int i,n; // variaveis  para  o la�o  e para o usuario infomara a quantidades  de processo a cadastra 
	FILE*file; // ponteiro para  aquivo 
	
	file=fopen("processo.txt","r"); // o arquivo deve se   chamar  processos 
	
	if(file==NULL) // caso  o arquivo na exitar ou  n�o a tenha o nome necessario o sistema vai  colocara essa  mensagem a seguir na tela   
	{
		system("cls");
		printf("\n \a \t ARQUIVO NAO ENCONTADO\n ");
		system("pause");
		system("cls");
	}
	else //caso n�o  vaia  pedir aoa usari informa  quantos processo ele vaia cadastra por arquivo 
	{
	system("cls");
	printf(" \n \t  \a QUANTOS CADASTRO  O  SR(A) QUE REALIZAR : \n");
	scanf("%i",&n);
	
	 for (i=0;i<n;i++) // la�o vai acontecer  at� alcan�ar  o numero infomandao pelo usario 
     {	
		if(*inicio== NULL) // caso a lista de dados esteja vazia  vai  realizar  os procedimentos a  seguir   
	   {
	    *inicio= (Dados*)malloc(sizeof(Dados));
	    (*pi)++;
	    (*inicio)->num=*pi;
	    fgets((*inicio)->forum,200,file);
    	(*inicio)->forum[strlen((*inicio)->forum)-1]='\0';
    	fgets((*inicio)->advog,200,file);
    	(*inicio)->advog[strlen((*inicio)->advog)-1]='\0'; 
    	fgets((*inicio)->cliente,200,file);
    	(*inicio)->cliente[strlen((*inicio)->cliente)-1]='\0';
    	(*inicio)->prox=NULL;
        }
        else  // caso a lista  n�o  esteja vazia  vai realiza  esse procedimentos a seguir 
        {
        *novo= (Dados*)malloc(sizeof(Dados));
	    (*pi)++;
	    (*novo)->num=*pi;
	    fgets((*novo)->forum,200,file);
    	(*novo)->forum[strlen((*novo)->forum)-1]='\0';
    	fgets((*novo)->advog,200,file);
    	(*novo)->advog[strlen((*novo)->advog)-1]='\0'; 
    	fgets((*novo)->cliente,200,file);
    	(*novo)->cliente[strlen((*novo)->cliente)-1]='\0';	
        	
        (*novo)->prox=(*inicio); 
     	(*inicio)=(*novo);      // com isso  os cados cadastrado  v�oa colocara no come�o da lista 
        	
        }
     }
     
	fclose(file); // fiechar o arquivo 
	
	printf("\a \n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");	
	printf("\a \n \t CADASTRO FEITO COM SUCESSO! \n");	                          // vaia exibir esse mensgaem  na tela 
	printf("\a \n------------------------------------------------------------\n");
	
	}
	
	} 
	void consulta (Dados*inicio)   // fun��oa para a realiza��oa de  consultas 
	{
	Dados *aux;                         // ponteiro  auxiliar par ajuadar na consulta 
	char foro[50], adv[50], clien[50];  // vetores de strings  para ser ultilizado na  conulta  pelo nome do advogado, forum ou cliente
	int  n, op;                         // variaveis para  o menum e para  achara processo pelo seu numero
	
	do {
	aux=inicio;
	do{
	system("cls");
	printf("\n\t__________________________________________\n");
	printf ("\n \t A CONSULTA VAI SER REALIZADA  PELO :\n");
	printf("\t 1->NUMERO DO PROCESSO \n");
	printf("\t 2->PELO NOME DO FORUM \n");
	printf("\t 3->PELO NOME DO ADVOGADO\n");
	printf("\t 4->PELO NOME DO  CLIENTE\n");
	printf(" \t 0-> SAIR \n");
	printf("\n \t------------------------------------------\n");
	scanf ("%d",&op);
	printf("\n++++++++++++++++++++++++++++++++++++++++++++\n");
	}while(op!=1 && op!=2 && op!=3 &&op!=4 && op!=0);  // enquanto o usuario n�o entrara com uma das op��es acima 
	
	if(op==1) // sendo essa op��oa  vaia acontecer os procedimentos a seguir 
	{
	 if(aux==NULL) // verifica se a lsita ta  vazia  se tiver vai acontcer o comando do bloco a seguir  
	{
		printf("\n NAO HA  PROCESSOS \n"); // mensgame  que vaia aparecer quando a lista estiver  vazia 
	    system("pause");
		system ("cls");	
	}
	
	else // se a lista  n�o  estiver vazia 
	{	
	system (" cls");
	printf("\n\t **************************************\n"); // vai solicitar  ao numero do processo com que ele deseja conultar
	printf("\n \t INFORME  O NUMERO  DO PROCESSO \n");
	 scanf("%d", & n);
	
	 	while( aux!=NULL && aux->num !=n) // o la�o vai porcura o processo com o numero indicado 
	  {
	
	   aux=aux->prox;
	  }
	
	 if ( aux==NULL) // se n�o achar o processo  vai exibir  a menasagem a seguir 
	  {
	   system ("cls");
	   printf(" \n \t  PROCESSO NAO ENCONTRADO \n ");
	   system ("pause");
	   system ("cls");
	   }
	  else // achando o processo  vai exibir as informa��es  que le cont�m
	  {
	   printf("\n PROCESSO DE NUMERO %d",aux->num);
	    printf("\n FORUM :%s",aux->forum);
	    printf("\n DOR (A):%s",aux->advog);
	    printf("\n CLIENTE :%s\n", aux->cliente);
	    system ("pause");
	    system (" cls");
	  }	
	} 
	} 
	else if ( op==2) // se u suario optar  por essa  op��o  vaia realiza a consulta por nome do  forum
	{
		
	 if (aux== NULL) // verificar se a lsita  ta vazia  se  estiver vaia exibir a mensagem a seguir 
	  {
	     system ("cls");
	     printf(" \n \t NAO  HA PROCESSO \n");
	     system("pause");
	     system ("cls");
	   }
	
	else // caso  a lista n�oa esteja vazia  vai solicita aoa usuario  informa o nome do forum
	   {
	    system("cls");
	    printf("\n\t**************************************\n");
	    printf(" \n \t INFORME  O NOME DO FORUM \n");
	    fflush(stdin);
	    gets(foro);
				
	     while (aux!= NULL)  // la�o  para procura  processo com  o nome do  forum iguala o informado pelo usuario  	    	
	    {
	
	     if(strcmp(foro,aux->forum)==0)
	     {
	       printf("\n PROCESSO DE NUMERO: %d",aux->num);
	       printf("\n FORUM: %s",aux->forum);
	       printf("\n Dr(a): %s",aux->advog);
	       printf("\n CLIENTE: %s\n", aux->cliente);
	       system ("pause");
	     } 
	       aux=aux->prox;
	     }
		
	 	}
	  }
	else if (op==3) // sendo  essa  a escolha do usuario  vaia realiza a consulta por nome do  advogado 
	  {
	
	    if (aux==NULL) // verificar se a lista ta vazia  se estiver vai exibir a mensagem  a seguir  
	    { 
	 	 system("cls");
	 	 printf("\n \t NAO HA PROCESSO \n"); // mensagem  para lista vazia 
	 	 system("pause");
	 	 system("cls");
	     }
	
	   else //  caso a lista  n�o  esteja  vazia  vai solicitar aoa usuario  o nomde do  advogado que ele  que consulta os processos
	    {
	 	 system("cls");
	     printf("\n\t**************************************\n");
	     printf("\n \t INDIQUE O NOME DO ADVOGADO\n");
	     fflush(stdin);
	     gets(adv);	
		
		 		
	     while (aux!= NULL)   	  // la�o  vai a contecer   para encontar os processo que tenha com advogado o nome informado pelo usuario   	
		 {
	
	      if(strcmp(adv,aux->advog)==0)
	      {
	         printf("\n PROCESSO DE NUMERO: %d",aux->num);
	         printf("\n FORUM: %s",aux->forum);
	         printf("\n Dr(a): %s",aux->advog);
	         printf("\n CLIENTE: %s\n", aux->cliente);
	         system ("pause");
		   }
	        aux=aux->prox;
	      }	
	    }  
	
	  }
	else if( op==4) // sendo essa  escolha  do  usuario   o sistem vai realiza a consulta pelo nome do cliente
	{
		if (aux==NULL) // verifica se a lista ta vazia 
		{
	    	system (" cls");
	    	printf("\n \t NAO HA PROCESSO \n"); // lista vazia  vaia exibir  essa mensagem 
	    	system("pause");
	    	system ("cls");
	    }
		else // caso alista  n�oa esteja  vaia  vazia o sistema  vaia solicitar  ao usuario o nome do cliente que ele  que  consulta os processos 
	 	{
	     system("cls");
	     printf("\n\t**************************************\n");
	     printf("\n \t INDIQUE O NOME DO CLIENTE \n");
	     fflush(stdin);
	     gets(clien);
	    		
	      while (aux!= NULL)   	//  la�o  vaia acontecer  para  verifica a e encontra os  proceso que tem  o nome do cliente informado pelo  usuario     	
		   {
	 	
	        if( strcmp (clien,aux->cliente)==0)
	         {
	           printf("\n PROCESSO DE NUMERO: %d",aux->num);
	           printf("\n FORUM: %s",aux->forum);
	           printf("\n Dr(a): %s",aux->advog);
	           printf("\n CLIENTE: %s\n", aux->cliente);
	          system ("pause");
			 }
	         
	         aux=aux->prox;
	       }	
		
	     }
	
	}
	system("cls");
	}while(op!=0); // sair  de  la�o  de  consultas
	}
	void editar(Dados**inicio)
	{
	
	char foro[50],adv[50],clien[50]; // vetores de strings  para  edi��o 
	int  op , n;                    // variaveis  para o menu e enconta o processo por seu numero 
	Dados*aux;                      // ponteiro auxiliar para  realiza a edi��o   
	aux=(*inicio);
	
	 if(aux==NULL)  // verificar se a lista  ta vazia  se estive vaia exibir a mensagem a  seguir
	{
		printf("\n \t NAO HA  PROCESSOS \n");
	    system("pause");
		system ("cls");	
	}
	else // caso a lista  n�oa esteja  vazia vai solicitara ao usuario  o numero do processo  que ele  que editar
	{	
	system (" cls");
	printf("\n\t **************************************\n");
	printf("\n \t INFORME  O NUMERO  DO PROCESSO \n");
	 scanf("%i", &n);
	
	 	while( aux!=NULL && aux->num !=n) // lalo vaia acontecer para encontara  o processo que vaia ser editado
	  {
	
	   aux=aux->prox;
	  }
	
	 if (aux==NULL) // se chegara no fim  da lista  e  n�oa achar o processo  vai  exibir a mensagem a seguir
	  {
	   system ("cls");
	   printf(" \n \t  PROCESSO NAO ENCONTRADO \n ");
	   system ("pause");
	   system ("cls");
	   }
	  else  // encontrando o processo  o sistema  vai pergunta  ao usuario atraves do menu  a seguir   o que ele gostaria de  editar
	  {
	    system (" cls");
	    do{
	    system("cls");
	    printf("\n \t |||||||||||||||||||||||||||||||||||||||\n");
	    printf("\t********************************************\n");
	    printf(" \a \n \t GOSTARIA DE  EDITAR O QUE \n ?");
	    printf("\n \t 1-FORUM");
	    printf("\n \t 2-ADVOGADO\n");
	    printf("\n \t 3-CLIENTE\n");
	    printf("\t********************************************\n");
	    printf("\n \t ||||||||||||||||||||||||||||||||||||||\n");
	    scanf("%i",&op);
	   }while(op!=1 && op!=2 && op!=3 && op!=0); //  o sistema  s�  vaia seguir se usuario escolher uma da op��es do menu 
	   
	    if(op==1) /* sendo essa op��oa o sistema vai solicitar o novo nome  forum e vai acontcer a substui��o na lista  
		         o nome do  forum pelo que usuario informar*/
	     {
	      system("cls");
	      printf("\n \t  INFOME O NOME DO  NOVO  FORUM\n");
	      fflush(stdin);
	      gets(foro);
	      strcpy (aux->forum,foro);	
		   	    
	      }
	   else if(op==2) /* sendo essa op��oa o sistema vai solicitar o novo nome advogado  e vai acontcer a substui��o na lista  
		         o nome do  advogado pelo que usuario informar*/
	     {
	      system("cls");
	      printf("\n \t  INFOME O NOME DO  NOVO  ADVOGADO\n");
	      fflush(stdin);
	      gets(adv);
	      strcpy(aux->advog,adv);	
	    	
	    }
	    else if( op==3) /* sendo essa op��oa o sistema vai solicitar o novo nome  cliente e vai acontcer a substui��o na lista  
		         o nome do  cliente pelo que usuario informar*/ 
	    {
	      system("cls");
	      printf("\n \t  INFOME O NOME DO  NOVO  CLIENTE\n");
	      fflush(stdin);
	      gets(clien);
	      strcpy (aux->cliente,clien);	
			
	    }
      }
   	
	}
 }
 void excluir (Dados**inicio) // fun��oa para excluir 
 {
 	Dados *aux,*aux2; // ponteiro auxiliar  para  ajudar na exclus�o 
 	int n;            // varivel  para  numero dos processos 
 	
 	aux=(*inicio);
 	
 	if (aux== NULL) // vaia verificar se  a lista ta vazia  se tiver  vai exibir a mensagem a seguir
 	{
 		system("cls");
 		printf("\n \t NAO HA PROCESSO PARA SER REMOVIDO \n");
 		system("pause");
 		system("cls");
 	}
 	else // caso a lista n�o esteja  vazia  o sistema  vaia solicitar  o numero do processo a ser excluido  
 	{	
	   system (" cls");
	   printf("\n\t **************************************\n");
	   printf("\n \t INFORME  O NUMERO  DO PROCESSO \n");
	   scanf("%d", & n);
	
	  while( aux!=NULL && aux->num !=n) // esse  la�o vai procura  o  processo com o numero  que  usuario informou
	  {
	   aux=aux->prox;
	  }
	  if (aux==NULL) // vai verificara se  chegou no fim da  lista e n�oa encontrou  o processo se  isso acontcer vaia exibir  a mensagem a seguir 
	  {
	   system ("cls");
	   printf(" \n \t  PROCESSO NAO ENCONTRADO \n ");
	   system ("pause");
	   system ("cls");
	   }
 	  else // caso a  encontre o processo com o numero informado pelo usuario  o sistema vai procura o pronteiro que  a ponta para ele  
	   {
	   	aux2=(*inicio);
	   	
 	    while(aux2->prox!=aux)// la�o para encontar o ponteiro que aponta para  oprocesso com o numero  que o usuario informou
	    { 
	    aux2=aux2->prox;
	    }
	   
	    aux2->prox=aux->prox; /* atraves desse procedimento o sistema vai passar o ponteiro que aponta  para o processo 
		com o numro informado pelo  usuario para o proximo processo */ 
	    free(aux); // com isso  o sistema vai excluir 

 	  }
 				
 	}
 }
 void exibir(Dados*inicio) // fun��o para exibir os processo  pelo gosto do usuario 
 {
 	Dados*aux,*aux2,*aux3=NULL; // ponteiro   auxiliares 
 	int op;                  // variaveis  para o menu 
 	
 	aux=inicio;
 	
 	if(aux==NULL) // vai verifica se a lista ta vazia se estiver vai exibir a mensagem a seguir 
 	{
 		printf("\n \t  NAO HA PROCESSO  PARA SER EXIBIDO\n");
 		system("pause");
 		system("cls");
 	}
 	else // caso a lista  n� esteja  vazia  o sistema vaia solicitar  qual � a ordem de exibi��o que o usuario que 
	 {
	  do{
	 	system("cls");
	 	printf("\n \t********************************************\n");
	 	printf("\n \t OS PROCESSOS SERAO  EXIBIDOS  EM QUAL ORDEM ? \n");
	 	printf("\n \t 1-DECRESECNTE\n");
	 	printf("\n \t 2-CESCENTE\n");
	 	printf("\n \t*********************************************\n");
	 	scanf("%i",&op);
	   }while(op!=1 && op!=2); // enquanto o usuario n�oa informa o dos numero do menu  vaia acontcer esse la�o
	    
	 	if(op==1)// sendo essa a escolha do usuario  o sistema vaia exibir os processo  em ordem decresente
	 	{
           system("cls");
	 		while(aux!=NULL)// la�o pra exibir os porcesso
	 		{
	 		  printf("\n PROCESSO DE NUMERO: %d",aux->num);
	           printf("\n FORUM: %s",aux->forum);
	           printf("\n Dr(a): %s",aux->advog);
	           printf("\n CLIENTE: %s\n", aux->cliente);
	          aux=aux->prox;
	 			
	 			system("pause");
	 		}
	 	}
	  	else if (op==2)/* sendo essa a escolha do usuario o sistema vai criar uma lista
		    nesse parte para exibir essa  nova lista que est� com os processo em ordem crescente */ 
	 	{
	 		while(aux!=NULL)
	 		{
	 			
	 			if(aux3==NULL)
	 			{
	 				aux3=(Dados*)malloc(sizeof(Dados));
	 				aux3->num =aux->num;
			        strcpy(aux3->forum,aux->forum);
	 			    strcpy(aux3->advog,aux->advog);
	 			    strcpy(aux3->cliente,aux->cliente);
	 				aux3->prox=NULL;
	 				
	 			}
	 			else 
				 {
				 	aux2=aux3;
				 	
				 	aux3=(Dados*)malloc(sizeof(Dados));
	 				aux3->num =aux->num;
	 			    strcpy(aux3->forum,aux->forum);
	 			    strcpy(aux3->advog,aux->advog);
	 			    strcpy(aux3->cliente,aux->cliente);
	 			   
				 	aux3->prox=aux2;
	 			}
	 			
	 			aux=aux->prox;
	 			
	 		}
	 		
	 		while(aux3!=NULL)
	 		{
	 			
	 		   printf("\n PROCESSO DE NUMERO: %d",aux3->num);
	           printf("\n FORUM: %s",aux3->forum);
	           printf("\n Dr(a): %s",aux3->advog);
	           printf("\n CLIENTE: %s\n", aux3->cliente);
	           aux3=aux3->prox;
	 			
	 			system("pause");
				 	
	 		}
	 		
	 	}
	
	}
}
void backup (Dados*inicio) // fun��o para guarda  os dados  que fora inferido no sistema  
{
	Dados*aux; // ponteiro  auxiliar 
	FILE*arq; // ponteiro para arquivo 
	aux=inicio;
	arq=fopen("PROCESSOS.txt","a+"); // criara um arquivo txt
	
   fprintf(arq,"PROCESSO \n");// uma mensagem  no arquivo 
   
   while(aux!=NULL) // la�o para escrever os dados  da lista no arquivo 
   {
	fprintf(arq,"\n PROCESSO DE NUMERO: %d",aux->num);
	fprintf(arq,"\n FORUM: %s",aux->forum);
	fprintf(arq,"\n Dr(a): %s",aux->advog);
	fprintf(arq,"\n CLIENTE: %s\n", aux->cliente);
	
	aux=aux->prox;
	
   }
	fclose(arq);// feichar  o arquivo 
}
