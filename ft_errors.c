#include "so_long.h"
char	**ft_free(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

/* Return input error and quit properly */
void    ft_input_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

/* Return maps error, free memory and quit properly*/
void    ft_map_error(char *msg, t_game *data)
{
    ft_putendl_fd(msg, 2);
    ft_free(data->map);
    free(data); 
    exit(EXIT_FAILURE);
}