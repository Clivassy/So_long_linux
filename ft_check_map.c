/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:25:28 by jbatoro           #+#    #+#             */
/*   Updated: 2022/05/04 17:46:23 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check if there is only one player */
int	ft_is_one_player(t_game *data)
{
	int	i;
	int	j;

	data->player = 0;
	i = 0;
	while (i < data->width)
	{
		j = 0;
		while (j < data->length)
		{	
			if (data->map[i][j] == 'P')
				data->player++;
			j++;
		}
		i++;
	}
	if (data->player != 1)
		ft_map_error("Error:\nMore or less than one player", data);
	return (0);
}

/* Check if start && end colums are filled with 1 
   && if there is at least one C && one E*/
void	ft_check_columns(t_game *data)
{
	int	last_nb;
	int	first_nb;
	int	j;
	int	i;

	i = 0;
	first_nb = 0;
	last_nb = data->length - 1;
	while (i < data->width)
	{
		if (data->map[first_nb][0] != '1'
			|| data->map[first_nb][last_nb] != '1')
			ft_map_error("Error:\nMap isn't surrounded by walls", data);
		j = 0;
		while (j < data->length)
		{
			ft_check_c_and_e(i, j, data);
			j++;
		}
		i++;
		first_nb++;
	}
	if (data->collector < 1 || data->exit < 1)
		ft_map_error("Error:\nNo collector or exit in map", data);
}

/* Check if map is surrounded by wall */
void	ft_check_walls(t_game *data)
{
	int	i;
	int	last_line;
	int	first_line;

	last_line = data->width -1 ;
	first_line = 0;
	i = 0;
	ft_check_one_line(data->map[first_line], data);
	ft_check_one_line(data->map[last_line], data);
	ft_check_columns(data);
}

/* Check if there is only valid characters in the map */
void	ft_check_inside_map(t_game *data)
{
	int	j;
	int	len;
	int	i;

	i = 0;
	len = data->length -1;
	while (i < data->width)
	{
		j = 0;
		while (j < len)
		{
			if (data->map[i][j] == '0' || data->map[i][j] == '1'
					|| data->map[i][j] == 'E'
					|| data->map[i][j] == 'C' || data->map[i][j] == 'P')
				j++;
			else
				ft_map_error("error: map contains invalid characters", data);
		}
		i++;
	}
	ft_is_one_player(data);
}

/* Check all conditions for a valid map*/
void	ft_map_checker(t_game *data)
{
	ft_check_lines_len(data);
	ft_check_walls(data);
	ft_check_inside_map(data);
}
