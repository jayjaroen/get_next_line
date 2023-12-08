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
/// open (0) //stdin --> write test
// fd =0;
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
        {
            // free(line);
            break ;
        }
        printf("%s\n", line);
        free(line);
    }
    // printf("this is the main function call: %s\n", line = get_next_line(fd));
    return (0);
}
