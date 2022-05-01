#include "so_long.h"
/* Count lines */
int ft_count_lines(char *file)
{
	char *str;
	int count_line = 0;
	int fd;

	fd = open(file, O_RDONLY);
	while ((str = get_next_line(fd)) != 0)
		count_line++;
	return (count_line);
}

/* Allocates memory for a string array with the same lines as the file */
char **malloc_columns(char *file, t_game *data)
{
	int line_count;
    char **map;

	line_count = ft_count_lines(file);
	if (line_count <= 0)
		ft_map_error("error: opening or reading failed: the file may not exist.", data);
	map = malloc(sizeof(char *) * line_count + 1);
	if (map == NULL)
		ft_map_error("error: malloc failed", data);
    return (map);
}

/* Creates -with malloc- a 2D char map as found in file */
char **ft_create_map(t_game *data, char *file)
{
	int fd;
	int i;
    char **map;

	map = malloc_columns(file, data);
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while ((map[i] = get_next_line(fd)) != 0)
		i++;
	map[i] = NULL;
    close(fd);
    return (map);
}

/* print map to terminal */
void ft_print_map(t_game *data)
{
	int j;
	int i;
	i = 0;
	while (i < data->width)
	{
		j = 0;
		while (j < ft_strlen(data->map[0]))
		{
			printf("%c", data->map[i][j]);
			j++;
		}
		i++;
	}
	printf("\n");
}

/* Check all conditions for a valid map*/
void	ft_map_checker(t_game *data)
{
	ft_print_map(data);
	ft_check_lines_len(data);
	ft_check_walls(data);
	ft_check_inside_map(data);
}