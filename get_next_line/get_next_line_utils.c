/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:07:32 by jbatoro           #+#    #+#             */
/*   Updated: 2022/01/12 11:51:17 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!src || n == 0)
		return (NULL);
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}	

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	if (s1)
	{
		while (s1[i])
			i++;
	}
	j = 0;
	if (s2)
	{
		while (s2[j])
		{
			s1[i] = s2[j];
			i++;
			j++;
		}
		s1[i] = '\0';
		return (s1);
	}
	return (0);
}

char	*ft_strjoin(char *static_buff, char *s2)
{
	char			*str_join;
	unsigned int	len;

	if (static_buff == 0)
	{
		static_buff = (char *)malloc(1 * sizeof(char));
		static_buff[0] = '\0';
	}
	len = ft_strlen(static_buff) + ft_strlen(s2) + 1;
	str_join = (char *)malloc(sizeof(char) * len);
	if (!str_join)
		return (NULL);
	str_join = ft_strcpy(str_join, static_buff);
	str_join = ft_strcat(str_join, s2);
	free(static_buff);
	return (str_join);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
