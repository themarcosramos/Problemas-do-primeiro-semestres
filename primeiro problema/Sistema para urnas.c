// sistema para as urnas

/*******************************************************************************
Autor: MARCOS DE JESUS RAMOS 
Componente Curricular: Algoritmos I
Concluido em: 29/09/2014
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
******************************************************************************************/

# include<stdio.h>
# include<stdlib.h>

int main ()
{
    int votos;
    int nulos=0;
    int eleitores;
    int brancos=0;
    int maeli_gente_boa=0;
    int lissandra_progresso=0;
    int loula_do_brasil=0;
    int maia_da_ana=0;
    int feminino;
    int masculino;
    int num_total_eleitores;
    int votos_validos;
    float po_de_maeli;
    float po_de_loula;
    float po_de_lissan;
    float po_de_maia;
    float po_de_brancos; 
    float po_de_nulos;
    float po_de_votos_val;
    float po_do_mascu;
    float po_do_femi;
    
    
    
     printf (" \t SEU VOTO %c AQUI \a \n",138); //  mensagem de  pra usuario 

     printf("\n Indique  o n%cmero de eleitores \n",163); //   vai pedir  para o usuario  informa seu cnadidato 
     scanf("%i",&num_total_eleitores);
    
     eleitores = num_total_eleitores;//aqui a variavel passa seu valor pra outra variavel
     
    system ("cls");

     if( eleitores<=0)
     {
         printf(" \t IMPOSSiVEL REALIZA A VOATA%c%cO\a ",128,134);//  se  por acaso o numero de eleitores for menor ou igual a 0 vai aparecer essa mensagem 
     }
    else
    {
        while(eleitores>0)// es é o loop  que  vai fazer com que cada eleitor vote em seu candidado  e  que seu voto seja computado e somando ao seu candidado  
        {

            printf("\t indique o n%cnero de seu candidato \n",163);
            
            printf(" \t Sra Maeli gente boa      -17\n");
            printf(" \t Sr loula do brasil       -22 \n");
            printf(" \t Dra lissandra Progresso  -31 \n");
            printf(" \t Seu Maia da Ana          -38 \n");
            printf(" \t branco                    -0\n");
            printf(" \t nulos qualquer numero fora  os  j%c citados \n",160);

            scanf("%i",& votos);
            
            //   esse vai seo o processo  que vai ocorre  quando o eleitor indicar  quem é o seu  candidado
            
        if( votos==17)
          {
            maeli_gente_boa++;            // se o voto  for 17 vai soma a candidata maeli e diminuir o número de eleitores
            eleitores--;
            system("cls");

           }
            else if ( votos==31)
            {
              lissandra_progresso++;      // se o voto  for 31 vai soma a candidata Lissandra e diminuir o número de eleitores
              eleitores--;
              system("cls");
            }
            else if( votos==22)
            {
                loula_do_brasil++;      // se o voto  for 22  vai soma ao candidato loula  e diminuir o número de eleitores
                eleitores--;
                system("cls");
            }
            else if  (votos==38)
            {
                maia_da_ana++;          // se o voto  for 38 vai soma ao candidato Maia e diminuir o número de eleitores
                masculino++;
                eleitores--;
                system("cls");
            }
            else if ( votos==0)
            {
                brancos++;              // se o voto  for 0 vai soma aos barncos  e diminuir o número de eleitores
                eleitores--;
                system("cls");
            }
            else
            {
                nulos++;
                eleitores--;          // se o voto  for qualquer numero difrente  do já aqui mencionados  via soma a nulos  e diminuir o número de eleitores
                system("cls");
             }
        }
        
        getchar ( );
        
         /* aqui  vai aparecer o  valor que cada candidato obeterve ao termino da votação  */
         
         printf("\n \t votos da candidata  Maeli gente boa :%i",maeli_gente_boa);
         printf("\n \t votos da candidata  Lissandra progresso :%i",lissandra_progresso);
         printf("\n \t votos do candidato  Loula do Brasil :%i",loula_do_brasil);
         printf("\n \t votos do candidato  Maia da ana %i",maia_da_ana);
         printf("\n \t votos Brancos %i",brancos);
         printf("\n \t votos Nulos %i\n",nulos);
         
         
         masculino = loula_do_brasil+maia_da_ana;
         printf("\n \t  votos para o sexo masculino %i\n",masculino);  //  vai  aperecer na tela  o numero de votos do candidatos do sexo masculino 
         
         feminino= maeli_gente_boa+lissandra_progresso;
         printf("\n \t  votos  para o sexo feminino %i\n",feminino );  //   vai  aperecer na tela  o numero de votos do candidatas do sexo femini no 
         
          
         getchar ( );      // esse   comnado é  usado  para  pausar o programa
         system("cls");    // esse comando é usado para limpar a tela 
          
        votos_validos = num_total_eleitores-nulos -brancos; // calculo  para achar votos validos 
          
        printf("\n \t votos validos %i",votos_validos);  // vai aprecer na tela  o número de votos validos 
        
        
		// no bloco a segui   mostra  com  vai ser feito o calculo  e  com  aprecer na tela  o percentual de votos dos candidatos 
		
		// po_de = é a variavel que  segnifica  pocentagem de votos  do candidato 
		       
        po_de_maeli= (float)maeli_gente_boa/ num_total_eleitores*100;
        
        printf("\n  \t pecentual de votos da candidata  maeli gente boa %.2f%%",po_de_maeli);
          
        po_de_loula= (float)loula_do_brasil/num_total_eleitores *100;  
        
        printf("\n  \t votos do candidato Loula do Brasil %.2f%%",po_de_loula);  
    
        po_de_lissan=(float)lissandra_progresso/num_total_eleitores*100; 
        
        printf(" \n \t votos da candidata Lissandra Progresso %.2f%% ",po_de_lissan);
        
        po_de_maia =(float)maia_da_ana/num_total_eleitores*100;
        
        printf(" \n \t votos do candidato  Maia da Ana %.2f%%",po_de_maia);
        
        po_do_mascu=(float)masculino/num_total_eleitores*100;
         
        printf("\n\t pecentual de  votos dos candidatos do sexo masculino %.2f%%",po_do_mascu);
    
        po_do_femi= (float)feminino /num_total_eleitores*100;
       
        printf("\n\t pecentual de votos das candidadas do sexo feminino %.2f%%",po_do_femi);
        
       getchar ( );
       system("cls");
        
        
        // no bloco a segui  demontras o processo condicional que é feito entres as variaveis pra mostra  quem foi o candidadto com mais votos 
        
       if(po_de_maeli>po_de_loula && po_de_maeli>po_de_lissan && po_de_maeli> po_de_maia)
       {
       	printf("\n  Maeli gente boa  foi a candidata com mais votos\n");
       }
       else if(po_de_loula>po_de_maeli && po_de_loula>po_de_lissan && po_de_loula> po_de_maeli) 
        {
        	printf("\n Loula do Brasil  foi o candidato com mais votos \n");
        }
        else if(po_de_lissan>po_de_maeli && po_de_lissan>po_de_maia && po_de_lissan >po_de_loula)
        {
        	printf("\n Lissandra Progresso  foi a  candidata  com mais votos \n");
        }
        else if( po_de_maia>po_de_loula && po_de_maia>po_de_maeli && po_de_maia>po_de_lissan)
        {
        	printf("\n  Maia da Ana  foi o candidato  com mais  votos \n");
        }
        
		 getchar ( );
                system("cls");
         
    
        // já no  bloco a segui  demontras o processo condicional que é feito entres as variaveis pra mostra  quem foi o candidadto com menos votos  
        
       if(po_de_maeli<po_de_loula && po_de_maeli<po_de_lissan && po_de_maeli< po_de_maia)
       {
       		printf("\n \t Maeli gente boa  foi a candidata com menos  votos\n");
       }
        else if( po_de_loula<po_de_maeli&& po_de_loula<po_de_lissan && po_de_loula<po_de_maia)
        {
        	printf("\n\t Loula do Brasil  foi o candidato  com menos  votos\n");
        }
        else if(po_de_lissan<po_de_maeli && po_de_lissan<po_de_loula && po_de_lissan<po_de_maia)
        {
        	printf("\n  \t Lissandra progresso foi a candidata com menos  votos \n");
        	
        }
        else if (po_de_maia<po_de_maeli && po_de_maia<po_de_loula && po_de_maia<po_de_lissan)
        {
        	printf("\n  \t Maia da ana foi o candidato com menos  votos\n");
        }
        
        
        getchar ( );
        system("cls");
        
        /*no  bloco a segui e outra estrutura condicional  que é feita entre  cada variavel  que representa  a pocentagem dos candidados 
	     e  o criterio que é usado apra determina se  tem algum candidato elelito  ou se vai ter segundo turno que  é  para um candidado ser eleito ele  tem que  
		 alcança mais que a maioria  absoluta do  votos  valido 	*/
		 
		 
           if ( po_de_maeli>50)
           {
           	printf(" \t A candidata  Maeli gente boa  esta eleita\n ");
           }
           
           else if ( po_de_lissan>50)
          {
          	printf("\t  A Candidata Lissandra Progresso esta eleita \n");
          }
          
           else if (po_de_maia>50)
		  {
		  	printf(" \t O candidato Seu Maia da  esta eleito \n");
		  }
		  
		   else if( po_de_loula>50)
		  {
		  	printf(" \t O candidato Loula do Brasil esta eleito \n");
		  }
		  
		   else 
		  {
		  	printf  ( "\t vai ter segundo turno \n\n \a");
		  }
		  
        }
        
        printf( "\n \t Obrigado  ate a pr%cxima  elei%c%Co !\n\a ",162,128,134) ;
}
