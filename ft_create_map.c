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
		ft_input_error("error");
	final_map = ft_split(map, '\n');
	free (map);
	return (final_map);
}

/* Read map */
char	**ft_read_map(t_game *data, char *file)
{
	char	*line;
	char	*all_lines;
	int		fd;

	data->width = 0;
	line = "";
	all_lines = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror("error fd");
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
		data->width++;
	}
	free(line);
	close(fd);
	return (ft_creat_map(all_lines));
}
