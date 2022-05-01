#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
//main with arguments
int main(int argc, char **argv)
{
	int fd = 0;
	char *str;

	if (argc < 2)
		printf("File name missing.\n");
	else if (argc > 2)
		printf("Too many arguments.\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Error, cannot open file\n");
			return (1);
		}
		while ((str = get_next_line(fd)) != 0)
		{
			printf("[%s]\n", str);
			free(str);
		}
		printf("\n:End of File\n");
	}
	return (0);
}