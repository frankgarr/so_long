/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:11:12 by frankgar          #+#    #+#             */
/*   Updated: 2023/09/27 12:43:30 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	while (i != dstsize - 1 && src[i] != '\0' && dstsize != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (len);
}
/*
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define COLOR_BLUE "\x1B[34m"
#define COLOR_GREEN "\x1B[32m"
#define COLOR_RESET "\x1B[0m"
#define COLOR_CYAN "\x1B[36m"
#define COLOR_MAGENTA "\x1B[35m"
#define COLOR_YELLOW "\x1B[33m"
#define COLOR_RED "\x1B[31m"
int nbsi(char *c)
{
	int i = 0;
	while (c[i] != '\0')
	{
		if (isdigit(c[i]))
			i++;
		else
			return(0);
	}
	return (1);
}
int main() 
{
	char a[50], b[50], c[30];
	size_t result;
	printf (COLOR_CYAN"Dst: "COLOR_RESET);
	scanf ("%[^\n]s", a);
	printf (COLOR_CYAN"Src: "COLOR_RESET);
	scanf ("%*c%[^\n]s", b);
	printf (COLOR_CYAN"Size: "COLOR_RESET);
	scanf ("%*c%s", c);
	while (nbsi(c) == 0)
	{
		printf (COLOR_RED"Comando no valido, Size tiene que ser un numero\n");
		printf (COLOR_CYAN"Size: "COLOR_RESET);
		scanf ("%s", c);
	}
	char *a2 = strdup ((const char *)a), *b2 = strdup ((const char *)b),
		*c2 = strdup ((const char *)c);
	//ORIGINAL
	printf (COLOR_YELLOW"-------------------------------------------------\n");
	printf ("              FUNCION ORIGINAL strlcpy:\n");
	printf ("Tu dst era: '%s'\n", a);
	//FUNCION QUE QUIERES AQUI ABAJO
	result = strlcpy( a, b, atoi(c));
	//FUNCION ARRIBA
	printf("Size de src es: '%zu', Tu dst tendria que dar: '%s' \n",
		   	result, a); 
	printf (COLOR_YELLOW"-------------------------------------------------\n");

	//PROPIA
	printf (COLOR_GREEN"-------------------------------------------------\n");
	printf ("              FUNCION PROPIA strlcpy:\n");
	printf ("Tu dst era: '%s'\n", a2);
	result = ft_strlcpy( a2, b2, atoi(c2));
	printf("Size de src es: '%zu', Tu dst da: '%s' \n",
			 result, a2);
	printf ("-------------------------------------------------\n");
 return (0);
}*/
