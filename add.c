#include"struct.h"
#include"add.h"
#include"purge.h"
#include"charg.h"
void Add (Books *b1, User *s1){//fonction ajout d'un livre

	Charg();
	
	char none[1];//contrer un bug
	int c;	
	int *c2=&c; //var confirmation ajout
	char book[TAILLE];
	int existe =0; //1 si existe sinon 0
	char recup[TAILLE];
	char login[TAILLE];
	
	FILE *fa = fopen ("user.txt", "r");//ouvre fichier user
		int actif=0; //on suppose que l'utilisateur etudié est inactif
    	if (fa==NULL)
	{                                         	                 
        	printf(" Erreur fopen signin \n");
        	exit (1);
    	}
    	
    	 while (fgets(recup,TAILLE,fa)!=NULL)
	{
		char * token1 = strtok (recup,"#");
		strcpy(login,token1);
    		token1=strtok(NULL,"#");
    		token1=strtok(NULL,"#");
    		strcpy(recup,token1);
    		
    		if (strcmp(login,s1->login)==0)
		{
    			if (strcmp(recup,"1")==0)
			{	
				printf("\nVous êtes professeur\n");
				break;
			}
			else
			{
				printf("\nVous n'avez pas accès a cette fonctionnalité\n");
				exit(1);
			}
		}
	}
    	fclose(fa);	
//////////////////////////////////////////////////////////////////////////////////////////////
   	FILE *fb = fopen ("book.txt", "r"); //ouvre fichier 
    	if ( fb==NULL){                                         	
     	  	printf(" Erreur fopen add book\n");
       		exit (1);
    	}
    	gets(none);
	printf("\nSaisir son Titre : \n");		
	gets(b1->title);
	
	while (fgets(book,TAILLE,fb)!=NULL){//lit le fichier
    		char * token = strtok (book,"#");
    		    		
    		if (strcmp(book,b1->title)==0){//comparaison 
    			existe=1;
    			break;
    		}
    	}
    	if(existe==0){
    		printf(" Oh un nouvel Livre !\n");
    		fclose(fb);
    	}
    	else{
    		printf(" Il existe deja...\n");
    		fclose(fb);
    		exit(1);
       	}
       	
       	FILE *fb2 = fopen ("book.txt", "a"); //ouvre fichier 
    	if ( fb2==NULL){                                         	
     	  	printf(" Erreur fopen add book 2 \n");
       		exit (1);
    	}
	
	printf("\nSaisir le NOM de l'Auteur : \n ");
	gets(b1->author);
	
	printf("\nSaisir son numéro d'identification : \n");
	scanf("%d", b1->num);
	
	while( *(b1->category) !=1 && *(b1->category) !=2 && *(b1->category) !=3 && *(b1->category) !=4){
		printf("\nSaisir sa catégorie : \n ");
		printf(" 1. Sciences \n");
		printf(" 2. Littérature \n");
		printf(" 3. Droit \n");
		printf(" 4. Autres \n");
		scanf("%d", b1->category);
		purge();
		
	}
	
	printf(" \n Verification : \n");
	printf("\nTitre : %s \n Auteur : %s \n Num : %d \n Catégorie : %d\n", b1->title, b1->author, *b1->num, *b1->category);
	
	while( *c2 != 1 && *c2 != 2) {	//confirmation 
		printf("\n Voulez-vous ajouté le livre ? 1.oui ou 2.non\n");
		scanf("%d", c2);
		purge();
	}
	
	if( *c2==1){
		fprintf(fb2, "%s#%s#%d#%d \n", b1->title, b1->author, *b1->num, *b1->category);
		printf(" Livre ajouté ! \n");
	}
	else 
		Add(b1,s1);
	
	fclose(fb2);
	Charg();
}
