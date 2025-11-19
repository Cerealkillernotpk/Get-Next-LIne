/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:15:38 by adakhama          #+#    #+#             */
/*   Updated: 2025/11/19 14:19:01 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
fonction avant n(buffer)
	on a j valant 0
	on a avant_n et apres_n deux char*
	tant que buffer[j] n'est pas un \n ou \0
		mettre avant_n[j] a buffer[j]
		ajouter 1 a j
	return avant_n
strjoin(line, avant_n(buffer))
fonction apres n(buffer)
tant que buffer[i] n'est pas un \n ou \0
	mettre apres_n[i] a buffer[j]
	ajouter 1 a i et a j

	
*/

char	*ft_before_bn(char *buffer, int	*bn, int fd)
{
	char	*before_n = 0;
	int		j;

	before_n = 0;
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if(!buffer)
		return(NULL);
	read(fd, buffer, BUFFER_SIZE);
	before_n = malloc(sizeof(char) * (BUFFER_SIZE));
	if (!before_n)
		return (NULL);
	j = 0;
	while(buffer[j] != '\n' || buffer[j] != '\0' || j != BUFFER_SIZE)
	{
		before_n[j] = buffer[j];
		if(buffer[j] == '\n')
			bn += 1;
		j++;
	}
	return (before_n);
}

char	*ft_after_bn(char *buffer, int fd)
{
	char	*after_n;
	int		i;
	int		j;

	after_n = 0;
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if(!buffer)
		return(NULL);
	read(fd, buffer, BUFFER_SIZE);
	after_n = malloc(sizeof(char) * (BUFFER_SIZE));
	if (!after_n)
		return (NULL);
	i = 0;
	j = 0;
	while (buffer[j] != '\n' || buffer[j] != '\0')
		j++;
	while (j <= BUFFER_SIZE)
	{
		after_n[i] = buffer[j];
	}
	return(after_n);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			bn;
	
	bn = 0;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return(NULL);
	
	line = ft_strjoin(line, buffer);
	while (bn == 0)
	{
		buffer = ft_before_bn(buffer, &bn, fd);
		line = ft_strjoin(line, buffer);
		buffer = ft_after_bn(buffer, fd);
	}
	return(line);
}

# include <stdio.h>

int main()
{
    int fd;
    
    fd = open("Text.txt", O_RDWR);
    printf("%s", get_next_line(fd));
}

/*
ft get next line : remplit les buffer grace a calloc et appele (ft get line);
ft get line : utilise strjoin pour concatener le buffer remplis et la dest qui ne range pas entre chaque appel, elle n'utilise que 3 char*;
ft read : remplis le buffer et utilise strchr pour verifier la presence de '\n' et affecte une valeur a bn en fonction de la veleur du strchr; 
*/