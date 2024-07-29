/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:03:15 by frankgar          #+#    #+#             */
/*   Updated: 2023/12/23 13:09:22 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_verify(const char src, const char *obj)
{
	int	i;

	i = 0;
	while (obj[i])
	{
		if (src == obj[i++])
			return (1);
	}
	return (0);
}

int	ft_position(const char *src, const char *obj, int i)
{
	int	x;

	x = 1;
	if (i > 0)
	{
		x = -1;
		i += x;
	}
	while (ft_verify (src[i], obj) == 1)
		i += x;
	return (i);
}

char	*ft_strtrim(const char *src, const char *obj)
{
	int		i;
	int		j;
	char	*str;

	i = ft_position(src, obj, 0);
	j = ft_position(src, obj, (ft_strlen (src)));
	str = ft_substr(src, i, j - i + 1);
	return (str);
}
/*
int main(void)
{
  char *set = "te";
  printf("%s", ft_strtrim (NULL, set));
  return (0);
}*/
