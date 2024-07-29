/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:37:48 by frankgar          #+#    #+#             */
/*   Updated: 2023/10/13 16:37:01 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

int	ft_power(int power)
{
	int	result;

	result = 1;
	if (power == 0)
		return (result);
	while (power != 0)
	{
		result *= 10;
		power--;
	}
	return (result);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;
	int	tmp;
	int	len;

	sign = 1;
	len = 0;
	tmp = n;
	if (n < 0)
	{
		sign = -1;
		write (fd, "-", 1);
	}
	if (n == 0)
		len++;
	while (tmp != 0)
	{
		tmp /= 10;
		len++;
	}
	while (len > 0)
	{
		tmp = (n / ft_power(--len) * sign) + '0';
		write (fd, &tmp, 1);
		n = n - ((n / ft_power(len)) * ft_power(len));
	}
}
/*
int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int fd;

	fd = open("archivo.txt", O_WRONLY);
	
	ft_putnbr_fd(atoi(argv[1]), fd);
	printf ("\n"); 
	return (0);
}*/
