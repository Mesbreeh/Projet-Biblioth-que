#include"selectSorting.h"
void selectSorting(char T[][TAILLEMAXSTR],int N)
{
	int p,i,j;
	char z[TAILLEMAXSTR]; //we suppose that the max a string can stoe is 30 character 
	for(i=0;i<N;i++)
	{
		//find the position of p the min of the sub-array containing T[i],T[i+1],T[i+2].....,T[N-1]
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
