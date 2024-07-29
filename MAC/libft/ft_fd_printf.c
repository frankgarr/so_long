/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:50:15 by frankgar          #+#    #+#             */
/*   Updated: 2023/12/28 18:37:10 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_char(const int fd, char c, int *len)
{
	if (*len != -1)
	{
		if (write(fd, &c, 1) == -1)
			*len = -1;
		else
			*len += 1;
	}
}

static void	print_str(const int fd, char *s, int *len)
{
	if (!s)
		s = "(null)";
	while (*s && *len != -1)
		print_char(fd, *s++, len);
}

static void	print_nbr(unsigned long n, int *base, const char *f, int *len)
{
	if ((int)n < 0 && (*f == 'd' || *f == 'i'))
	{
		n = -n;
		print_char(base[0], '-', len);
	}
	if (n >= (unsigned int)base[1])
		print_nbr(n / base[1], base, f, len);
	if (*len == -1)
		return ;
	if (*f == 'X')
		print_char(base[0], "0123456789ABCDEF"[n % base[1]], len);
	else
		print_char(base[0], "0123456789abcdef"[n % base[1]], len);
}

//la variable "base" contendrá el int fd ya que put_nbr tiene 
//el máximo de variables posibles.

static void	print_checker(const int fd, const char *f, va_list arg, int *len)
{
	int	base[2];

	base[0] = fd;
	base[1] = 10;
	if (*f == 'c')
		print_char(fd, va_arg(arg, int), len);
	else if (*f == 's')
		print_str(fd, va_arg(arg, char *), len);
	else if (*f == 'd' || *f == 'i')
		print_nbr(va_arg(arg, int), base, f, len);
	else if (*f == 'u')
		print_nbr(va_arg(arg, unsigned int), base, f, len);
	else if (*f == 'p')
	{
		base[1] = 16;
		print_str(fd, "0x", len);
		print_nbr(va_arg(arg, unsigned long), base, f, len);
	}
	else if (*f == 'x' || *f == 'X')
	{
		base[1] = 16;
		print_nbr(va_arg(arg, unsigned int), base, f, len);
	}
	else if (*f == '%')
		print_char(fd, '%', len);
}

int	ft_fd_printf(int fd, const char *f, ...)
{
	va_list	arg;
	int		len;

	len = 0;
	if (f == NULL)
		return (0);
	va_start(arg, f);
	while (*f && len != -1)
	{
		if (*f == '%')
		{
			f++;
			print_checker(fd, f, arg, &len);
		}
		else
			print_char(fd, *f, &len);
		if (*f != '\0')
			f++;
	}
	va_end(arg);
	return (len);
}
