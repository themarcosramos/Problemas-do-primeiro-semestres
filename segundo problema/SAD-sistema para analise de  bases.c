	// sistema para  analise de bases
	
	/*******************************************************************************
	Autor: MARCOS DE JESUS RAMOS 
	Componente Curricular: Algoritmos I
	Concluido em: 04/11/2014
	Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
	trecho de código de outro colega ou de outro autor, tais como provindos de livros e
	apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
	de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
	do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
	******************************************************************************************/
	
	# include <stdio.h>
	#include <stdlib.h>
	
	void ler ( char fitas [][15], char complementares [][15],int A[20],int T[20],int G[20],int C[20],int a[20],int t[20],int g[20],int c[20]);
	void quantidade(int A[20],int T[20],int G[20],int C[20],int a[20],int t[20],int g[20],int c[20]);
	void propensao (char complementar [][15]);
	void doencas(char complementares [][15], int peso[20], int id[20]);
	void mostra ( int peso [20],int  id[20]);
	void complementar ( char complementar [][15] );
	void produziraq (int id[20], char fitas[][11] );
		
		int main()
		    {
			char fitas [20][15],complementares [20][15]; // matriz  das fitas  e  das  complementares 
			int A[20],T[20],G[20],C[20], peso[20];      // vetores  correspondente as fitas principais e calcular o peso 
			int a[20],t[20],g[20],c[20],i, id[20]; // vetores correspondente as fitas  complementares , mais  a variavel i  para o loop de zera a vetores 
			                                         //  veotes peso é para o peso das fitas e  id para calculara o id .
		     int op ; // variavel para  o menu
			   
		     	i=0;
		           // loop a  segui vai zera as matrizes
		        	while (i<20)
		        	{
			        	A[i]=0, a[i]=0;
			        	T[i]=0, t[i]=0;
			        	G[i]=0, g[i]=0;
			        	C[i]=0, c[i]=0;
		                 peso[i]=0;
				      i++;
			        }
		
			    printf("\n##########################################################################\n");
			                  
			                           printf("\n \t \a S.A.D.  sistema  para anlise  de  DNA.\n");
			                  
		    	printf("\n###########################################################################\n");
		
		        ler	 (fitas , complementares, A,T,G,C,a,t,c,g ); // vai chamar primeira função 
		         system ( " pause ");
		         system (" cls");
		         
		         // vai aprecer  um menu com as opções que  o usuaria vai escolher  e sistema vai fazer
		        do{
		        	printf("==================================================================");
		        	printf("\n \a escolha  uma  opcao\n");
		        	printf(" opcao 1 mostra quantidade\n");
		        	printf(" opcao 2 mostra propensao a ativadades\n");
		        	printf(" opcao 3 mostra propensao a  doenças que cada fita pode ter\n");
		        	printf(" opcao 4 mostra o maior e o menor  id \n");
		        	printf(" opcao 5 mostra a fitas complementares e ciar arquivos txt \n");
		        	printf(" opcao 0 sai do sistema e  fechar\n");
		        	printf("==================================================================\n");
		        	scanf( " %i", & op);
		        	printf("\n===============================================================");
		        	if( op== 1)
					{
		        		quantidade(A, T, G, C, a, t, g,c);
		        		system (" cls");
		        	}
		        	
		        	else if(op == 2)
					{
		        		
		        	 propensao ( complementares );	
		        	 system (" cls");
		        	}
		        	
		        	else if ( op==3)
		        	{
		        	 doencas( complementares ,  peso,id);	
		        	 system (" cls");
		        	}	
		        	else if (op ==4)
		        	{
		        	 mostra ( peso ,  id);	
		        	 system (" cls");		
		            }
		        	else if (op ==5) 
					{
					 complementar ( complementares);
		              produziraq (id,fitas); 
		              system(" pause");
		              system (" cls") ;
		        	}
		        }    while ( op!=0) ; 
		                    
		         printf("\n \a \t obrigado pelo preferencia! \n");
		         
		    return(0);
			}
		
		   void ler ( char fitas [][15], char complementares [][15],int A[20],int T[20],int G[20],int C[20],int a[20],int t[20],int g[20],int c[20])
		    {
		    // essa função vai ler o aquivo txt.
		     	int i,j;  //  essa  variaveis é para oloops 
		
			    FILE *arq; //  pondetiro  para o arquivo 
		
			    arq = fopen("Dna.txt","r");
		
			    if(arq == NULL)  //  se o arquivo não ser encontrado  vai  acontecer  isso 
		    	{
			    	printf(" Erro -  arquivo  na  encontrado ");
			    	getchar();
		            exit(1);
		     	}
		        else
		        {    //  aquivo sendo encontrado  vai acontcer o procedimento a segui
		
		        for (i=0;i<20;i++)
		            {
		    	    	fscanf (arq,"%s\n",fitas[i]);
		    	    	fitas[i][11]='\0';
		            }
		           printf (" \n**************************************************\n");
		           printf("\n \a \t Bases fornecidas pelo o usuarios\n");
		           printf ("\n****************************************************\n");
		
				for(i=0;i<20;i++)  //  vai aparecer na tela as fitas  lidas
				       {
						printf("%s\n",fitas[i]);
			        	}
		                getchar( );
		
		       	for (i=0;i<20;i++) // vai encher a  matriz complementar  
		            	{
		    	        	for(j=0;j<11;j++)
		    	    	     {
		    	            	if (fitas[i][j] == 'A' || fitas[i][j]== 'a' )
				        	     {
		                          complementares[i][j] = 'T';
		                          A[i]++;
		                          t[i]++;
		                         }
		                     else if (fitas[i][j] == 'T'|| fitas [i][j]== 't' )
						        {
		                         complementares [i][j] = 'A';
		                          T[i]++;
				        	      a[i]++;
		                        }
		                     else if (fitas [i][j] == 'G'|| fitas[i][j]=='g')
						         {
		                          complementares[i][j] = 'C';
		                           G [i]++;
				        	       c[i]++;
		                         }
		                      else if (fitas[i][j] == 'C'|| fitas[i][j]=='c' )
						         {
		                          complementares [i][j] = 'G';
		                          C[i]++;
				        	      g[i]++;
		                         }
		    	    	    }
		    	    	    complementares[i][10]='\0';
		            	}
		         	fclose(arq); //  vai fechar  o aquivo que foi lido 
		        }
		    }
		 	void quantidade(int A[20],int T[20],int G[20],int C[20],int a[20],int t[20],int g[20],int c[20])
		 	// essa  função vai  vai fazer o claculos  sobre as fitas  e printa na tela 
		 	{
		 	     	float pocA[20], pocT[20],pocG[20], pocC[20];  // variaveis  para a porcentagem da bases 
		
		 		    int i, TotA[20],TotT[20],TotG[20],TotC[20];   // variaveis   para  o  total das bases
		
		 		     for (i=0;i<20;i++) // loop  para  calcular o total da  das bases 
		 		     {
		 		        TotA[i]= A[i]+a[i];
		 			    TotT[i]= T[i]+t[i];
		 			    TotG[i]= G[i]+g[i];
					    TotC[i]= C[i]+c[i];
		 		      }
		
		         printf("***************************************************************** \n");
		 		 printf(" \t VALOR ABSOLUTO DAS  FITAS \n ");
		         printf("******************************************************************\n");
		
		 		     for(i=0;i<20;i++)  // vai exibir o total da  bases 
		 	       	  {
		 			      printf("\n%i - FITAS-->A %i ",i+1,TotA[i]);
		 		          printf("\n%i - FITAS-->T %i ",i+1,TotT[i]);
					      printf("\n%i - FITAS-->G %i ",i+1,TotG[i]);
					      printf("\n%i - FITAS-->C %i ",i+1,TotC[i]);
					      printf(" \n");
		 		       }
		                  system ( " pause");
					      system ( " cls");
		
				    for(i=0;i<20;i++)  //  loop  para calcular a pocentagem  das bases
						{
		 		         pocA[i]= (float)TotA[i]*5.0;
		 		         pocT[i]= (float)TotT[i]*5.0;
		 		         pocG[i]= (float)TotG[i]*5.0;
		 		         pocC[i]= (float)TotC[i]*5.0;
						 
						 }
						 
		            printf("\n*************************************************************\n");
		 	    	printf("\n \t POCENTAGEM DAS FITAS \n");
		            printf("\n**************************************************************\n");
		
		 		       for(i=0;i<20;i++) //  loop para exibir as  pocentagem 
		 	           {
		                printf("\n=================================================\n");
		 		       	printf(" \nFITAS-->A %.2f%% ",pocA[i]);
		 		        printf(" \nFITAS-->T %.2f%% ",pocT[i]);
					    printf(" \nFITAS-->G %.2f%%",pocG[i]);
					    printf( "\nFITAS-->C %.2f%%",pocC[i]);
					    printf("\n==================================================\n");
					    printf(" \n");
		
		 	         	}
		                system ( " pause");
					    system ( " cls");
		 	}
		   void propensao (char complementar [][15])
		   { // essa função vai   clacular se  a pessas tem propensão artistica ou esportivas 
		
		   		int qtdg[20],qtdc[20], qtda[20],qtdt[20], i,j; // vetores  locais pata clacular a quantidade  das basese 
		   		                                              // i e j  são variaveis auxiliar para o loop dessa função 
		
		   		for(i=0;i<20;i++) // zera os vetores 
		   		{
		   			qtdg[i]=0;
		   			qtdc[i]=0;
		   			qtda[i]=0;
		   			qtdt[i]=0;	
		       	}
		
		   	    for(i=0;i<20;i++)
		   	     {
		        	for(j=0;j<11;j++) // vai aumentando em 1 nos vetores qtd de base que  encontramos em cada a respectivas fitas .
		   	 	    {
		   	 	    	 if(complementar[i][j]=='G')
		   	 		    {
		   	 			    qtdg[i]++;
		   	 			    qtdc[i]++;
		   	 	     	}
		   	 	    	else if(complementar[i][j]=='C')
				     	{
		   	 	        	qtdc[i]++;
		   	 	        	qtdg[i]++;
				    	}
		   	 	    	else if(complementar[i][j]=='A')
					    {
		   	 		    	qtda[i]++;
		   	 			   qtdt[i]++;
		
		    	    	}
		    	    	else if(complementar[i][j]=='t')
		    	    	{
		    			  qtdt[i]++;
		    			  qtda[i]++;
		    	    	}
		    	    	
		   	 	      }
		   	        }
		   	    for(i=0;i<20;i++) // loop  a segui vai  avalia e determina  as  propensãoes de cada  fita 
		   	          {
		   	 	         if(qtdg[i] + qtdc[i]>10)
				        	{
					    	printf(" A %i fita ",i+1);
					    	printf("\n tem propensao artistica\n");
		   	 	            }
		   	 		      else if(qtdg[i]+qtdc[i]== qtda[i]+qtdt[i])
		   	 		        {
		   	 		    	    printf("\n A %i fita ", i+1);
		   	 			        printf("\n impossivel  determina  alguma coisa\n ");
		   	                }
		   	             else if ( qtda[i] + qtdt[i]>10) 
		   	 		         {
		   	 		        	printf("\n A %i fita",i+1);
		   	 		        	printf("\n propensao esportivas\n");
					         }  
				     	 }     
		               system("pause");
		               system ("cls");
	      }
		void doencas(char complementares [][15], int peso[20], int id[20])
		{   // essa  função  vai  verifica  qual  doença cada  fica tem propensão a ter
		
		    int i, j, qtd=0, soma=0; /*as variaveis qtd  vai aumenta a cada guania  ou citosina a se encontrada 
			                          e soma é um variavel auxiliar apara  calculara o id */
			 
		 // os loops a segui vai sevir para cacular o id  das  fitas 
		    for(i=0;i<20;i++)
		    {
		        for(j=0;j<11;j++)
		        {
		
		        if (complementares[i][j]== 'A')
		         {
		            soma=soma+3;
		         }
		        else if ( complementares[i][j]== 'T')
		         {
		             soma=soma+3;
		         }  
		        else if ( complementares[i][j]== 'G')
		         {
		           soma= soma+7;
		            qtd++;
		         }  
		        else if ( complementares[i][j]=='C')
		          {
		             soma=soma+7;
		            qtd++;
		          }
		        }
		        id[i] = soma + qtd;
		        soma=0;
		      }
		    // vai printar  na tela  quais doença cada fita  te propensão
		     for(i=0;i<20;i++)
		     {
		     	 if(id[i]<50)
		            printf("\n%s tem propensao a doencas cardiacas\n.",complementares[i]);
		        if(id[i]>50)
		            printf("\n%s tem propensao a doencas respiratorios.\n",complementares[i]);
		            else
		            {
		               printf("\n %s nao se pode determinar nada.\n", complementares[i]);
		            }
		     }
		      system("pause");
		      system ("cls");
		}
		void mostra ( int peso [20],int  id[20])
		{
		    int maior, i, menor;  // variaveis  para maior  indice e menor indice  e o i para o loops
		     maior = id[0];
		      for(i=0;i<20;i++)
		      {
		          if( id[i]>maior) // vai encontarar  o meiores  e printando na tela 
		          {
		             maior = id[i];
		             printf( "\n A fita %i tem o maior id " ,i+1);
		          }
		      }
		       menor = id[0];
		       
		      for(i=0;i<20;i++) // vai encontara  o menores  e printando 
		        {
		         if ( id[i]<menor)
		            {
		                menor=id[i];
		                printf( "\n A fita %i tem o menor id ",i+1);
		            }
		        }
		        printf("\n");
		       system ("pause");
		       system("cls");
		      }
		void complementar ( char complementares [][15] )
		//  essa função vai printa as finata complementares 
		{
		int i;
		
		 printf("\n******************************************************************\n");
		 printf("\n \t  FITAS COMPLEMENTARES \n");
		 printf("*******************************************************************\n");
		 
		 for(i=0;i<20;i++) // loops para printa as as fitas complementares 
		 {
		 		puts (complementares[i]);
		 	    printf("\n");
		 }  
		}
		void produziraq (int id[20], char fitas[20][11] )
		// essa  função  vai  riara o arquivos txt com o indices 
		{
		int  i;
		
		FILE*card; //  ponteiro para  o  aquivo  para as fitas   quem tem propensão a  donças  cardiacas 
		FILE*ind;  //  ponteiros para o aquivo para as fitas que não tem com determina qual propensão de doenças ela  tem
		FILE*rep;  // ponteiro para  o  aquivo  para as fitas   quem tem  propensão a donças  respiratoria
		card= fopen(" cardiaco.txt","w"); // vai criar um  arquivo e vai escrever ne  sá a fitas que tem  propensão a doenças cardiaca 
		for(i=0;i<20;i++)
		  {
	    	if(id[i]<50)
	    	{
			 fprintf ( card,"\n%i-->", id[i]);
			 fprintf(card,"\%s\n", fitas[i]);
	         }
	    	}
		fclose(card); // vai  fechar esse aquivo 
		printf("\n arquivo com as fitas e seu id  que tem propensao a ter doenças cardiaca foi criado\n ");
		
		rep= fopen(" respiratoria.txt","w"); // vai criar um  arquivo e vai escrever ne  sá a fitas que tem  propensão a doenças respiratoria 
		for(i=0;i<20;i++)
	    	{
		     if(id[i]>50)
	        	{
			     fprintf (rep,"\n%i-->", id[i]);
			     fprintf(rep,"%s\n", fitas[i]);
		        } 	
		   }
		fclose(rep); // vai fechar o aquivo 
		printf("\n arquivo com as fitas e seu id que tem propensao a ter doenças respiratoria foi criado \n");
	
		ind= fopen(" indeterminado.txt","w"); //vai criar um  arquivo e vai escrever ne  sá a fitas que é impossivel determina que propensão tem 
		
		 for(i=0;i<20;i++)
		  {  
		    if(id[i]==50)
		    {
		    	fprintf (ind,"\n%i-->", id[i]);
			    fprintf(ind,"%s\n", fitas[i]);
		    }
		  }   
		fclose(ind); // vai  fechar o arquivo 
		printf(" \n arquivo com as fitas e seu id que tem que nao pode determinar qual é a propensao foi criado \n ");
		printf("\n");
		printf("a verifique na pasta onte está o aquivo DNA e sistem se nao há 3 novos arquivos\n ")  ;  
	    system (" pause");	 
		}
