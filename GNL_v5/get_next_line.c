/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:48:21 by adakhama          #+#    #+#             */
/*   Updated: 2025/11/28 19:51:38 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read(int fd, char *buffer)
{
	int		res;

	res = 0;
	res = read(fd, buffer, BUFFER_SIZE);
	if (res <= 0)
		return (-1);
	buffer[res] = '\0';
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*tmp;
	char		*line;

	line = NULL;
	tmp = NULL;
	tmp = ft_strjoin(tmp, buffer);
	if (buffer)
		free(buffer);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	line = ft_strjoin(line, tmp);
	free(tmp);
	if (ft_read(fd, buffer) < 0)
	{
		free(buffer);
		free(tmp);
		return(NULL);
	}
	while(ft_strchr(buffer, '\n') == 0)
	{
		line = ft_strjoin(line, buffer);
		ft_read(fd, buffer);
	}
	tmp = ft_strchr(buffer, '\n');
	line = ft_strjoin(line, tmp);
	if (ft_strrchr(buffer, '\n') == 0)
		free(buffer);
	else
		buffer = ft_strrchr(buffer, '\n');
	return(line);
}

