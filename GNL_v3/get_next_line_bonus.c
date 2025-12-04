/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:15:38 by adakhama          #+#    #+#             */
/*   Updated: 2025/11/26 16:37:43 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_read_fd(int fd, char *buffer)
{
	int	res;

	res = read(fd, buffer, BUFFER_SIZE);
	if (res <= 0)
	{
		buffer[0] = '\0';
		return (-1);
	}
	buffer[res] = '\0';
	return (0);
}

static char	*ft_before_bn(char *buffer, int *bn)
{
	char	*before;
	int		i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	before = malloc(i + 2);
	if (!before)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		before[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		before[i] = '\n';
		*bn = 1;
		i++;
	}
	before[i] = '\0';
	return (before);
}

static char	*ft_after_bn(char *buffer)
{
	char	*after;
	int		i;
	int		j;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (NULL);
	i++;
	j = 0;
	while (buffer[i + j])
		j++;
	after = malloc(j + 1);
	if (!after)
		return (NULL);
	j = 0;
	while (buffer[i])
		after[j++] = buffer[i++];
	after[j] = '\0';
	return (after);
}

static void	ft_cond(char **after, char **tmp, char **line, int fd)
{
	char	*before;
	char	*tmp_line;
	int		bn;

	bn = 0;
	while (!bn)
	{
		before = ft_before_bn(*tmp, &bn);
		if (!before)
			break ;
		tmp_line = ft_strjoin(*line, before);
		free(before);
		free(*line);
		*line = tmp_line;
		if (!*line)
			break ;
		if (bn)
		{
			char *tmp_after = ft_after_bn(*tmp);
			if (tmp_after)
				*after = tmp_after;
			break ;
		}
		if (ft_read_fd(fd, *tmp) < 0)
			break ;
	}
	free(*tmp);
}

char	*get_next_line(int fd)
{
	static char	*after[1024];
	char		*tmp;
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	line = NULL;
	if (after[fd])
	{
		line = ft_strjoin(NULL, after[fd]);
		free(after[fd]);
		after[fd] = NULL;
	}
	if (ft_read_fd(fd, tmp) < 0 && !line)
	{
		free(tmp);
		return (NULL);
	}
	ft_cond(&after[fd], &tmp, &line, fd);
	return (line);
}
