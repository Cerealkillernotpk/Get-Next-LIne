/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:15:38 by adakhama          #+#    #+#             */
/*   Updated: 2025/11/20 16:12:46 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_read(int fd, char *buffer)
{
	int		res;

	res = 0;
	if(!buffer)
		return(-1);
	res = read(fd, buffer, BUFFER_SIZE);
	if (res <= 0)
		return (-1);
	buffer[res] = '\0';
	return (0);
}

char	*ft_before_bn(char *buffer, int	*bn)
{
	char	*before_n = 0;
	int		j;
	
	before_n = 0;
	if (buffer == NULL)
		return(NULL);
	before_n = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!before_n)
		return (NULL);
	j = 0;
	while(buffer[j] != '\0' && j != BUFFER_SIZE)
	{
		if (buffer[j] != '\0' && buffer[j] != '\n' && *bn == 0) 
			before_n[j] = buffer[j];
		if(buffer[j] == '\n')
			*bn += 1;
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

	after_n = 0;
	if(!buffer)
		return(NULL);
	after_n = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!after_n)
		return (NULL);
	i = 0;
	j = 0;
	while (buffer[j] != '\n' && buffer[j] != '\0')
		j++;
	while (j <= BUFFER_SIZE && buffer[j] != '\0')
	{
		j++;
		after_n[i] = buffer[j];
		i++;	
	}
	after_n[i] = '\0';
	return(after_n);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp;
	char		*line;
	int			bn;
	
	bn = 0;
	tmp = 0;
	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return(NULL);
	line = ft_strjoin(line, buffer);
	while (bn == 0)
	{
		tmp = ft_calloc(BUFFER_SIZE, sizeof(char));
		bn = ft_read(fd, tmp);
		if (bn < 0)
			return (NULL);
		buffer = ft_before_bn(tmp, &bn);
		line = ft_strjoin(line, buffer);
		if (bn > 0)
			buffer = ft_after_bn(tmp);
		free(tmp);
	}
	return(line);
}

# include <stdio.h>

int main()
{
    int fd = 0;
	char *line;
    
	line = get_next_line(fd);
    fd = open("Text.txt", O_RDWR);
    printf("%s", line);
	free(line);
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