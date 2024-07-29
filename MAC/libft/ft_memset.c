/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:01:05 by frankgar          #+#    #+#             */
/*   Updated: 2023/09/17 20:31:11 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}
/*
#include <stdio.h>
int main(int c, char **v)
{
	if (c == 4)
	{	
	printf ("la solucion es: %s \n", ft_memset(v[1], v[2][0], atoi(v[3])));
	}
	else 
		printf("Error de argumenots :D \n");
	return (0);
}*/
