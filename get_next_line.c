/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:33:21 by adakhama          #+#    #+#             */
/*   Updated: 2025/11/12 14:00:27 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_affect_file(char *str, int fd)
{
	int		i;
	
	i = 0;
	read(fd, str, BUFFER_SIZE);
	return(str);
}
static int	ft_get_line_size(char *str)
{
	static int i = 0;
	int j;
	
	j = 0;
	while(str[i] != '\n' || str[i])
		{
			i++;
			j++;
		}
	return(j);
} 
static char *ft_affect_line(char *str, int len)
{
	char *s;
	static int i;
	int j;

	s = 0;
	i = 0;
	j = 0;
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return(NULL);
	while(str[i] != '\n' || str[i])
		{
			s[j] = str[i];
			i++;
			j++;
		}
	return(s);
}

char	*get_next_line(int fd)
{
    char	str[BUFFER_SIZE + 1];
	static char	*str_file;
	char	*s;
	int		l_size;
    
	s = 0;
	str_file = 0;
	str_file =	malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str_file)
		return(NULL);
	str_file = ft_affect_file(str, fd);
	l_size = ft_get_line_size(str_file);
	s = malloc(sizeof(char) * (l_size + 1));
	if (!s)
		return(NULL);
	s = ft_affect_line(str_file, l_size);
	return(s);
}
# include <stdio.h>

int main()
{
    int fd;
    
    fd = open("Text.txt", O_RDWR);
    printf("%s", get_next_line(fd));
}