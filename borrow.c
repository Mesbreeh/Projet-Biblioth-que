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
	 
    		char * token1 = strtok(verif,"#");//recuperer le titre d'un livre
    		strcpy(log,token1);
    		token1=strtok(NULL,"#");//recuperer le login
    		strcpy(mdp,token1);
    		token1=strtok(NULL,"#");//recuperer mdp
    		strcpy(role,token1);
    		token1=strtok(NULL,"#");//recuperer enabled
    		strcpy(enabled,token1);
    		token1=strtok(NULL,"#");//recuperer nbrEmprunt
    		strcpy(nbrEmprunt,token1);
  		
    		if(strcmp(log,s1->login)==0)
			{
				int nn=strlen(nbrEmprunt);
				nbrEmprunt[nn-1]='\0';
    			if (strcmp(role,"1")==0 && strcmp(nbrEmprunt,"5")==0)
				{
    				printf("\n Vous ne pouvez pas emprunter de livre, veuillez rendre un livre\n");
    				exit(1);
    			}
    			else
    			{
    				if(strcmp(role,"2")==0 && strcmp(nbrEmprunt,"3")==0)
					{
    					printf("\n Vous ne pouvez pas emprunter de livre, veuillez rendre un livre\n");
    					exit(1);
    				}
    				else
    				{
    					printf("\nVous pouvez encore emrpunter un livre !\n");
					}
				}
       			Nbligne++;
       			break;
    		}
    }
    fclose(fub);
    
    
    
    //Recuperer la liste des titres des livres et les affecter au tableau T (T est un tableau de chaines : tableau de titres)
    char T[NBBOOKSMAX][TAILLEMAXSTR];
	FILE *fbob = fopen ("book.txt", "r");
	if ( fbob==NULL)
	{                                         	                 
        printf(" Erreur fopen book borrow  \n");
        exit (1);
	}
	int i=0;
	while (fgets(book,TAILLE,fbob)!=NULL) //recuperer ligne par ligne
	{
		char * token1 = strtok (book,"#"); //recuperer, dans token1, le titre d'un livre
		//printf("***%s***\n",token1);
		strcpy(T[i],token1);
		//printf("%s\n",T[i]);
		i++;
	}
	//à la sorie de while, la variable i contiendra le nombre de books effectif (nombre d'elements utilisé dans T)
   	fclose(fbob);
	
	selectSorting(T,i);
    printf("Catalogue des livres de la biblio (titres)");
   	for(int j=0;j<i;j++)
   	{
	   printf("%s\n",T[j]);
	}    
	
	
	
	//saisir le livre et verifier son existance dans book.txt et ensuite sa disponibilité dans borrow.txt
	//recherche si livre existe 
	gets(none);
	printf("Quel livres voulez-vous emrpunter ?\n");
	gets(whatbook);
	
	FILE *fbob2 = fopen ("book.txt", "r");
	//ouvre fichier book
	if (fbob2==NULL)
	{                                         	                 
        printf(" Erreur fopen book borrow  \n");
        exit (1);
	}
	
	while (fgets(book,TAILLE,fbob2)!=NULL)
	{//lit le fichier
		char * token1 = strtok (book,"#");
		    		
		if (strcmp(book,whatbook)==0)
		{//comparaison titre et whatbook
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
		printf("\nIl n'y a pas de livre avec ce titre...\n");
		fclose(fbob2);
		exit(1);
   	}
	
	//verifier la disponibilité du livre dans borrow.txt
   	FILE *fborbor = fopen ("borrow.txt", "r");//ouvre fichier book
	if ( fborbor==NULL){                                         	                 
        printf(" Erreur fopen borrow fbor1 \n");
        exit (1);
	}
	
	while (fgets(prisoupas,TAILLE,fborbor)!=NULL){//lit le fichier
		char * token2 = strtok (prisoupas,"#");
		    		
		if (strcmp(prisoupas,whatbook)==0){//comparaison 
			dispo=1;
			break;
		}
	}
	
	if(dispo==0){
		printf("\nLivre disponible ! \n");
		fclose(fborbor);
   	}
	else{
		printf("\nIl y a deja quelqu'un qui lit ce livre ^^\n");
		fclose(fborbor);
		exit(1);
   	}
		
	
	
	//inserer une ligne contenant les données de l'operation d'emprunt dans borrow.txt
///////////////////////////////////////////////////////////////////////////////////////////      	
      	//ajoute le livre+user+h+min dans le fichier borrow.txt
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
       	
       	
       	
       	
	//modifie le nbremprunt dans user.txt  
     
   FILE *fcopyUser = fopen ("copieUser.txt", "w");//ouvre fichier
	if (fcopyUser==NULL){                                         	                 
        printf(" Erreur fopen ftempub borrow \n");
        exit (1);
	}
	
	FILE *ff = fopen ("user.txt", "r");//ouvre fichier
	if (ff==NULL){                                         	                 
        printf(" Erreur fopen ff borrow \n");
        exit (1);
	}
	
	char row[TAILLE];
	char LOGIN[TAILLE],MDP[TAILLE],ROLE[TAILLE],ENABLED[TAILLE],NBLV[TAILLE];
	while (fgets(row,TAILLE,ff)!=NULL)
	{
		char * token2 = strtok(row,"#");//recuperer le titre d'un livre
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
	remove("user.txt"); //supprimer le fichier
	int result = rename("copieUser.txt", "user.txt");

}
