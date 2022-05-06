/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:28:44 by jbatoro           #+#    #+#             */
/*   Updated: 2022/05/05 10:29:50 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Convertion of xpm file to img */
void	*ft_convert_to_img(char *img, t_game *data)
{
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image
		(data->mlx_ptr, img, &data->width, &data->length);
	return (img_ptr);
}

/* Initialize struct with accurate images*/
void	ft_img_init(t_game *data)
{
	data->img_wall = ft_convert_to_img("./images/wall_violet.xpm", data);
	data->img_floor = ft_convert_to_img("./images/background_violet.xpm", data);
	data->img_player = ft_convert_to_img("./images/perso.xpm", data);
	data->img_exit = ft_convert_to_img("./images/door3.xpm", data);
	data->img_collect = ft_convert_to_img("./images/chandelier.xpm", data);
}

/* Print image to window*/
void	img_draw(t_game *data, void *img, int x, int y)
{
	mlx_put_image_to_window
		(data->mlx_ptr, data->mlx_win, img, x * 50, y * 50);
}

/* Replace accurate letter by accurate image */
int	ft_get_char(int i, int j, char letter, t_game *data)
{
	if (letter == '1')
		img_draw(data, data->img_wall, j, i);
	if (letter == '0')
		img_draw(data, data->img_floor, j, i);
	if (letter == 'P')
		img_draw(data, data->img_player, j, i);
	if (letter == 'E')
		img_draw(data, data->img_exit, j, i);
	if (letter == 'C')
		img_draw(data, data->img_collect, j, i);
	return (0);
}

/* Fct to put images to replace each items */
int	ft_draw_map(t_game *data)
{
	int		i;
	int		j;

	ft_img_init(data);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			ft_get_char(i, j, data->map[i][j], data);
			j++;
		}
		i++;
	}
	return (0);
}
