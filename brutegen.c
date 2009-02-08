#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tabela argv[2]

void zera(char p[],char q, int num)
{
	int i;
	for( i = 0 ; i < num ; i++)
		p[i] = (char)q;
	p[i] = '\0';
}

int jaAcabou(int p[], int num, int tam)
{
	int i;

	for ( i = 0 ; i < num ; i++ )
		if ( p[i] >= tam )
			return 1;
	return 0;
}

void gera(char p[],char q[], int num)
{
	int i, k;
	int tam = strlen(q);
	int *vet;

	vet=(int*)calloc(num,sizeof(int));
	if (vet == NULL )
        exit(1);

	//printf("%d\n",vet[1]);
	while ( jaAcabou(vet,num,tam) == 0 )
	{

		for ( i = (num - 1) ; i >= 0 ;  i--)
		{
			p[i] = q[ vet[i] ];
		}

		printf("%s\n",p);

		for ( k = 1 ; k < num ; k++)
			if (vet[k] >= (tam - 1) )
			{
				vet[k] = 0x0;
				vet[k-1]++;
				vet[(num - 1)] = -1; // gambiarra pra dar zero ali embaixo
			}
		vet[(num - 1)]++;

		//printf("%d\n",vet[1]);

	}

}




int main(int argc, char **argv)
{
	int num;
	char palavra[256];

    argc = 3;
    argv[1] = "3";
    argv[2] = "abcd";

	if (argc < 3)
	{
		printf("USO: %s <numero de caracteres> <string de caracteres validos>\n",argv[0]);
		return EXIT_FAILURE;
	}

	num = atoi(argv[1]);
	gera(palavra,tabela,num);

	return EXIT_SUCCESS;
}

