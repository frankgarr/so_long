/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:14:11 by frankgar          #+#    #+#             */
/*   Updated: 2023/12/28 18:36:43 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_char(char c, int *len)
{
	if (*len != -1)
	{
		if (write(1, &c, 1) == -1)
			*len = -1;
		else
			*len += 1;
	}
}

static void	print_str(char *s, int *len)
{
	if (!s)
		s = "(null)";
	while (*s && *len != -1)
		print_char(*s++, len);
}

static void	print_nbr(unsigned long n, unsigned int base, const char *f,
	int *len)
{
	if ((int)n < 0 && (*f == 'd' || *f == 'i'))
	{
		n = -n;
		print_char('-', len);
	}
	if (n >= base)
		print_nbr(n / base, base, f, len);
	if (*len == -1)
		return ;
	if (*f == 'X')
		print_char("0123456789ABCDEF"[n % base], len);
	else
		print_char("0123456789abcdef"[n % base], len);
}

static void	print_checker(const char *f, va_list arg, int *len)
{
	if (*f == 'c')
		print_char(va_arg(arg, int), len);
	else if (*f == 's')
		print_str(va_arg(arg, char *), len);
	else if (*f == 'd' || *f == 'i')
		print_nbr(va_arg(arg, int), 10, f, len);
	else if (*f == 'u')
		print_nbr(va_arg(arg, unsigned int), 10, f, len);
	else if (*f == 'p')
	{
		print_str("0x", len);
		print_nbr(va_arg(arg, unsigned long), 16, f, len);
	}
	else if (*f == 'x' || *f == 'X')
		print_nbr(va_arg(arg, unsigned int), 16, f, len);
	else if (*f == '%')
		print_char('%', len);
}

int	ft_printf(const char *f, ...)
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
			print_checker(f, arg, &len);
		}
		else
			print_char(*f, &len);
		if (*f != '\0')
			f++;
	}
	va_end(arg);
	return (len);
}
/*
#include <fcntl.h>

int main(void)
{
	int		fd;
	int		tmp;
	char	*str = ".fd_prueba";
	int		res;
	int		res2;

	fd = open(str, O_CREAT | O_RDONLY);
	tmp = dup(1);
	dup2(fd, 1);
	res = ft_printf("a");
	res2 = printf("a\n");
	dup2(tmp, 1);
	printf("res [ft_printf]: %i && res2 [printf]: %i\n", res, res2);
	close(fd);
	unlink(str);
	return (0);	
}*/
