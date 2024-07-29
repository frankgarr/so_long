/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:08:51 by frankgar          #+#    #+#             */
/*   Updated: 2023/10/05 10:15:19 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s) || len == 0 || ft_strlen(s) == 0)
	{
		str = (char *)malloc(1);
		if (str == NULL)
			return (NULL);
		str[i] = '\0';
		return (str);
	}
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	str = (char *) malloc ((len + 1) * sizeof (char));
	if (str == NULL)
		return (NULL);
	while (i < len && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
