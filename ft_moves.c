/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:47:42 by jbatoro           #+#    #+#             */
/*   Updated: 2022/05/04 17:56:14 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_player_pos(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->p_x = x;
				data->p_y = y;
			}
			x++;
		}
		y++;
	}
}

void	ft_move_up(t_game *data)
{
	ft_get_player_pos(data);
	data->p_y--;
	if (data->map[data->p_y][data->p_x] != '1')
	{
		if (data->map[data->p_y][data->p_x] == 'E')
		{
			if (data->collector == 0)
				ft_exit(data);
			else
				return ;
		}
		if (data->map[data->p_y][data->p_x] == 'C')
			data->collector--;
		data->map[data->p_y][data->p_x] = 'P';
		img_draw(data, data->img_player, data->p_x, data->p_y);
		data->map[data->p_y + 1][data->p_x] = '0';
		img_draw(data, data->img_floor, data->p_x, (data->p_y +1));
		data->move++;
		ft_putnbr(data->move);
		ft_putstr_fd("\n", 1);
	}
}

void	ft_move_down(t_game *data)
{
	ft_get_player_pos(data);
	data->p_y++;
	if (data->map[data->p_y][data->p_x] != '1')
	{
		if (data->map[data->p_y][data->p_x] == 'E')
		{
			if (data->collector == 0)
				ft_exit(data);
			else
				return ;
		}
		if (data->map[data->p_y][data->p_x] == 'C')
			data->collector--;
		data->map[data->p_y][data->p_x] = 'P';
		img_draw(data, data->img_player, data->p_x, data->p_y);
		data->map[data->p_y - 1][data->p_x] = '0';
		img_draw(data, data->img_floor, data->p_x, (data->p_y - 1));
		data->move++;
		ft_putnbr(data->move);
		ft_putstr_fd("\n", 1);
	}
}

void	ft_move_right(t_game *data)
{
	ft_get_player_pos(data);
	data->p_x++;
	if (data->map[data->p_y][data->p_x] != '1')
	{
		if (data->map[data->p_y][data->p_x] == 'E')
		{
			if (data->collector == 0)
				ft_exit(data);
			else
				return ;
		}
		if (data->map[data->p_y][data->p_x] == 'C')
			data->collector--;
		data->map[data->p_y][data->p_x] = 'P';
		img_draw(data, data->img_player, data->p_x, data->p_y);
		data->map[data->p_y][data->p_x - 1] = '0';
		img_draw(data, data->img_floor, (data->p_x - 1), data->p_y);
		data->move++;
		ft_putnbr(data->move);
		ft_putstr_fd("\n", 1);
	}
}

void	ft_move_left(t_game *data)
{
	ft_get_player_pos(data);
	data->p_x--;
	if (data->map[data->p_y][data->p_x] != '1')
	{
		if (data->map[data->p_y][data->p_x] == 'E')
		{
			if (data->collector == 0)
				ft_exit(data);
			else
				return ;
		}
		if (data->map[data->p_y][data->p_x] == 'C')
			data->collector--;
		data->map[data->p_y][data->p_x] = 'P';
		img_draw(data, data->img_player, data->p_x, data->p_y);
		data->map[data->p_y][data->p_x +1] = '0';
		img_draw(data, data->img_floor, (data->p_x + 1), data->p_y);
		data->move++;
		ft_putnbr(data->move);
		ft_putstr_fd("\n", 1);
	}
}
