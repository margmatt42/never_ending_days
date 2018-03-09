#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_count_words(char *str)
{
	int compteur;

	compteur = 0;
	while(*str)
	{
		if (*str != '\t' && *str != ' ' && *str != '\n')
		{
			compteur++;
			while ( *str && *str != '\t' && *str != ' '  && *str != '\n')
			{
				str++;
			}		
		}
		while ( *str == ' ' || *str == '\t' || *str == '\n')
		{
			str++;
		}
	}
	return (compteur);
}

char **ft_white_spirit(char *str)
{

	char **tab;
	char **tmp;
	char *ancrage;
	int compteur;
	int taille;

	taille = ft_count_words(str) + 1;

	tab = (char **)malloc(sizeof(char*)*taille);
 	tab[taille-1] = 0;
	tmp = tab; 
	while(*str)
	{
		compteur = 0;
	
		if (*str != '\t' && *str != ' ' && *str != '\n')
		{
			ancrage = str;
			while ( *str && *str != '\t' && *str != ' '  && *str != '\n')
			{
				compteur++;
				str++;
			}
			*tmp = strndup(ancrage, compteur);	
			tmp ++;	
		}	
		while ( *str == ' ' || *str == '\t' || *str == '\n')
		{
			str++;
		}	
		
	}
	return (tab);
}

int	main(int argc, char **argv)
{ 
	char ** tab;
	tab = ft_white_spirit(argv[1]);
	if (argc == 2)
	{		
		while (*tab)
		{
			printf("%s\n", *tab);
			tab++;
		
		}
	}
	return (0);	
}




