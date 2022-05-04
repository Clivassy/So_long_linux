#include "so_long.h"

/* Count lines */
int ft_count_lines(char *file)
{
	char *str;
	int count_line = 0;
	int fd;

	fd = open(file, O_RDONLY);
	while ((str = get_next_line(fd)) != 0)
	{
		count_line++;
		free(str);
	}
	return (count_line);
}

/* Read map */
char	**ft_create_map(char *file)
{
	char	*line;
	char	*all_lines;
	char	**final;
	int		i;
	int		fd;

	i = 0;
	line = "";
	all_lines = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror("error fd");
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	if (all_lines[0] == '\0')
		ft_input_error("error");
	final = ft_split(all_lines, '\n');
	free(all_lines);
	return(final);
}