#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
    int fd = open("test.txt", O_RDONLY, 0);
    printf("%s\n",get_next_line(fd));
    printf("%s\n",get_next_line(fd));
    printf("%s\n",get_next_line(fd));
}