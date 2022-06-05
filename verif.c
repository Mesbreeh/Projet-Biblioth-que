#include"struct.h"
#include"verif.h"
void Verif(User *s1)
{
    //function need to verify if enabled is 1 or 0 and then show the borrowed books 
	char bookborrow[TAILLE]; //list of books borrowed by s1
	char ligne[TAILLE];
	char login[TAILLE],enabled[2],title[TAILLE],nblv[3];
    int existe=0;// =1 if exist =0 if noon-existant
	FILE *fu = fopen ("user.txt", "r");//open the file user
	int actif=0; //we supposs that the user is non-actif 
    if ( fu==NULL)
	{                                         	                 
        printf(" Erreur fopen signin \n");
        exit (1);
    }
    while (fgets(ligne,TAILLE,fu)!=NULL)
	{//lit le fichier
    		char * token = strtok (ligne,"#");///in the token variable store the value of the loggin in the current line 
    		strcpy(login,token);
    		token=strtok(NULL,"#");//in the token variable store the value of password in the current line
    		token=strtok(NULL,"#");//in the token variable store the value of role in the current line
    		token=strtok(NULL,"#");//in the token variable store the value of enabled in the current line
    		strcpy(enabled,token);
    		token=strtok(NULL,"#");//in the token variable store the value of the number of borrowed books in the current line de la ligne courante
    		strcpy(nblv,token);
    		int n=strlen(nblv);
    		nblv[n-1]='\0'; //remove the last character wish is a newline after each book from user.txt 
    		if (strcmp(login,s1->login)==0)
			{
			    if (strcmp(enabled,"0")==0)
			    {
			    	printf("\nYou didn't respect the rules!\n");
			    	exit(1);
				}
			    else
			    	{
			    	printf("\nYou are dooing well, continue that way ! \n");
			    	printf("\n You borrowed %s books\n",nblv);
				actif=1;						    	
				}
    			existe=1;
    			break;
    		}
    }
	fclose(fu);
    	//instruction to verify the books borrowed by the active user 
   //printf("%d\n",actif);
	if(actif==1)
	{
			char title[TAILLE],lg[TAILLE],hh[TAILLE],mm[TAILLE];
			FILE *fb = fopen ("borrow.txt", "r");
		    if ( fb==NULL)
			{                                         	                 
		        printf(" Erreur fopen borrow.txt \n");
		        exit (1);
		    }
		    printf("Liste des livres empruntés par %s\n",login);
		    while (fgets(ligne,TAILLE,fb)!=NULL)
			{
		    		char * token = strtok (ligne,"#");//in the token variable store the value of the current line's title 
		    		strcpy(title,token);
		    		token=strtok(NULL,"#");//in the token variable store the value of the current line's loggin 
		    		strcpy(lg,token);
		    		token=strtok(NULL,"#");//in the token variable store the value of the current line's loggin 
		    		strcpy(hh,token);				    		
		    		token=strtok(NULL,"#");//in the token variable store the value of the current line's loggin 
		    		strcpy(mm,token);
					int n=strlen(mm);
					mm[n-1]='\0';
					if (strcmp(login,lg)==0)
					{
						printf("\nThe book %s is borrowed, make sure to return is before %sh%s\n",title,hh,mm);
					}
							    			
			}
	fclose(fb);	
	}
	
}
