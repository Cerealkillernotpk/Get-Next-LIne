/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:40:07 by adakhama          #+#    #+#             */
/*   Updated: 2025/12/04 16:55:26 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	fd = open("Text.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	line = get_next_line(fd);
	while ((line) != NULL)
	{
		printf("LINE: %s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
