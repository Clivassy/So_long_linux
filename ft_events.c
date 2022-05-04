#include "so_long.h"

/* Quit properly, free all images && map */
int	ft_exit(t_game *data)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_collect);
	mlx_destroy_image(data->mlx_ptr, data->img_exit);
	mlx_destroy_image(data->mlx_ptr, data->img_player);
	mlx_destroy_image(data->mlx_ptr, data->img_floor);
    mlx_destroy_image(data->mlx_ptr, data->img_wall);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr); 
	ft_free(data->map);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}

/* Configure move from keypress*/
int	move_event(int key, t_game *data)
{
	if (key == XK_Escape)
		ft_exit(data);
	else if (key == XK_w)
		ft_move_up(data);
	else if (key == XK_a)
		ft_move_left(data);
	else if (key == XK_d)
		ft_move_right(data);
	else if (key == XK_s)
		ft_move_down(data);
	return (0);
}