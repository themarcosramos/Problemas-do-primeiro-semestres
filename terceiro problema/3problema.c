// sistema  para  manipulação de  processo 
	
/*******************************************************************************
Autor: MARCOS DE JESUS RAMOS 
Componente Curricular: Algoritmos I
Concluido em: 11/12/2014
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
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
	
	void cadastromanual(Dados**inicio, Dados**novo,int *pi);        // função  para colocara  itens  na lista  encadeada 
	void cadastroporaquivo(Dados **inicio, Dados**novo,int *pi);     // função para colocara itens na lista  por aquivo 
	void consulta (Dados*inicio);                                 // função  para consulta de processo 
	void editar(Dados**inicio);                                 // função  para  excluir  processos 
	void excluir (Dados**inicio);                               //  função  para exibir os processos 
	void exibir(Dados*inicio);                                //  função  para  exibir  os processos
	void backup (Dados*inicio);                           // função vai gaurda  o processo em um arquivo de texto
	
	int  main ()
 {
	 Dados *inicio=NULL,*novo, *aux; //  variaveis  para  cria  a lista  e   exibir  na função principal
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
	 
	if(op==1) // sendo a  opçao escolhida  pelo usario 1  vai fazer o cadastro  e apos isso vai exibir na tela  os dados cadastrados 
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
	else if( op==2) // sendo a   opção escolhida 2  vai  fazer o cadastro por arquivo de texto
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
	
	
	else if(op==4) // sendo essa  opção escolhida  vai  realiza  edição de alguma processo 
    	 {
	
	        editar(&inicio);
	        system("pause");
	        system("cls");
        	aux=inicio;
	
	      while(aux!=NULL) // vai exibir na  tela todos os processo  incluse o editado com asnovas inforamções contiddas nele
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
	  else if(op==5)// sendo essa  a opção escolhida  vai realiza a exclusão  de alagum processo
	  {
	    excluir (&inicio);
	    system("pause");
	    system("cls");
	    aux=inicio;
	
	      while(aux!=NULL) // vaia exibir  todos  os processo que agora  estão presente na lista
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
	else if(op==6)	// sendo essa opção escolhida  vaia realiza a exibição seguindo a vontade do usuario 
	  {
	   exibir(inicio); 
	   system("cls");
	  		
	  }	 
    } while (op!=0);	
     
	 backup (inicio); // após  todas  as opções  ter sindo  escolhida e o sistema  vai amarzenar  o processo  presente nele
	 
	 
	  printf("\a \n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");	
	  printf("\a \n 0BRIGADO, ESTAMOS SEMPRE  AQUI PARA LHE  AJUDAR!\n");       //n saudaçãoa ao usuario 
      printf("\a \n------------------------------------------------------------\n");
	
	 free(inicio); // excluir  a lista  para na pesa  a  menoria 

 }
void cadastromanual(Dados**inicio, Dados**novo,int*pi)  // função para cadastro dos processos por teclado
 {
	int op; // variavel para o menu
	Dados*aux; // ponteiro   para auxiliar  na manipulação da lista
	
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
	
	(*novo)->prox=(*inicio);   // os dados  vão  sendo colocados  no começo da lista de dados
	(*inicio)=(*novo);
	}
	system("cls");
	do{
	printf("\n \t  GOSTARIA DE FAZER  MAIS  ALGUM CADASTRO :\n"); // vai  perguntar aoa usuario  se ele  que fazer mais  cadastros 
	printf("\n \t1->SIM \n \t2->NAO\n");
	scanf("%i",&op);
	}while(op!=1 && op!=2); // caso opção seja  deferente de 1 ou 2 o sistema vai continuar pergunado ao usuario até que ele  escoolha uma das duas opções 
	
	}while(op!=2);
	
	system("cls");
	}
	void cadastroporaquivo(Dados **inicio,Dados**novo, int*pi) // funçãoa pra  cadastro dos processos por arquivo de texto
	{

	int i,n; // variaveis  para  o laço  e para o usuario infomara a quantidades  de processo a cadastra 
	FILE*file; // ponteiro para  aquivo 
	
	file=fopen("processo.txt","r"); // o arquivo deve se   chamar  processos 
	
	if(file==NULL) // caso  o arquivo na exitar ou  não a tenha o nome necessario o sistema vai  colocara essa  mensagem a seguir na tela   
	{
		system("cls");
		printf("\n \a \t ARQUIVO NAO ENCONTADO\n ");
		system("pause");
		system("cls");
	}
	else //caso não  vaia  pedir aoa usari informa  quantos processo ele vaia cadastra por arquivo 
	{
	system("cls");
	printf(" \n \t  \a QUANTOS CADASTRO  O  SR(A) QUE REALIZAR : \n");
	scanf("%i",&n);
	
	 for (i=0;i<n;i++) // laço vai acontecer  até alcançar  o numero infomandao pelo usario 
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
        else  // caso a lista  não  esteja vazia  vai realiza  esse procedimentos a seguir 
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
     	(*inicio)=(*novo);      // com isso  os cados cadastrado  vãoa colocara no começo da lista 
        	
        }
     }
     
	fclose(file); // fiechar o arquivo 
	
	printf("\a \n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");	
	printf("\a \n \t CADASTRO FEITO COM SUCESSO! \n");	                          // vaia exibir esse mensgaem  na tela 
	printf("\a \n------------------------------------------------------------\n");
	
	}
	
	} 
	void consulta (Dados*inicio)   // funçãoa para a realizaçãoa de  consultas 
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
	}while(op!=1 && op!=2 && op!=3 &&op!=4 && op!=0);  // enquanto o usuario não entrara com uma das opções acima 
	
	if(op==1) // sendo essa opçãoa  vaia acontecer os procedimentos a seguir 
	{
	 if(aux==NULL) // verifica se a lsita ta  vazia  se tiver vai acontcer o comando do bloco a seguir  
	{
		printf("\n NAO HA  PROCESSOS \n"); // mensgame  que vaia aparecer quando a lista estiver  vazia 
	    system("pause");
		system ("cls");	
	}
	
	else // se a lista  não  estiver vazia 
	{	
	system (" cls");
	printf("\n\t **************************************\n"); // vai solicitar  ao numero do processo com que ele deseja conultar
	printf("\n \t INFORME  O NUMERO  DO PROCESSO \n");
	 scanf("%d", & n);
	
	 	while( aux!=NULL && aux->num !=n) // o laço vai porcura o processo com o numero indicado 
	  {
	
	   aux=aux->prox;
	  }
	
	 if ( aux==NULL) // se não achar o processo  vai exibir  a menasagem a seguir 
	  {
	   system ("cls");
	   printf(" \n \t  PROCESSO NAO ENCONTRADO \n ");
	   system ("pause");
	   system ("cls");
	   }
	  else // achando o processo  vai exibir as informações  que le contém
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
	else if ( op==2) // se u suario optar  por essa  opção  vaia realiza a consulta por nome do  forum
	{
		
	 if (aux== NULL) // verificar se a lsita  ta vazia  se  estiver vaia exibir a mensagem a seguir 
	  {
	     system ("cls");
	     printf(" \n \t NAO  HA PROCESSO \n");
	     system("pause");
	     system ("cls");
	   }
	
	else // caso  a lista nãoa esteja vazia  vai solicita aoa usuario  informa o nome do forum
	   {
	    system("cls");
	    printf("\n\t**************************************\n");
	    printf(" \n \t INFORME  O NOME DO FORUM \n");
	    fflush(stdin);
	    gets(foro);
				
	     while (aux!= NULL)  // laço  para procura  processo com  o nome do  forum iguala o informado pelo usuario  	    	
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
	
	   else //  caso a lista  não  esteja  vazia  vai solicitar aoa usuario  o nomde do  advogado que ele  que consulta os processos
	    {
	 	 system("cls");
	     printf("\n\t**************************************\n");
	     printf("\n \t INDIQUE O NOME DO ADVOGADO\n");
	     fflush(stdin);
	     gets(adv);	
		
		 		
	     while (aux!= NULL)   	  // laço  vai a contecer   para encontar os processo que tenha com advogado o nome informado pelo usuario   	
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
		else // caso alista  nãoa esteja  vaia  vazia o sistema  vaia solicitar  ao usuario o nome do cliente que ele  que  consulta os processos 
	 	{
	     system("cls");
	     printf("\n\t**************************************\n");
	     printf("\n \t INDIQUE O NOME DO CLIENTE \n");
	     fflush(stdin);
	     gets(clien);
	    		
	      while (aux!= NULL)   	//  laço  vaia acontecer  para  verifica a e encontra os  proceso que tem  o nome do cliente informado pelo  usuario     	
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
	}while(op!=0); // sair  de  laço  de  consultas
	}
	void editar(Dados**inicio)
	{
	
	char foro[50],adv[50],clien[50]; // vetores de strings  para  edição 
	int  op , n;                    // variaveis  para o menu e enconta o processo por seu numero 
	Dados*aux;                      // ponteiro auxiliar para  realiza a edição   
	aux=(*inicio);
	
	 if(aux==NULL)  // verificar se a lista  ta vazia  se estive vaia exibir a mensagem a  seguir
	{
		printf("\n \t NAO HA  PROCESSOS \n");
	    system("pause");
		system ("cls");	
	}
	else // caso a lista  nãoa esteja  vazia vai solicitara ao usuario  o numero do processo  que ele  que editar
	{	
	system (" cls");
	printf("\n\t **************************************\n");
	printf("\n \t INFORME  O NUMERO  DO PROCESSO \n");
	 scanf("%i", &n);
	
	 	while( aux!=NULL && aux->num !=n) // lalo vaia acontecer para encontara  o processo que vaia ser editado
	  {
	
	   aux=aux->prox;
	  }
	
	 if (aux==NULL) // se chegara no fim  da lista  e  nãoa achar o processo  vai  exibir a mensagem a seguir
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
	   }while(op!=1 && op!=2 && op!=3 && op!=0); //  o sistema  só  vaia seguir se usuario escolher uma da opções do menu 
	   
	    if(op==1) /* sendo essa opçãoa o sistema vai solicitar o novo nome  forum e vai acontcer a substuição na lista  
		         o nome do  forum pelo que usuario informar*/
	     {
	      system("cls");
	      printf("\n \t  INFOME O NOME DO  NOVO  FORUM\n");
	      fflush(stdin);
	      gets(foro);
	      strcpy (aux->forum,foro);	
		   	    
	      }
	   else if(op==2) /* sendo essa opçãoa o sistema vai solicitar o novo nome advogado  e vai acontcer a substuição na lista  
		         o nome do  advogado pelo que usuario informar*/
	     {
	      system("cls");
	      printf("\n \t  INFOME O NOME DO  NOVO  ADVOGADO\n");
	      fflush(stdin);
	      gets(adv);
	      strcpy(aux->advog,adv);	
	    	
	    }
	    else if( op==3) /* sendo essa opçãoa o sistema vai solicitar o novo nome  cliente e vai acontcer a substuição na lista  
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
 void excluir (Dados**inicio) // funçãoa para excluir 
 {
 	Dados *aux,*aux2; // ponteiro auxiliar  para  ajudar na exclusão 
 	int n;            // varivel  para  numero dos processos 
 	
 	aux=(*inicio);
 	
 	if (aux== NULL) // vaia verificar se  a lista ta vazia  se tiver  vai exibir a mensagem a seguir
 	{
 		system("cls");
 		printf("\n \t NAO HA PROCESSO PARA SER REMOVIDO \n");
 		system("pause");
 		system("cls");
 	}
 	else // caso a lista não esteja  vazia  o sistema  vaia solicitar  o numero do processo a ser excluido  
 	{	
	   system (" cls");
	   printf("\n\t **************************************\n");
	   printf("\n \t INFORME  O NUMERO  DO PROCESSO \n");
	   scanf("%d", & n);
	
	  while( aux!=NULL && aux->num !=n) // esse  laço vai procura  o  processo com o numero  que  usuario informou
	  {
	   aux=aux->prox;
	  }
	  if (aux==NULL) // vai verificara se  chegou no fim da  lista e nãoa encontrou  o processo se  isso acontcer vaia exibir  a mensagem a seguir 
	  {
	   system ("cls");
	   printf(" \n \t  PROCESSO NAO ENCONTRADO \n ");
	   system ("pause");
	   system ("cls");
	   }
 	  else // caso a  encontre o processo com o numero informado pelo usuario  o sistema vai procura o pronteiro que  a ponta para ele  
	   {
	   	aux2=(*inicio);
	   	
 	    while(aux2->prox!=aux)// laço para encontar o ponteiro que aponta para  oprocesso com o numero  que o usuario informou
	    { 
	    aux2=aux2->prox;
	    }
	   
	    aux2->prox=aux->prox; /* atraves desse procedimento o sistema vai passar o ponteiro que aponta  para o processo 
		com o numro informado pelo  usuario para o proximo processo */ 
	    free(aux); // com isso  o sistema vai excluir 

 	  }
 				
 	}
 }
 void exibir(Dados*inicio) // função para exibir os processo  pelo gosto do usuario 
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
 	else // caso a lista  nã esteja  vazia  o sistema vaia solicitar  qual é a ordem de exibição que o usuario que 
	 {
	  do{
	 	system("cls");
	 	printf("\n \t********************************************\n");
	 	printf("\n \t OS PROCESSOS SERAO  EXIBIDOS  EM QUAL ORDEM ? \n");
	 	printf("\n \t 1-DECRESECNTE\n");
	 	printf("\n \t 2-CESCENTE\n");
	 	printf("\n \t*********************************************\n");
	 	scanf("%i",&op);
	   }while(op!=1 && op!=2); // enquanto o usuario nãoa informa o dos numero do menu  vaia acontcer esse laço
	    
	 	if(op==1)// sendo essa a escolha do usuario  o sistema vaia exibir os processo  em ordem decresente
	 	{
           system("cls");
	 		while(aux!=NULL)// laço pra exibir os porcesso
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
		    nesse parte para exibir essa  nova lista que está com os processo em ordem crescente */ 
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
void backup (Dados*inicio) // função para guarda  os dados  que fora inferido no sistema  
{
	Dados*aux; // ponteiro  auxiliar 
	FILE*arq; // ponteiro para arquivo 
	aux=inicio;
	arq=fopen("PROCESSOS.txt","a+"); // criara um arquivo txt
	
   fprintf(arq,"PROCESSO \n");// uma mensagem  no arquivo 
   
   while(aux!=NULL) // laço para escrever os dados  da lista no arquivo 
   {
	fprintf(arq,"\n PROCESSO DE NUMERO: %d",aux->num);
	fprintf(arq,"\n FORUM: %s",aux->forum);
	fprintf(arq,"\n Dr(a): %s",aux->advog);
	fprintf(arq,"\n CLIENTE: %s\n", aux->cliente);
	
	aux=aux->prox;
	
   }
	fclose(arq);// feichar  o arquivo 
}
