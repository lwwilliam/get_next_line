/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:54:57 by lwilliam          #+#    #+#             */
/*   Updated: 2022/07/18 18:01:08 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	read_funct(int fd, char **buffer, int *x)
{
	int	res;

	res = read(fd, *buffer, BUFFER_SIZE);
	*x = res;
	return (res);
}

void	free_funct(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

char	*get_line(char **str)
{
	size_t	x;
	char	*temp;
	char	*res;

	x = 0;
	while ((*str)[x] && (*str)[x] != '\n')
		x++;
	if ((*str)[x])
	{
		res = ft_substr(*str, 0, x + 1);
		temp = ft_strdup(*str + x + 1);
		free_funct(str);
		if (temp[0] != '\0')
			*str = temp;
		else
			free_funct(&temp);
	}
	else
	{
		res = ft_strdup(*str);
		free_funct(str);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*res[1024];
	char		*buffer;
	char		*temp;
	int			x;

	if ((fd < 0 || fd > 1024) || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (read_funct(fd, &buffer, &x) > 0)
	{
		buffer[x] = 0;
		if (!res[fd])
			res[fd] = ft_strdup("");
		temp = ft_strjoin(res[fd], buffer);
		free_funct(&res[fd]);
		res[fd] = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free_funct(&buffer);
	if (x < 0 || (x == 0 && !res[fd]))
		return (0);
	return (get_line(&res[fd]));
}
