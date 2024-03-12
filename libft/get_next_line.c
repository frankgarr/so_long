/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:48:03 by frankgar          #+#    #+#             */
/*   Updated: 2024/03/08 14:40:13 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free(char **ptr1, char **ptr2)
{
	if (ptr1 && *ptr1)
	{
		free(*ptr1);
		*ptr1 = NULL;
	}
	if (ptr2 && *ptr2)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
	return (NULL);
}

char	*take_line(char *buf, char *line)
{
	int	len;

	len = 0;
	if (!buf[len])
		return (NULL);
	while (buf[len] && buf[len] != '\n')
		len++;
	if (buf[len] == '\n')
		len++;
	line = malloc(len + 1 * sizeof(char));
	if (!line)
		return (NULL);
	line[len] = '\0';
	len = 0;
	while (buf[len] && buf[len] != '\n')
	{
		line[len] = buf[len];
		len++;
	}
	if (buf[len] == '\n')
		line[len] = '\n';
	return (line);
}

char	*read_line(int fd, char *buf, int byte)
{
	char	*tmpbuf;
	int		checker;
	char	*tmp;

	checker = 0;
	tmpbuf = malloc(BUFFER_SIZE + 1 * sizeof (char));
	if (!tmpbuf)
		return (ft_free(&buf, &tmpbuf));
	while (byte > 0 && checker != 1)
	{
		byte = read (fd, tmpbuf, BUFFER_SIZE);
		if (byte < 0)
			return (ft_free(&buf, &tmpbuf));
		tmpbuf[byte] = '\0';
		tmp = ft_strjoin(buf, tmpbuf);
		if (!tmp)
			return (ft_free(&buf, &tmpbuf));
		ft_free(&buf, NULL);
		buf = tmp;
		if (ft_strchr_pos(tmpbuf, '\n'))
			checker++;
	}
	ft_free(&tmpbuf, NULL);
	return (buf);
}

char	*next_buffer(char *buf)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = ft_strchr_pos(buf, '\0');
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
		return (ft_free(&buf, NULL));
	tmp = malloc ((j - i) * sizeof (char));
	i++;
	j = 0;
	if (!tmp)
		return (ft_free(&buf, NULL));
	while (buf[i])
		tmp[j++] = buf[i++];
	tmp[j] = '\0';
	ft_free(&buf, NULL);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf)
	{
		buf = malloc (1 * sizeof (char));
		if (!buf)
			return (NULL);
		buf[0] = '\0';
	}
	buf = read_line(fd, buf, 1);
	if (!buf)
		return (NULL);
	line = take_line(buf, line);
	if (!line || *line == '\0')
		return (ft_free(&buf, &line));
	buf = next_buffer(buf);
	return (line);
}
/*
int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
		return (0);
	char *line = NULL;
	//int fd = open ("txt", O_RDONLY);
	for (int i = 1; i <= 7; i++)
	{
		line = get_next_line(0);
		printf("line[%i] = %s", i, line);
		free (line);	
	}

	return (0);
}*/
