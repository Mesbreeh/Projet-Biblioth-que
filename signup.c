#include"struct.h"
#include"signup.h"
#include"charg.h"
#include"purge.h"
void SignUp (User *s1){//fonction creation de compte
    	
    	Charg();
    	
    	char login[TAILLE];
    	int dispo=0;// =0 si dispo =1 si indispo
    	
	FILE *fu = fopen ("user.txt", "r");//ouvre fichier
    	if ( fu==NULL){                                         	                 
            printf(" Erreur fopen u \n");
            exit (1);
    	}
    	
    	printf("\nCréer votre Identifiant \n ");
    	scanf ("%s", (s1->login));
    	
    	while (fgets(login,TAILLE,fu)!=NULL){//lit le fichier
    		char * token = strtok (login,"#");
    		    		
    		if (strcmp(login,s1->login)==0){//comparaison 
    			dispo=1;
    			break;
    		}
    	}
    	//printf("\n VALEUR LOGIN %s\n", login);
    		if(dispo==0){
    			
    			printf(" Login disponible\n");
    			
    			printf("\nCréer votre MDP \n ");
    			scanf ("%s", (s1->pw)); 
    	
    			while( *(s1->role) != 1 && *(s1->role) != 2 ) {
   	 			printf("\nEntrer votre role : \n" );
    				printf(" 1. Professeur  \n" );	
    				printf(" 2. Etudiant \n" );	
				scanf( "%d", s1->role );
				purge();
			}
			s1->enabled=1; //active le compte
			s1->nbremprunt=0;
 		}
 	
    		else{
    			printf(" Login indisponible\n");
    			exit(1);
    		}
    			
    	fclose(fu);   
    	
    	
 	
 	FILE *fu2 = fopen ("user.txt", "a");//ouvre fichier
    	if ( fu2==NULL){                                         	                 
            printf(" Erreur fopen u2 \n");
            exit (1);
    	}
    	
    	fprintf(fu2,"%s#%s#%d#%d#%d\n", s1->login, s1->pw, *s1->role, s1->enabled, s1->nbremprunt);
 	
 	fclose(fu2);
 	
 	printf("\n Login : %s \n Password : %s \n Role : %d \n Etat : %d \n Nombre de Livre Emprunté : %d\n", s1->login, s1->pw, *s1->role, s1->enabled, s1->nbremprunt);	
	printf(" \nInscription réussi ! \n");
	
	Charg();
}
