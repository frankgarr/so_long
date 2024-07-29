/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:07:20 by frankgar          #+#    #+#             */
/*   Updated: 2023/10/13 12:37:26 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	sl;

	i = 0;
	sl = '\n';
	if (!s)
		return ;
	while (s[i])
		write(fd, &s[i++], 1);
	write(fd, &sl, 1);
}
