/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:15:38 by adakhama          #+#    #+#             */
/*   Updated: 2025/11/26 13:47:59 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_before_bn(char *buffer, int	*bn)
{
	char	*before_n;
	int		j;

	j = 0;
	before_n = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!before_n)
		return (NULL);
	while (buffer[j] != '\n' && buffer[j])
	{
		before_n[j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
	{
		before_n[j] = '\n';
		*bn = 1;
		j++;
	}
	before_n[j] = '\0';
	return (before_n);
}

char	*ft_after_bn(char *buffer)
{
	char	*after_n;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[j] != '\n' && buffer[j])
		j++;
	if (!buffer[j])
		return (NULL);
	j++;
	after_n = malloc(sizeof(char) * (ft_strlen(buffer + j) + 1));
	if (!after_n)
		return (NULL);
	while (buffer[j])
		after_n[i++] = buffer[j++];
	after_n[i] = '\0';
	return (after_n);
}

void	ft_cond(char **after, char **tmp, char **line, int fd)
{
	char		*before;
	int			bn;

	bn = 0;
	while (!bn)
	{
		before = ft_before_bn(*tmp, &bn);
		*line = ft_strjoin(*line, before);
		free(before);
		if (bn)
		{
			*after = ft_after_bn(*tmp);
			break ;
		}
		if (ft_read(fd, *tmp) < 0)
		{
			free(*after);
			*after = NULL;
			break ;
		}
	}
	free(*tmp);
}

char	*get_next_line(int fd)
{
	static char	*after[1024];
	char		*tmp;
	char		*line;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
	{
		free(after[fd]);
		return (NULL);
	}
	ft_bzero(tmp, (BUFFER_SIZE + 1));
	line = NULL;
	if (after[fd])
	{
		line = ft_strjoin(line, after[fd]);
		free(after[fd]);
		after[fd] = NULL;
	}
	if (ft_read(fd, tmp) < 0)
	{
		free(tmp);
		return (NULL);
	}
	ft_cond(&after[fd], &tmp, &line, fd);
	return (line);
}
