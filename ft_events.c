#include "so_long.h"

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
	ft_free(data->map); // free la map 
	free(data->mlx_ptr); // 
	exit(EXIT_SUCCESS);
}
static int	ft_len(long nb)
{
	int		len;

	len = 0;
	if (nb <= 0)
		len = 1;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

static char	*ft_pos_or_neg(char *s, long nb, int n)
{
	if (nb < 0)
	{
		s[0] = '-';
		nb = nb * (-1);
	}
	while (nb > 0)
	{
		s[n] = 48 + (nb % 10);
		nb = nb / 10;
		n--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*s_itoa;

	nb = n;
	len = ft_len(nb);
	s_itoa = (char *)malloc(sizeof(char) * (len + 1));
	if (!s_itoa)
		return (NULL);
	s_itoa[len--] = '\0';
	if (nb == 0)
	{
		s_itoa[0] = 48;
		return (s_itoa);
	}
	s_itoa = ft_pos_or_neg(s_itoa, nb, len);
	return (s_itoa);
}

int	move_event(int key, t_game *data)
{
	mlx_string_put(data->mlx_ptr, data->mlx_win, 20, 30, 0xffffff, ft_itoa(data->move));
	if (key == XK_Escape) // ESC 
		ft_exit(data);
	else if (key == XK_w) // A
		ft_move_up(data);
	else if (key == XK_a) // S 
		ft_move_left(data);
	else if (key == XK_d)
		ft_move_right(data); // D
	else if (key == XK_s)
		ft_move_down(data); // W
	return (0);
}