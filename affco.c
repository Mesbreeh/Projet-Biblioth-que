#include"Affco.h"
#include"struct.h"
#include"signup.h"
#include"signin.h"
#include"purge.h"

User affco(User *s1){//1ere page du programme

	int choice;
	int *c1=&choice;//var choix 


	printf(" -------------------------- \n");
	printf(" 	CY-biblioTECH       \n");
	printf(" -------------------------- \n");
	printf("\n");
	printf(" 1. Sign in \n");
	printf(" 2. Sign up\n");
	printf(" 3. Qutter\n");
	                               
    
    while( *(c1) !=1 && *(c1) !=2){ 	//inscription ou connexion
	scanf("%d", c1); 	
						
    	switch (*c1) {
        	case 1 :
            		SignIn(s1);	//fonction connexion
            	break;
 
       		case 2 :
           	 	SignUp(s1);	//fonction inscription
            	break;
            	
            	case 3:
            		exit(1);
            	break;
        
        	default :
            		printf(" Veuillez choisir 1, 2 ou 3 \n");
			purge();
        }        
    }
	
	return *s1;
}
