#include"struct.h"
#include"return.h"
void Return (User *s1){//function to return a book

	char none[1];//overcome a pb in gets
	char rend[TAILLE];
	char ligne[TAILLE];
	int existe=0;//1=exist 0=non-existant
	int heuc; //current hour
	int minc; //current min


    gets(none);
    printf("\nWich book do you want to return ?\n");
    gets(rend);
 	FILE *fb = fopen ("borrow.txt", "r");//open the file book
	if ( fb==NULL)
	{                                         	                 
        printf(" Erreur fopen fb return \n");
        exit (1);
	}
	char title[TAILLE],lg[TAILLE];
	int nb=0; //variable to store the number of line that contain the book and the login objets to DELETE
	char hh[TAILLE],mm[TAILLE];
	int h,m;
	time_t now = time(NULL);//current time
	struct tm *cur_time = localtime(&now); //current time
	heuc=cur_time->tm_hour;
   	minc=cur_time->tm_min;
   	
   	int NB=1;
   	
	while (fgets(ligne,TAILLE,fb)!=NULL)   //recover, at eatch iteration, a line from the file borrow.txt (in variable liv)
	{
	    //verify if the book has been borrowed 
		char * token1 = strtok(ligne,"#");//recover the title of a book
		strcpy(title,token1);
		token1=strtok(NULL,"#");//recover the login who borrowed it
		strcpy(lg,token1);
		token1=strtok(NULL,"#");//recover the hour
		strcpy(hh,token1);
		token1=strtok(NULL,"#");//recover the minutes 
		strcpy(mm,token1);
		int n=strlen(mm);
		mm[n-1]='\0';
		h=atoi(hh);
		m=atoi(mm);
		if (strcmp(title,rend)==0 && strcmp(lg,s1->login)==0)
		{
			existe=1;
			//instructions to modify the file borrow.txt cause its an operation to do for the rules to be respected or not
			printf("Le retour du livre en cours du traitement...\n");
			rewind(fb);//in the start of the file borrow.txt
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
			remove("borrow.txt");  //delete file
			int result = rename("temporaire.txt", "borrow.txt");			
			printf("the book return %s was done well\n");
			printf("Now, let's verify if you respected library's rules\n");
			
			
	    	if(heuc==h && minc<=m)//if the user respects the rules
			{
				printf("\nYou respected the rules\n");
				printf("\nWelcome to the library\n");
				//instructions to decrease the number of the borrowed books by the borrower (decrease by 1 )
	       		FILE *fcopyUser = fopen("copieUSer.txt", "w");
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
				remove("user.txt"); //delete the file
				int result = rename("copieUSer.txt", "user.txt");	
	       	}
	       	else
			//if the user doesn't respect the rules
			{
	       		printf("\n Aie aie aie, livre rendu en retard !\n");
	       		FILE *fcopyUser = fopen ("copieUSer.txt", "w");//open file
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
					char * token2 = strtok(row,"#");//recover the book title
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
				remove("user.txt"); //delete the file
				int result = rename("copieUSer.txt", "user.txt");	
	      	}
	        break;
		}					
		NB++;
	}

	if(existe==0)
	{
		printf("\nYou borrowed no book with this title\n");
		fclose(fb);
		exit(1);
   	}
}
