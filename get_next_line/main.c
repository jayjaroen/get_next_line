#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

// # include <unistd.h>
// # include <stdlib.h>

// char	*get_next_line(int fd);
// char 	*ft_strjoin(char *s1, char *s2);
// size_t	ft_strlen(char const *s);

int main (void)
{
    char *line;
    int fd = open("test.txt", O_RDONLY);
	int	i = 100;

    while (i)
    {
		line = get_next_line(fd);
        printf("%s\n", line);
        free(line);
		i--;
    }
    return (0);
}
