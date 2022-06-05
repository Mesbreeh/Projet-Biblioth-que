#include"struct.h"
#include"borrow.h"
void Borrow (User *s1, Borrowed *l1)
{
	char none[1];
	char whatbook[TAILLE];
	char book[TAILLE];
	int existe=0;
	int dispo=0;
	char prisoupas[TAILLE];
	
	char verif[TAILLE];
	char log[TAILLE], mdp[TAILLE], role[TAILLE], enabled[TAILLE], nbrEmprunt[TAILLE];
	
	int Nbligne;
	
	
	time_t now = time(NULL);
	struct tm *cur_time = localtime(&now);
	FILE *fub = fopen ("user.txt", "r");
	if ( fub==NULL){
		printf(" Erreur fopen fub borrow \n");
		exit (1);
	}
	 while (fgets(verif,TAILLE,fub)!=NULL)
	 {
	 
    		char * token1 = strtok(verif,"#");//recover the title of a book 
    		strcpy(log,token1);
    		token1=strtok(NULL,"#");//recover the loggin
    		strcpy(mdp,token1);
    		token1=strtok(NULL,"#");//recover the password
    		strcpy(role,token1);
    		token1=strtok(NULL,"#");//recover enabled
    		strcpy(enabled,token1);
    		token1=strtok(NULL,"#");//recover nbrEmprunt
    		strcpy(nbrEmprunt,token1);
  		
    		if(strcmp(log,s1->login)==0)
			{
				int nn=strlen(nbrEmprunt);
				nbrEmprunt[nn-1]='\0';
    			if (strcmp(role,"1")==0 && strcmp(nbrEmprunt,"5")==0)
				{
    				printf("\n You can not borrow new books, make sure to return the borrowed ones\n");
    				exit(1);
    			}
    			else
    			{
    				if(strcmp(role,"2")==0 && strcmp(nbrEmprunt,"3")==0)
					{
    					printf("\n You can not borrow new books, make sure to return the borrowed ones\n");
    					exit(1);
    				}
    				else
    				{
    					printf("\nYou actually can borrow some more books\n");
					}
				}
       			Nbligne++;
       			break;
    		}
    }
    fclose(fub);
    
    
    
     //recover the list of books's titles and assign them to the array T T is a string array : titles array)
    char T[NBBOOKSMAX][TAILLEMAXSTR];
	FILE *fbob = fopen ("book.txt", "r");
	if ( fbob==NULL)
	{                                         	                 
        printf(" Erreur fopen book borrow  \n");
        exit (1);
	}
	int i=0;
	while (fgets(book,TAILLE,fbob)!=NULL) //recover lines one by one
	{
		char * token1 = strtok (book,"#"); //recover,in token1, the title of a book
		//printf("***%s***\n",token1);
		strcpy(T[i],token1);
		//printf("%s\n",T[i]);
		i++;
	}
	//at the end of while,the variable i will contain the number of effectif books numbre of elements used in T)
   	fclose(fbob);
	
	selectSorting(T,i);
    printf("Catalogue des livres de la biblio (titres)");
   	for(int j=0;j<i;j++)
   	{
	   printf("%s\n",T[j]);
	}    
	
	
	
	//choose the book and verify if he exist in book.txt and then verify if he's available in borrow.txt
	//verify if the book exist
	gets(none);
	printf("wich book do you want to borrow ?\n");
	gets(whatbook);
	
	FILE *fbob2 = fopen ("book.txt", "r");
	
	if (fbob2==NULL)
	{                                         	                 
        printf(" Erreur fopen book borrow  \n");
        exit (1);
	}
	
	while (fgets(book,TAILLE,fbob2)!=NULL)
	{
		char * token1 = strtok (book,"#");
		    		
		if (strcmp(book,whatbook)==0)
		{//compair the title and whatbook
			existe=1;
			break;
		}
	}
	
	if(existe==1)
	{
		printf("\nLe livre existe mais verifions sa disponibilité...\n");
		fclose(fbob2);
   	}
	else
	{
		printf("\nThere is no book with that title...\n");
		fclose(fbob2);
		exit(1);
   	}
	
	//verify if the bok is available in borrow.txt
   	FILE *fborbor = fopen ("borrow.txt", "r");
	if ( fborbor==NULL){                                         	                 
        printf(" Erreur fopen borrow fbor1 \n");
        exit (1);
	}
	
	while (fgets(prisoupas,TAILLE,fborbor)!=NULL){
		char * token2 = strtok (prisoupas,"#");
		    		
		if (strcmp(prisoupas,whatbook)==0){
			dispo=1;
			break;
		}
	}
	
	if(dispo==0){
		printf("\nBook available! \n");
		fclose(fborbor);
   	}
	else{
		printf("\nSomeone borrowed the book before you ^^\n");
		fclose(fborbor);
		exit(1);
   	}
		
	
	
	//insert a line containing the data of the borrowing operation in borrow.txt
///////////////////////////////////////////////////////////////////////////////////////////      	
      	//add book+user+h+min in the file borrow.txt
       	FILE *fborrowb2 = fopen ("borrow.txt", "a");
    	if ( fborrowb2==NULL)
		{                                         	                 
            printf(" Erreur fopen borrow fborrow \n");
            exit (1);
    	}
    	
    	if (strcmp(role,"1")==0 )
		{
    	l1->heurpri = cur_time->tm_hour;
		l1->heurend = cur_time->tm_hour; 
		l1->minpri = cur_time->tm_min;
		l1->minrend = cur_time->tm_min+3;
		}
		else
		{
    	l1->heurpri=cur_time->tm_hour;
		l1->heurend=cur_time->tm_hour; 
		l1->minpri = cur_time->tm_min;
		l1->minrend = cur_time->tm_min+2;
		}
       	fprintf(fborrowb2, "%s#%s#%d#%d\n", whatbook, s1->login, l1->heurend, l1->minrend);
       	fclose(fborrowb2);
       	
       	
       	
       	
	//modify the nbremprunt in user.txt   
     
   FILE *fcopyUser = fopen ("copieUser.txt", "w");
	if (fcopyUser==NULL){                                         	                 
        printf(" Erreur fopen ftempub borrow \n");
        exit (1);
	}
	
	FILE *ff = fopen ("user.txt", "r");
	if (ff==NULL){                                         	                 
        printf(" Erreur fopen ff borrow \n");
        exit (1);
	}
	
	char row[TAILLE];
	char LOGIN[TAILLE],MDP[TAILLE],ROLE[TAILLE],ENABLED[TAILLE],NBLV[TAILLE];
	while (fgets(row,TAILLE,ff)!=NULL)
	{
		char * token2 = strtok(row,"#");//recover the title of a book
		strcpy(LOGIN,token2);
		token2=strtok(NULL,"#");
		strcpy(MDP,token2);
		token2=strtok(NULL,"#");
		strcpy(ROLE,token2);    					
		token2=strtok(NULL,"#");
		strcpy(ENABLED,token2);
		token2=strtok(NULL,"#");
		strcpy(NBLV,token2);
		if (strcmp(LOGIN,s1->login)==0)
		{
			int x=strlen(NBLV);
			NBLV[x-1]='\0';
			int newNumberBooks;
			newNumberBooks=atoi(NBLV);
			newNumberBooks++;
			fprintf(fcopyUser,"%s#%s#%s#%s#%d\n",LOGIN,MDP,ROLE,ENABLED,newNumberBooks);
		}
		else
		{
			fprintf(fcopyUser,"%s#%s#%s#%s#%s",LOGIN,MDP,ROLE,ENABLED,NBLV);
		}
	}
	fclose(fcopyUser);
	fclose(ff);
	remove("user.txt"); //delete the file
	int result = rename("copieUser.txt", "user.txt");

}
