/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 09:58:18 by frankgar          #+#    #+#             */
/*   Updated: 2023/10/07 18:36:40 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = (char *)malloc ((int)ft_strlen (s1) + 1 * sizeof (char));
	if (str)
		ft_strlcpy (str, s1, (int)ft_strlen (s1) + 1);
	return (str);
}
