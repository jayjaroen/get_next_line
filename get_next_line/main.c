#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

// # include <unistd.h>
// # include <stdlib.h>

// char	*get_next_line(int fd);
// char 	*ft_strjoin(char *s1, char *s2);
// size_t	ft_strlen(char const *s);

int main (void)
{
    char *line;
    int fd = open ("test.txt", O_RDONLY);
    // while (1)
    // {
        line = get_next_line(fd);
        // if (!line)
        //     break ;
        printf ("%s\n", line);
    //     free (line);
    // }
    return (0);
}