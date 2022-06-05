#ifndef STRUCT_H
    #define STRUCT_H
    #include <stdio.h>
    #define TAILLE 40
    #define TAILLEMAXSTR 30
    #define NBBOOKSMAX 1000

typedef struct {
    
        char login[TAILLE];
        char pw[TAILLE];                            
        int  role[1];
	int  enabled;
	int nbremprunt;
        
}User; //structure user


typedef struct {
    
    char title[TAILLE];
    char author[TAILLE];                            
    int  num[TAILLE];
    int category[1];
    
}Books;//structure book


typedef struct {

	int  heurpri;				
	int  heurend;				
	int  minpri;				
	int  minrend;		
				
}Borrowed;//structure borrow

#endif
