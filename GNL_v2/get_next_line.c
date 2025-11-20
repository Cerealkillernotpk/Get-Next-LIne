/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:15:38 by adakhama          #+#    #+#             */
/*   Updated: 2025/11/20 17:33:11 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_read(int fd, char *buffer)
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
			*bn = 1;
	before_n[j] = '\0';
	return (before_n);
}

char	*ft_after_bn(char *buffer)
{
	char	*after_n;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_strdup("");
	while (buffer[j] != '\n' && buffer[j])
		j++;
	if	(!buffer[j])
		return (tmp);
	j++;
	after_n = malloc(sizeof(char) * (BUFFER_SIZE - j + 2));
	if (!after_n)
		return (NULL);
	while (buffer[j])
		after_n[i++] = buffer[j++];
	after_n[i] = '\0';
	return(after_n);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*line;
	char		*before;
	char		*after;
	int			bn;
	
	bn = 0;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return(NULL);
	if (ft_read(fd, tmp) < 0)
	{
		free(tmp);
		return(NULL);
	}
	while (!bn)
	{
		before = ft_before_bn(tmp, &bn);
		line = ft_strjoin(line, before);
		free(before);
		if (bn)
		{
			after = ft_after_bn(tmp);
			free = after;
			break;
		}
		if (ft_read(fd, tmp) < 0)
			break;
	}
	free(tmp);
	return(line);
}

# include <stdio.h>

int main()
{
    int fd;
	char *line;
    
	fd = open("Text.txt", O_RDWR);
	line = get_next_line(fd);
    printf("%s", line);
}

// ft get next line : remplit les buffer grace a calloc et appele (ft get line);
// ft get line : utilise strjoin pour concatener le buffer remplis et la dest qui ne range pas entre chaque appel, elle n'utilise que 3 char*;
// ft read : remplis le buffer et utilise strchr pour verifier la presence de '\n' et affecte une valeur a bn en fonction de la veleur du strchr; 

// fonction avant n(buffer)
// 	on a j valant 0
// 	on a avant_n et apres_n deux char*
// 	tant que buffer[j] n'est pas un \n ou \0
// 		mettre avant_n[j] a buffer[j]
// 		ajouter 1 a j
// 	return avant_n
// strjoin(line, avant_n(buffer))
// fonction apres n(buffer)
// tant que buffer[i] n'est pas un \n ou \0
// 	mettre apres_n[i] a buffer[j]
// 	ajouter 1 a i et a j