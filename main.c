#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*s;

	fd = open("test", O_RDONLY);
	while ((s = get_next_line(99999999)) != NULL)
	{
		printf("%s", s);
		free(s);
	}
	return (0);
} 