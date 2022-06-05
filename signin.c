#include"struct.h"
#include "signin.h"
void SignIn (User *s1){

    	
    	char login[TAILLE];
    	int existe=0;// =1 si existe =0 si inexistant
    	
    	char mdp[TAILLE];
    	int pw =0; // =1 si existe =0 si inexistant
    			
	    FILE *fu = fopen ("user.txt", "r");//ouvre fichier user
    	if ( fu==NULL){                                         	                 
            printf(" Erreur fopen signin \n");
            exit (1);
    	}
    	
    	printf("\n Entrer votre Identifiant \n ");
    	scanf ("%s", (s1->login));
    	
    	int linenumber=0;
    	while (fgets(login,TAILLE,fu)!=NULL){//lit le fichier
    		char * token = strtok (login,"#");
    		linenumber++;
    		if (strcmp(login,s1->login)==0){//comparaison 
    			existe=1;
    			break;
    		}
    	}
    	//printf("\n VALEUR LOGIN %s\n", login);
    	
    	if(existe==1)
    	{
		    printf("\nBon identifiant !\n");
		       
			//verifier que le mdp est correct
			printf("\nSaisir le MDP \n ");
    		scanf ("%s", (s1->pw));
    		rewind(fu); //remettre le curseur au debut du fichier
    		while (fgets(mdp,TAILLE,fu)!=NULL)
			{//lit le fichier
    			char * token = strtok (mdp,"#"); //recuprer le login
				token=strtok(NULL,"#");//recuperer le token de 2eme position càd le mdp
				linenumber--;
				if (linenumber==0)
				{
    				if (strcmp(token,s1->pw)==0)
					{//comparaison 
    					pw=1;
    				}
    				break;
				}
    		}
    		//printf("\n VALEUR PW %s %d\n", mdp,linenumber);
    		if(pw==1)
				printf("\nBon mot de passe !\n");  			 
	    	else
			{
    			printf("\nMauvais mdp !\n");
    			exit(1);
    		}
				
			fclose(fu);  	
		}		 
	    else
		{
    			printf("\nMauvais identifiant ! \n");
    			fclose(fu);  
    			SignIn(s1);
    			exit(1);
    	}
    	printf("\nConnexion réussi ! \n");
	printf("		    Bienvenue %s !\n", s1->login); 	   
}
