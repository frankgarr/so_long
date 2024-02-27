/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:47:38 by frankgar          #+#    #+#             */
/*   Updated: 2023/09/19 12:51:55 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((unsigned char *)src == (unsigned char *)dst)
		return (0);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
/*#include <stdio.h>
int main(int c, char **v)
{
	if (c == 4)
		printf ("Resultado: '%s'.\n", ft_memcpy(v[1], v[2], atoi(v[3])));
	else
		printf("error de argumentos :D.\n");
	return (0);
}*/
