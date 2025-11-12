/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:33:21 by adakhama          #+#    #+#             */
/*   Updated: 2025/11/12 17:56:14 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_get_next_buffer(int fd)
{
	char			str[BUFFER_SIZE + 1];
	static char		*buffer = 0;
	static int		i = 0;
	int				j;

	read(fd, str, BUFFER_SIZE);
	j = 0;
	while(i <= BUFFER_SIZE)
		{
			buffer[i] = str[j];
			i++;
			j++;
		}
	return(buffer);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line;
	static int		i = 0;
	int				j;
	int				k;

	j = 0;
	k = 0;
	buffer = ft_get_next_buffer(fd);
	while (buffer [i])
	{
		if(buffer[i] == '\n')
		else if (buffer[i] != '\n' && buffer[i] == '\0')
			
		i++;	
	}
}
# include <stdio.h>

int main()
{
    int fd;
    
    fd = open("Text.txt", O_RDWR);
    printf("%s", get_next_line(fd));
}