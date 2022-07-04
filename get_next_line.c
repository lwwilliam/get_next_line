/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:54:57 by lwilliam          #+#    #+#             */
/*   Updated: 2022/07/04 14:45:25 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_funct(int fd, char **buffer, int *x)
{
	int	res;
	
	res = read(fd, *buffer, BUFFER_SIZE);
	*x = res;
	return(res);
}

void free_funct(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

char *get_next_line(int fd)
{
	static char	*res;
	char	*buffer;
	char	*temp;
	int	x;

	if (fd < 1 || fd > 1024)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return(NULL);
	while (read_funct(fd, &buffer, &x) < 0)
	{
		buffer[x] = 0;
		if (!res)
			res = ft_strdup("");
		temp = ft_strjoin(res, buffer);
		free_funct(&res);
		res = temp;
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free_funct(&buffer)
	if (x <= 1 || !res)
		return (0);
	return(1);
}