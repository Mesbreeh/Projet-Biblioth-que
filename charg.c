#include"charg.h"

void Charg(){//charge le nbr d'utilisateur et de livre
	
	int c;
	int nbr_user=0;
	int nbr_livre=0;
	
	FILE *fl = fopen ("user.txt", "r");//ouvre fichier login
    	if ( fl==NULL){                                         	                 
            printf(" Erreur fopen user charg \n");
            exit (1);
    	}
    	
    	while ((c = getc(fl)) != EOF){//compte le nombre de lignes
    		if (c == '\n')
        		nbr_user++;
	}
	printf("\nNbr user : %d \n", nbr_user);
	
 	fclose(fl);
 	
 	FILE *fb = fopen ("book.txt", "r");//ouvre fichier book
    	if ( fb==NULL){                                         	                 
            printf(" Erreur fopen book charg \n");
            exit (1);
    	}
    	
    	while ((c = getc(fb)) != EOF){//compte le nombre de lignes
    		if (c == '\n')
        	nbr_livre++;
	}
	printf("Nbr de livre : %d \n", nbr_livre);
	
 	fclose(fb);
}
