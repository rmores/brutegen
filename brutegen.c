/*
 *  BruteGen - Bruteforce Wordlist Generator.
    Copyright (C) 2009  Rafael F. M. Mores

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */

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
	}

}




int main(int argc, char **argv)
{
	int num;
	char palavra[256];

	if (argc < 3)
	{
		printf("%s Copyright (C) 2009  Rafael Mores\n \
		This program comes with ABSOLUTELY NO WARRANTY;\n \
		This is free software, and you are welcome to redistribute it\n \
		under certain conditions; \n\n",argv[0]);
		printf("USO: %s <numero de caracteres> <string de caracteres validos>\n",argv[0]);
		return EXIT_FAILURE;
	}

	num = atoi(argv[1]);
	gera(palavra,tabela,num);

	return EXIT_SUCCESS;
}


