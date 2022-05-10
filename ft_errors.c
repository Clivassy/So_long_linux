/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:30:30 by jbatoro           #+#    #+#             */
/*   Updated: 2022/05/05 10:33:05 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	ft_input_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

/* Error reading map */
void	ft_error_empty_map(t_game *data, char *map)
{
	printf("error:\nWrong Map\n");
	free(map);
	free(data);
	exit(EXIT_FAILURE);
}

/* Return fd error, free and quit properly */
void	ft_fd_error(char *msg, char *map, t_game *data)
{
	ft_putendl_fd(msg, 2);
	free(map);
	free(data);
	exit(EXIT_FAILURE);
}

/* Return maps error, free memory and quit properly*/
void	ft_map_error(char *msg, t_game *data)
{
	ft_putendl_fd(msg, 2);
	ft_free(data->map);
	free(data);
	exit(EXIT_FAILURE);
}
