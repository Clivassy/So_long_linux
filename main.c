#include "so_long.h"

/* Check if all lines have the same len */
int ft_check_lines_len(t_game *data)
{
	int i;
	int len;

	len = data->length;
	i = 0;
	while (i < data->width)
	{
		if (i == data->width - 1)
			len = data->length - 1;
		if (ft_strlen(data->map[i]) != len)
			ft_map_error("Error:\nAll line are not equal", data);
		i++;
	}
	printf("OK : all lines are equal\n");
	return (0);
}

int ft_is_one_player(t_game *data)
{
	int i;
	int j;
	data->player = 0;
	i = 0;
	while (i < data->width)
	{
		j = 0;
		while (j < data->length)
		{	
			//printf("%c\n", data->map[i][j]);
			if (data->map[i][j] == 'P')
				data->player++;
			j++;
		}
		i++;
	}
	//printf("%d\n", data->player);
	if (data->player != 1)
		ft_map_error("Error:\nMore or less than one player", data);
	printf("\nOK : only one player\n");
	return (0);
}

void ft_check_c_and_e(int index, int j, t_game *data)
{
	if (data->map[index][j] == 'C')
		data->collector++;
	if (data->map[index][j] == 'E')
		data->exit++;
	// printf("%d\n",input->collector);
	// printf("%d\n",input->exit);
}

void ft_check_columns(t_game *data)
{
	int last_nb;
	int first_nb;
	int j;
	int i;

	i = 0;
	first_nb = 0;
	last_nb = data->length - 2;
	while (i < data->width)
	{
		if (i == data->width - 1)
			last_nb = data->length - 3;
		if (data->map[first_nb][0] != '1' || data->map[first_nb][last_nb] != '1')
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

void ft_check_one_line(char *line, t_game *data)
{
	int i;

	i = 0;
	while (i < ft_strlen(line) - 1)
	{
		if (line[i] != '1')
			ft_map_error("Error:\nap isn't surrounded by walls", data);
		i++;
	}
}

/* Check if map is surrounded by wall */
void ft_check_walls(t_game *data)
{
	int i;
	int last_line;
	int first_line;

	last_line = data->width - 1;
	first_line = 0;
	i = 0;
	if ((int)data->length - 1 == (int)data->width)
		ft_map_error("Error\nMap is square", data);
	ft_check_one_line(data->map[first_line], data);
	ft_check_one_line(data->map[last_line], data);
	ft_check_columns(data);
	printf("OK : map is surrounded by walls\n");
}

/* Check if there is only valid characters in the map */
void ft_check_inside_map(t_game *data)
{
	int j;
	int len;
	int i;

	i = 0;
	len = data->length - 2;
	// printf("%zu\n", ft_strlen(map[0]));
	while (i < data->width)
	{
		j = 0;
		while (j < len)
		{
			// printf("%c",map[i][j]);
			if (i == data->width - 1)
				len = data->length - 3;
			if (data->map[i][j] == '0' || data->map[i][j] == '1' || data->map[i][j] == 'E' 
				|| data->map[i][j] == 'C' || data->map[i][j] == 'P')
				j++;
			else
				ft_map_error("error: map contains invalid characters", data);
		}
		i++;
	}
	printf("OK : map contains only valid characters");
	ft_is_one_player(data);
}

/* Check the input */
void ft_check_input(int argc, char **argv)
{
	if (argc != 2)
		ft_input_error("Error: wrong input: input must be: ./so_long [file.ber]");
    if ((ft_strlen(argv[1]) < 4) || (!ft_strrchr(argv[1], '.')))
		ft_input_error("Error: wrong format: file must be [.ber]");
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
        ft_input_error("Error: wrong format: file must be [.ber]");
}

/* Initialize game structure */
void ft_init_struc(t_game *data, char *file)
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
	data->width = ft_count_lines(file);
  	data->map = ft_create_map(data, file);
	data->length = ft_strlen(data->map[0]);
}

int main(int argc, char **argv)
{
	// attention : penser que carte vide : segfault
	// ++ env -i 

	t_game *data;
	data = NULL;
	ft_check_input(argc, argv);
	data = (t_game *)malloc(sizeof(t_game));
	//data = malloc(sizeof(t_game));
	ft_init_struc(data, argv[1]);
	ft_map_checker(data); 
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, (data->length -1) * 50,  data->width * 50, "SO_LONG");
	ft_draw_map(data);
	mlx_hook(data->mlx_win, 2, 1L << 0, move_event, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, ft_exit, data);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 5, 10, 0xffffff, "Number of moves: ");
	mlx_loop(data->mlx_ptr);
	free(data);
	return (0);
}