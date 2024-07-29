/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:48:20 by frankgar          #+#    #+#             */
/*   Updated: 2023/10/10 11:37:15 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*mfill(int len, int n, int i, int signo)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	i = len--;
	if (signo == -1)
		str[0] = '-';
	while (n != 0)
	{
		str[len--] = n % 10 * signo + '0';
		n = n / 10;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		signo;
	int		i;
	int		len;
	char	*str;

	if (n > 2147483647 || n < -2147483648)
		return (NULL);
	signo = 1;
	i = n;
	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		signo = -1;
		len++;
	}
	while (i != 0)
	{
		i = i / 10;
		len++;
	}
	str = mfill(len, n, i, signo);
	return (str);
}

/*int	main(int argc, char **argv)
{
	if (argc != 2)
	   return (0);
	printf("str: %s\n", ft_itoa(atoi(argv[1])));
	return (0);
}*/
