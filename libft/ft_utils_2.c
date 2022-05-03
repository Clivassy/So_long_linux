#include "../so_long.h"

char	*ft_strdup(char *s)
{
	int	src_size;
	char	*dest;
	char	*source;
	int		i;

	i = 0;
	source = (char *)s;
	src_size = ft_strlen(s);
	dest = (char *)malloc(src_size * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	while (source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int			count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}
static char	*ft_malloc_word(const char *str, int start, int end)
{
	char	*malloc_w;
	int		i;
	int		len;

	i = 0;
	len = (end - start) + 1;
	malloc_w = (char *)malloc(sizeof(char) * len);
	if (!malloc_w)
		return (0);
	while (start < end)
	{
		malloc_w[i] = str[start];
		i++;
		start++;
	}
	malloc_w[i] = '\0';
	return (malloc_w);
}

static char	**ft_malloc_array(char *s, char **array, char c)
{
	int	i;
	int	j;
	int		index;

	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if ((s[i] != c) && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			array[j] = ft_malloc_word(s, index, i);
			if (!array[j])
				return (ft_free(array));
			index = -1;
			j++;
		}
		i++;
	}
	array[j] = 0;
	return (array);
}

char	**ft_split(char *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	ft_malloc_array(s, array, c);
	return (array);
}