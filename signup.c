#include"struct.h"
#include"signup.h"
#include"charg.h"
#include"purge.h"
void SignUp (User *s1){//function creation of the account
    	
    	Charg();
    	
    	char login[TAILLE];
    	int dispo=0;// =0 is available =1 if none available 
    	
	FILE *fu = fopen ("user.txt", "r");//open file 
    	if ( fu==NULL){                                         	                 
            printf(" Erreur fopen u \n");
            exit (1);
    	}
    	
    	printf("\nCreate your Identifier \n ");
    	scanf ("%s", (s1->login));
    	
    	while (fgets(login,TAILLE,fu)!=NULL){//read the file
    		char * token = strtok (login,"#");
    		    		
    		if (strcmp(login,s1->login)==0){//comparison 
    			dispo=1;
    			break;
    		}
    	}
    	//printf("\n VALEUR LOGIN %s\n", login);
    		if(dispo==0){
    			
    			printf(" Login avaible\n");
    			
    			printf("\nCréer votre MDP \n ");
    			scanf ("%s", (s1->pw)); 
    	
    			while( *(s1->role) != 1 && *(s1->role) != 2 ) {
   	 			printf("\nEnter your role : \n" );
    				printf(" 1. Teacher  \n" );	
    				printf(" 2. Student \n" );	
				scanf( "%d", s1->role );
				purge();
			}
			s1->enabled=1; //activate the account 
			s1->nbremprunt=0;
 		}
 	
    		else{
    			printf(" Login unavailable\n");
    			exit(1);
    		}
    			
    	fclose(fu);   
    	
    	
 	
 	FILE *fu2 = fopen ("user.txt", "a");//open file
    	if ( fu2==NULL){                                         	                 
            printf(" Erreur fopen u2 \n");
            exit (1);
    	}
    	
    	fprintf(fu2,"%s#%s#%d#%d#%d\n", s1->login, s1->pw, *s1->role, s1->enabled, s1->nbremprunt);
 	
 	fclose(fu2);
 	
 	printf("\n Login : %s \n Password : %s \n Role : %d \n Etat : %d \n Number of borrowed books : %d\n", s1->login, s1->pw, *s1->role, s1->enabled, s1->nbremprunt);	
	printf(" \nSuccessful registration ! \n");
	
	Charg();
}
