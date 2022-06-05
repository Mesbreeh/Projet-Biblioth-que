#include"struct.h"
#include"home.h"
#include"return.h"
#include"borrow.h"
#include"add.h"
#include"purge.h"

void Home(User *s1){//library home

	int action; 
	int *i1=&action; //var action choice
	
	Borrowed l;
	Borrowed *l1=&l;//for borrowed
	
	Books b;
	Books *b1=&b;//for add
	
 	printf(" \nWich action would you like to do ?\n");				
    	printf(" 1. Borrow a book \n");
    	printf(" 2. Return a book \n");
   	printf(" 3. Add a new book \n");
    	printf(" 4. Log out\n");
    
   	while( *(i1) !=1 && *(i1) !=2 && *(i1) !=3 && *(i1) !=4){//borrow, return, add ou exit
	    	scanf("%d", i1); 
 		switch (*i1) {
        		case 1 :
            			Borrow(s1,l1);//lauch the function borrow
            			Home(s1);//home page
				break;
                                            
       			case 2 :
           		    	Return(s1); //lauch the function return
            			Home(s1);
				break;
            
            		case 3 :
           	    		Add(b1,s1);
           	    		Home(s1);
				break;
            
            		case 4 :
           	    		exit(1);
            			break;
        
        		default :
            			printf(" Please enter a valid action by entering the correct number ! \n");
				purge();
    	}	       
}
    printf(" exit \n");
}
