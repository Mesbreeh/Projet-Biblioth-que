#include"struct.h"
#include"return.h"
void Return (User *s1){//fonction permettant de rendre un livre

	char none[1];//pallier a un pb de gets
	char rend[TAILLE];
	char ligne[TAILLE];
	int existe=0;//1=existe 0=inexistant
	int heuc; //heure courante
	int minc; //min courante


    gets(none);
    printf("\nQuel livre voulez-vous rendre ?\n");
    gets(rend);
 	FILE *fb = fopen ("borrow.txt", "r");//ouvre fichier book
	if ( fb==NULL)
	{                                         	                 
        printf(" Erreur fopen fb return \n");
        exit (1);
	}
	char title[TAILLE],lg[TAILLE];
	int nb=0; //variable pour stocker le n° de la ligne contenant le livre et le login objets de DELETE
	char hh[TAILLE],mm[TAILLE];
	int h,m;
	time_t now = time(NULL);//pour l'heure courante
	struct tm *cur_time = localtime(&now); //pour l'heure courante
	heuc=cur_time->tm_hour;
   	minc=cur_time->tm_min;
   	
   	int NB=1;
   	
	while (fgets(ligne,TAILLE,fb)!=NULL)   //recuperer, à chaque iteration, une ligne du fichier borrow.txt (dans la variable liv)
	{
	    //verif si le livre a ete empruntÃ©
		char * token1 = strtok(ligne,"#");//recuperer le titre d'un livre
		strcpy(title,token1);
		token1=strtok(NULL,"#");//recuperer le login qui l'a emprunté
		strcpy(lg,token1);
		token1=strtok(NULL,"#");//recuperer l'heure
		strcpy(hh,token1);
		token1=strtok(NULL,"#");//recuperer les minutes
		strcpy(mm,token1);
		int n=strlen(mm);
		mm[n-1]='\0';
		h=atoi(hh);
		m=atoi(mm);
		if (strcmp(title,rend)==0 && strcmp(lg,s1->login)==0)
		{
			existe=1;
			//instructions pour modifier le fichier borrow.txt car c'est une operation à faire que ça soit les regles sont respectées ou non
			printf("Le retour du livre en cours du traitement...\n");
			rewind(fb);//se mettre au debut du fichier borrow.txt
			FILE *fcopy=fopen("temporaire.txt","w");
			int nb=1;
		   	while (fgets(ligne,TAILLE,fb)!=NULL)
			{
				if(nb!=NB)
				{
					fprintf(fcopy,"%s",ligne);
				}
				nb++;
			}    		
			fclose(fb);
			fclose(fcopy);
			remove("borrow.txt"); //supprimer le fichier
			int result = rename("temporaire.txt", "borrow.txt");			
			printf("le retour du livre %s a ete bien effectue\n");
			printf("Maintenant, la verification du respect des regles de la biblio\n");
			
			
	    	if(heuc==h && minc<=m) //si l'user respecte les regles
			{
				printf("vous avez respecte les regles\n");
				printf("vous seriez le(a) bienvenu(e) à la biblio\n");
				//instructions pour decrementer le nombre de livres empruntés par l'emprunteur connecté (reduire ce nombre de 1 )
	       		FILE *fcopyUser = fopen("copieUSer.txt", "w");//ouvre fichier
	       		FILE *ff=fopen("user.txt","r");
	    		if (ff==NULL)
				{                                       	                 
	            		printf(" Erreur fopen du file user return \n");
	            		exit(1);
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
					//printf("***TEST*****%s*****%s***%s\n",LOGIN,s1->login,NBLV);
					if (strcmp(LOGIN,s1->login)==0)
					{
						int x=strlen(NBLV);
						NBLV[x-1]='\0';
						int newNumberBooks;
						newNumberBooks=atoi(NBLV);
						newNumberBooks--;
						//itoa(newNumberBooks,NBLV,10);
						
						sprintf(NBLV, "%d", newNumberBooks);
						fprintf(fcopyUser,"%s#%s#%s#%s#%s\n",LOGIN,MDP,ROLE,ENABLED,NBLV);
					}
					else
					{
						fprintf(fcopyUser,"%s#%s#%s#%s#%s",LOGIN,MDP,ROLE,ENABLED,NBLV);
					}
				}
				fclose(fcopyUser);
				fclose(ff);
				remove("user.txt"); //supprimer le fichier
				int result = rename("copieUSer.txt", "user.txt");	
	       	}
	       	else
			//si l'user ne respecte pas les regles
			{
	       		printf("\n Aie aie aie, livre rendu en retard !\n");
	       		FILE *fcopyUser = fopen ("copieUSer.txt", "w");//ouvre fichier
	       		FILE *ff=fopen("user.txt","r");
	    		if (ff==NULL)
				{                                       	                 
	            		printf(" Erreur fopen du file user return \n");
	            		exit(1);
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
						newNumberBooks--;
						
						char r[2]="0";
						
					sprintf(NBLV, "%d", newNumberBooks);
					
					fprintf(fcopyUser,"%s#%s#%s#%s#%d\n",LOGIN,MDP,ROLE,r,newNumberBooks);
					}
					else
					{
					fprintf(fcopyUser,"%s#%s#%s#%s#%s",LOGIN,MDP,ROLE,ENABLED,NBLV);
					}
				}
				fclose(fcopyUser);
				fclose(ff);
				remove("user.txt"); //supprimer le fichier
				int result = rename("copieUSer.txt", "user.txt");	
	      	}
	        break;
		}					
		NB++;
	}

	if(existe==0)
	{
		printf("\nIl n'y a pas de livre emprunte a vous avec ce titre\n");
		fclose(fb);
		exit(1);
   	}
}
