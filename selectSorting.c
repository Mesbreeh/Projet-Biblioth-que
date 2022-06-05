#include"selectSorting.h"
void selectSorting(char T[][TAILLEMAXSTR],int N)
{
	int p,i,j;
	char z[TAILLEMAXSTR]; //on suppose que la taille maximale d'une chaine est 30 caractères
	for(i=0;i<N;i++)
	{
		//chercher la position p du min du sous tableau contenant T[i],T[i+1],T[i+2].....,T[N-1]
		p=i;
		for(j=i+1;j<N;j++)
		{
			if(strcmp(T[j],T[p])<0)
			{
				p=j;
			}
		}
		strcpy(z,T[i]);
		strcpy(T[i],T[p]);
		strcpy(T[p],z);
	}
}
