#include"struct.h"
#include "signin.h"
void SignIn (User *s1){

    	
    	char login[TAILLE];
    	int existe=0;// =1 is exist =0 if non-existant
    	
    	char mdp[TAILLE];
    	int pw =0; // =1 if exist =0 if non-existant
    			
	    FILE *fu = fopen ("user.txt", "r");//open file user
    	if ( fu==NULL){                                         	                 
            printf(" Erreur fopen signin \n");
            exit (1);
    	}
    	
    	printf("\n Enter your Identifier \n ");
    	scanf ("%s", (s1->login));
    	
    	int linenumber=0;
    	while (fgets(login,TAILLE,fu)!=NULL){//read the file
    		char * token = strtok (login,"#");
    		linenumber++;
    		if (strcmp(login,s1->login)==0){//comparison 
    			existe=1;
    			break;
    		}
    	}
    	//printf("\n VALEUR LOGIN %s\n", login);
    	
    	if(existe==1)
    	{
		    printf("\nRight identifier !\n");
		       
			//verifier que le mdp est correct
			printf("\nEnter the password \n ");
    		scanf ("%s", (s1->pw));
    		rewind(fu); //return the cursor to the start of the file
    		while (fgets(mdp,TAILLE,fu)!=NULL)
			{
    			char * token = strtok (mdp,"#"); //retrieve login
				token=strtok(NULL,"#");//retrieve the token in seconde position password)
				linenumber--;
				if (linenumber==0)
				{
    				if (strcmp(token,s1->pw)==0)
					{//comparison
    					pw=1;
    				}
    				break;
				}
    		}
    		//printf("\n VALEUR PW %s %d\n", mdp,linenumber);
    		if(pw==1)
				printf("\nRight password !\n");  			 
	    	else
			{
    			printf("\nWrong password !\n");
    			exit(1);
    		}
				
			fclose(fu);  	
		}		 
	    else
		{
    			printf("\nWrong identifier! \n");
    			fclose(fu);  
    			SignIn(s1);
    			exit(1);
    	}
    	printf("\nSuccessful Connection  !  \n");
	printf("		    Welcome %s !\n", s1->login); 	   
}
