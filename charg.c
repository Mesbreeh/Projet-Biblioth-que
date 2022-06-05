#include"charg.h"

void Charg(){//load the number of users and books
	
	int c;
	int nbr_user=0;
	int nbr_livre=0;
	
	FILE *fl = fopen ("user.txt", "r");//open the file loggin
    	if ( fl==NULL){                                         	                 
            printf(" Erreur fopen user charg \n");
            exit (1);
    	}
    	
    	while ((c = getc(fl)) != EOF){//count the number of lines
    		if (c == '\n')
        		nbr_user++;
	}
	printf("\nNbr user : %d \n", nbr_user);
	
 	fclose(fl);
 	
 	FILE *fb = fopen ("book.txt", "r");//open the file book
    	if ( fb==NULL){                                         	                 
            printf(" Erreur fopen book charg \n");
            exit (1);
    	}
    	
    	while ((c = getc(fb)) != EOF){//count th number of books
    		if (c == '\n')
        	nbr_livre++;
	}
	printf("Nbr de livre : %d \n", nbr_livre);
	
 	fclose(fb);
}
