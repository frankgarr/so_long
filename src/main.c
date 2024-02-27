/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:21:21 by frankgar          #+#    #+#             */
/*   Updated: 2024/02/25 11:21:41 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		exit(ft_fd_printf(2, "Error\nArguments.\n") * 0 + 1);
	if (!correct_file(argv[1]))
		exit(ft_fd_printf(2, "Error\nUnexpected File Extension.\n") * 0 + 1);
	if (fd < 0)
		exit(ft_fd_printf(2, "Error\nNot Able To Open The File.\n") * 0 + 1);
	parsing(fd);
	ft_printf(":D\n");
	return (0);
}
