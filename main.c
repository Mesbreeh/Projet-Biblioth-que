#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include"Affco.h"
#include"home.h"
#include"verif.h"
#include"struct.h"

#define TAILLE 40
#define TAILLEMAXSTR 30   //nombre de caractères maximal qu'un titre de livre peut avoir
#define NBBOOKSMAX 1000   //nombre de titres (de livres) que le tableau T peut stocker

int main (){
	
	User si;  //obliger                               
	User *s1=&si;//obliger
	
	affco(s1);
	
	Verif(s1);
	
	Home(s1);
    	
	return 0;
}
