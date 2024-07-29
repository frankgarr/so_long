/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:33:55 by frankgar          #+#    #+#             */
/*   Updated: 2024/01/21 12:28:04 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(char const *s, char c)
{
	int	i;
	int	qword;

	i = 0;
	qword = 0;
	if (s[0] != c && s[0] != '\0')
		qword++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			qword++;
		i++;
	}
	return (qword);
}

char	**ft_shut_down_and_get_off(char **str, int qword)
{
	while (qword >= 0)
		free (str[qword--]);
	free (str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		start;
	int		fin;
	int		qword;

	start = 0;
	qword = 0;
	str = (char **) malloc((ft_word_count(s, c) + 1) * sizeof (char *));
	if (!str)
		return (NULL);
	while (qword < ft_word_count(s, c))
	{
		while (s[start] == c)
			start++;
		fin = start;
		while (s[fin] != c && s[fin] != '\0')
			fin++;
		str[qword] = ft_substr(s, start, fin - start);
		if (!str[qword])
			return (ft_shut_down_and_get_off(str, qword - 1));
		start = fin;
		qword++;
	}
	str[qword] = 0;
	return (str);
}
/*
int	main(void)
{
	char	**tab;

	tab = ft_split(NULL, 'a');
	return (0);
}*/
