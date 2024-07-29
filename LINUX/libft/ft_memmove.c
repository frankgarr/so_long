/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:36:18 by frankgar          #+#    #+#             */
/*   Updated: 2023/10/05 09:57:32 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if ((unsigned char *)src == NULL && (unsigned char *)dst == NULL)
		return (0);
	if (dst > src)
	{
		while (len)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
int main(int c, char **v)
{

	if (c == 4)
		printf ("Tu Resultado: '%s'.\n", ft_memmove(v[1], v[2], atoi(v[3])));
	else if (c == 5)
		printf ("Resultado Esperado: '%s'.\n", memmove(v[1], v[2], atoi(v[3])));
	else
		printf("error de argumentos :D.\n");
	return (0);
}*/
