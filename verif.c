#include"struct.h"
#include"verif.h"
void Verif(User *s1)
{
    //fonction besoin de verifier si enabled 1 ou 0 et ensuite de dire les livres empruntÃ©s
	char bookborrow[TAILLE]; //liste des livres empruntés par s1
	char ligne[TAILLE];
	char login[TAILLE],enabled[2],title[TAILLE],nblv[3];
    int existe=0;// =1 si existe =0 si inexistant
	FILE *fu = fopen ("user.txt", "r");//ouvre fichier user
	int actif=0; //on suppose que l'utilisateur etudié est inactif
    if ( fu==NULL)
	{                                         	                 
        printf(" Erreur fopen signin \n");
        exit (1);
    }
    while (fgets(ligne,TAILLE,fu)!=NULL)
	{//lit le fichier
    		char * token = strtok (ligne,"#");//stocker, dans la variable token, la valeur du login de la ligne courante
    		strcpy(login,token);
    		token=strtok(NULL,"#");//stocker, dans la variable token, la valeur du mdp de la ligne courante
    		token=strtok(NULL,"#");//stocker, dans la variable token, la valeur du role de la ligne courante
    		token=strtok(NULL,"#");//stocker, dans la variable token, la valeur de enabled de la ligne courante
    		strcpy(enabled,token);
    		token=strtok(NULL,"#");//stocker, dans la variable token, la valeur du nbr de livres empruntés de la ligne courante
    		strcpy(nblv,token);
    		int n=strlen(nblv);
    		nblv[n-1]='\0'; //retirer le dernier caractère qui est un retour à la ligne apres chaque nbr de livres dans user.txt
    		if (strcmp(login,s1->login)==0)
			{
			    if (strcmp(enabled,"0")==0)
			    {
			    	printf("\nVous n'avez pas respectez les règles!\n");
			    	exit(1);
				}
			    else
			    	{
			    	printf("\nVous avez respectez les règles, continué comme ca ! \n");
			    	printf("\n Vous avez emprunté %s livres\n",nblv);
				actif=1;						    	
				}
    			existe=1;
    			break;
    		}
    }
	fclose(fu);
    	//instructions pour verifier les livres empruntés par l'utilisateur actif
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
			{//lit le fichier
		    		char * token = strtok (ligne,"#");//stocker, dans la variable token, la valeur du titre de la ligne courante
		    		strcpy(title,token);
		    		token=strtok(NULL,"#");//stocker, dans la variable token, la valeur du login de la ligne courante
		    		strcpy(lg,token);
		    		token=strtok(NULL,"#");//stocker, dans la variable token, la valeur du login de la ligne courante
		    		strcpy(hh,token);				    		
		    		token=strtok(NULL,"#");//stocker, dans la variable token, la valeur du login de la ligne courante
		    		strcpy(mm,token);
					int n=strlen(mm);
					mm[n-1]='\0';
					if (strcmp(login,lg)==0)
					{
						printf("\nLe livre %s est emprunté, attention à rendre avant %sh%s\n",title,hh,mm);
					}
							    			
			}
	fclose(fb);	
	}
	
}
