#include"struct.h"
#include"add.h"
#include"purge.h"
#include"charg.h"
void Add (Books *b1, User *s1){//function add a book

	Charg();
	
	char none[1];//fixe a bug
	int c;	
	int *c2=&c; //var confirmation add
	char book[TAILLE];
	int existe =0; //1 if exist otherwise 0
	char recup[TAILLE];
	char login[TAILLE];
	
	FILE *fa = fopen ("user.txt", "r");
		int actif=0; //we suppose that the user is active
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
				printf("\nYou are a teacher\n");
				break;
			}
			else
			{
				printf("\nYou do not have the access to this feature\n");
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
	printf("\nEnter the title : \n");		
	gets(b1->title);
	
	while (fgets(book,TAILLE,fb)!=NULL){//read the file
    		char * token = strtok (book,"#");
    		    		
    		if (strcmp(book,b1->title)==0){//comparison 
    			existe=1;
    			break;
    		}
    	}
    	if(existe==0){
    		printf("\n Oh a NEW BOOK !\n");
    		fclose(fb);
    	}
    	else{
    		printf("\n Already exist...\n");
    		fclose(fb);
    		exit(1);
       	}
       	
       	FILE *fb2 = fopen ("book.txt", "a"); 
    	if ( fb2==NULL){                                         	
     	  	printf(" Erreur fopen add book 2 \n");
       		exit (1);
    	}
	
	printf("\nEnter the author's name : \n ");
	gets(b1->author);
	
	printf("\nEnter his identification number : \n");
	scanf("%d", b1->num);
	
	while( *(b1->category) !=1 && *(b1->category) !=2 && *(b1->category) !=3 && *(b1->category) !=4){
		printf("\nEnter his category : \n ");
		printf(" 1. Sciences \n");
		printf(" 2. Literature  \n");
		printf(" 3. Law  \n");
		printf(" 4. Other \n");
		scanf("%d", b1->category);
		purge();
		
	}
	
	printf(" \n Verification : \n");
	printf("\nTitre : %s \n Author : %s \n Num : %d \n Category : %d\n", b1->title, b1->author, *b1->num, *b1->category);
	
	while( *c2 != 1 && *c2 != 2) {	//confirmation 
		printf("\nWould you like to add a book ? 1.yes ou 2.no\n");
		scanf("%d", c2);
		purge();
	}
	
	if( *c2==1){
		fprintf(fb2, "%s#%s#%d#%d \n", b1->title, b1->author, *b1->num, *b1->category);
		printf(" Book added! \n");
	}
	else 
		Add(b1,s1);
	
	fclose(fb2);
	Charg();
}
