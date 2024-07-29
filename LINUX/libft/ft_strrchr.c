/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:32:35 by frankgar          #+#    #+#             */
/*   Updated: 2023/09/25 20:37:01 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (s[i] != (char)c)
	{
		if (i-- <= 0)
			return (NULL);
	}
	return ((char *)&s[i]);
}
/*
int main(void)
{
  int x = 'a';
  char str[] = "Yea, wussup, you have any problem?";
  printf("%s", ft_strrchr(str, x));
  return (0);
 }
*/
