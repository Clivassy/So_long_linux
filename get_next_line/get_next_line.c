/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:13:08 by jbatoro           #+#    #+#             */
/*   Updated: 2022/01/12 17:48:07 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_search(char *s)
{
	if (!s)
		return (0);
	while (*s && *s != '\n')
		s++;
	if (*s == '\n')
		return (s);
	return (NULL);
}

char	*ft_get_remainder(char *buffer)
{
	int		i;
	int		remainder_len;
	char	*save_remainder;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	remainder_len = ft_strlen(buffer) - i;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	save_remainder = malloc(sizeof(char *) * remainder_len + 1);
	if (!save_remainder)
		return (NULL);
	i++;
	save_remainder = ft_strncpy(save_remainder, buffer + i, remainder_len);
	free (buffer);
	return (save_remainder);
}

char	*ft_get_one_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char ) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_buff(int fd, char *static_buff)
{
	char	*save_buff;
	int		return_value;

	save_buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!save_buff)
		return (NULL);
	return_value = 1;
	while (return_value > 0)
	{
		return_value = read(fd, save_buff, BUFFER_SIZE);
		if (return_value == -1)
		{
			free (save_buff);
			return (NULL);
		}
		save_buff[return_value] = '\0';
		static_buff = ft_strjoin(static_buff, save_buff);
		if (ft_search(static_buff))
			break ;
	}
	free (save_buff);
	return (static_buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer_read = ft_read_buff(fd, buffer_read);
	if (!buffer_read)
		return (NULL);
	line = ft_get_one_line(buffer_read);
	buffer_read = ft_get_remainder(buffer_read);
	return (line);
}
