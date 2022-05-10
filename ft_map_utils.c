/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:35:16 by jbatoro           #+#    #+#             */
/*   Updated: 2022/05/05 10:40:48 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check if all lines have the same len */
int	ft_check_lines_len(t_game *data)
{
	int	i;

	i = 0;
	while (i < data->width)
	{
		if (ft_strlen(data->map[i]) != data->length)
			ft_map_error("Error:\nAll line are not equal", data);
		i++;
	}
	return (0);
}

/* Check for exit && collector */
void	ft_check_c_and_e(int index, int j, t_game *data)
{
	if (data->map[index][j] == 'C')
		data->collector++;
	if (data->map[index][j] == 'E')
		data->exit++;
}

/* Check if one line is surrounded by 1 */
void	ft_check_one_line(char *line, t_game *data)
{
	int	i;

	i = 0;
	while (i < ft_strlen(line) - 1)
	{
		if (line[i] != '1')
			ft_map_error("Error:\nap isn't surrounded by walls", data);
		i++;
	}
}
