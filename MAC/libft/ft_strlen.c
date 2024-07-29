/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:48:42 by frankgar          #+#    #+#             */
/*   Updated: 2023/09/25 17:20:57 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
#include <stdio.h>

int main(int c, char **v)
{
	if (c == 2)
		printf ("El tamany es: %zu \n",ft_strlen(v[1]));
	else
		printf ("error de argumentos :D \n");
	return (0);
}*/
