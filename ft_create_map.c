/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:37:17 by jbatoro           #+#    #+#             */
/*   Updated: 2022/05/05 10:27:48 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Create the map */
char	**ft_creat_map(char *map)
{
	char	**final_map;

	if (map[0] == '\0')
		ft_input_error("error:\nCan't read the file");
	final_map = ft_split(map, '\n');
	free (map);
	return (final_map);
}

/* Read map */
char	**ft_read_map(t_game *data, char *file)
{
	char	*str;
	char	*map;
	int		fd;

	str = "";
	map = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_fd_error("Error:\nCan't create fd\n", map, data);
	while (str)
	{
		str = get_next_line(fd);
		if (str == NULL || str[0] == '\n')
		{
			free(map);
			free(data);
			free(str);
			close(fd);
			exit(EXIT_FAILURE);
		}
		map = ft_strjoin(map, str);
		free(str);
		data->width++;
	}
	free(str);
	close(fd);
	return (ft_creat_map(map));
}
