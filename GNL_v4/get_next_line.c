/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:04:43 by adakhama          #+#    #+#             */
/*   Updated: 2025/11/26 17:05:45 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line_bonus.h"

static int	ft_read_fd(int fd, char *buf)
{
	int	r;

	r = read(fd, buf, BUFFER_SIZE);
	if (r <= 0)
	{
		buf[0] = '\0';
		return (-1);
	}
	buf[r] = '\0';
	return (0);
}

static char	*ft_before_bn(char *buf, int *bn)
{
	char	*r;
	int		i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	r = malloc(i + 2);
	if (!r)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		r[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		r[i] = '\n';
		*bn = 1;
		i++;
	}
	r[i] = '\0';
	return (r);
}

static char	*ft_after_bn(char *buf)
{
	int		i;
	char	*r;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
		return (NULL);
	i++;
	r = ft_strdup(buf + i);
	return (r);
}

static void	ft_loop(char **after, char **tmp, char **line, int fd)
{
	char	*before;
	int		bn;

	bn = 0;
	while (!bn)
	{
		before = ft_before_bn(*tmp, &bn);
		if (!before)
			return ;
		*line = ft_strjoin(*line, before);
		free(before);
		if (!*line)
			return ;
		if (bn)
			*after = ft_after_bn(*tmp);
		else if (ft_read_fd(fd, *tmp) < 0)
			return ;
	}
}

char	*get_next_line(int fd)
{
	static char	*after[1024];
	char		*tmp;
	char		*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	line = NULL;
	if (after)
	{
		line = ft_strdup(after);
		free(after);
		after = NULL;
	}
	if (!line && ft_read_fd(fd, tmp) < 0)
		return (free(tmp), NULL);
	ft_loop(&after, &tmp, &line, fd);
	return (free(tmp), line);
}