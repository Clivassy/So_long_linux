/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:21:27 by jbatoro           #+#    #+#             */
/*   Updated: 2022/05/04 14:24:42 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check the input */
void	ft_check_input(int argc, char **argv)
{
	if (argc != 2)
		ft_input_error("Error: wrong input: ./so_long [file.ber]");
	if ((ft_strlen(argv[1]) < 4) || (!ft_strrchr(argv[1], '.')))
		ft_input_error("Error: wrong format: missing extension");
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
		ft_input_error("Error: wrong format: file must be [.ber]");
}

/* Initialize game structure */
void	ft_init_struc(t_game *data, char *file)
{
	data->move = 1;
	data->img_exit = 0;
	data->img_collect = 0;
	data->img_floor = 0;
	data->img_player = 0;
	data->img_wall = 0;
	data->collector = 0;
	data->exit = 0;
	data->player = 0;
	data->map = ft_read_map(data, file);
	data->length = ft_strlen(data->map[0]);
}

int	main(int argc, char **argv)
{
	t_game	*data;

	data = NULL;
	ft_check_input(argc, argv);
	data = (t_game *)malloc(sizeof(t_game));
	ft_init_struc(data, argv[1]);
	ft_map_checker(data);
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->length * 50,
			data->width * 50, "SO_LONG");
	ft_draw_map(data);
	mlx_hook(data->mlx_win, 2, 1L << 0, move_event, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, ft_exit, data);
	mlx_loop(data->mlx_ptr);
	free(data);
	return (0);
}
