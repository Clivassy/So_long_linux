#include "so_long.h"

int	ft_exit(t_game *data)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	//mlx_loop_end(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_collect);
	mlx_destroy_image(data->mlx_ptr, data->img_exit);
	mlx_destroy_image(data->mlx_ptr, data->img_player);
	mlx_destroy_image(data->mlx_ptr, data->img_floor);
    mlx_destroy_image(data->mlx_ptr, data->img_wall);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
//	mlx_destroy_display(data->mlx_ptr); a tester sou linux 
	ft_free(data->map); // free la map 
	free(data->mlx_ptr); // 
	exit(EXIT_SUCCESS);
}

int	move_event(int key, t_game *data)
{
	if (key == 53) // ESC 
		ft_exit(data);
	else if (key == 12) // A
		ft_move_up(data);
	else if (key == 1) // S 
		ft_move_left(data);
	else if (key == 2)
		ft_move_right(data); // D
	else if (key == 6)
		ft_move_down(data); // W
	return (0);
}