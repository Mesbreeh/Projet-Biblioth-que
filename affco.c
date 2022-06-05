#include"Affco.h"
#include"struct.h"
#include"signup.h"
#include"signin.h"
#include"purge.h"

User affco(User *s1){//first page of the program

	int choice;
	int *c1=&choice;//var choice 


	printf(" -------------------------- \n");
	printf(" 	CY-biblioTECH       \n");
	printf(" -------------------------- \n");
	printf("\n");
	printf(" 1. Sign in \n");
	printf(" 2. Sign up\n");
	printf(" 3. Quit\n");
	                               
    
    while( *(c1) !=1 && *(c1) !=2){ 	//sign in or sign up
	scanf("%d", c1); 	
						
    	switch (*c1) {
        	case 1 :
            		SignIn(s1);	//sign in (connection)
            	break;
 
       		case 2 :
           	 	SignUp(s1);	//sign up (registration)
            	break;
            	
            	case 3:
            		exit(1);
            	break;
        
        	default :
            		printf("Would you mind choosing between 1, 2 or 3 \n");
			purge();
        }        
    }
	
	return *s1;
}
