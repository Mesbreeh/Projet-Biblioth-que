#include"struct.h"
#include"home.h"
#include"return.h"
#include"borrow.h"
#include"add.h"
#include"purge.h"

void Home(User *s1){//accueil biblio

	int action; 
	int *i1=&action; //var action choisit
	
	Borrowed l;
	Borrowed *l1=&l;//pour emprunté
	
	Books b;
	Books *b1=&b;//pour add
	
 	printf(" \nQuelle action voulez-vous faire ?`\n");				
    	printf(" 1. Emprunter un nouveau livre \n");
    	printf(" 2. Rendre un livre \n");
   	printf(" 3. Ajouter un nouveau livre \n");
    	printf(" 4. Se deconnecter \n");
    
   	while( *(i1) !=1 && *(i1) !=2 && *(i1) !=3 && *(i1) !=4){//emprunt, rendre, ajouter ou sorti
	    	scanf("%d", i1); 
 		switch (*i1) {
        		case 1 :
            			Borrow(s1,l1); //lance fonction emprunt
            			Home(s1);//retour accueil
				break;
                                            
       			case 2 :
           		    	Return(s1); //lance fonction rendre
            			Home(s1);
				break;
            
            		case 3 :
           	    		Add(b1,s1);
				break;
            
            		case 4 :
           	    		exit(1);
            			break;
        
        		default :
            			printf(" Veuillez saisir une action valide en entrant le bon chiffre ! \n");
				purge();
    	}	       
}
    printf(" sorti \n");
}
