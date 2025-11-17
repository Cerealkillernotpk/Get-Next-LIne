/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:15:38 by adakhama          #+#    #+#             */
/*   Updated: 2025/11/17 17:06:32 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_line(char *line, int fd)
{
	char		*buffer;
	int			bn;
	static int	i = 0;
	int			j;

	i = 0;
	bn = 0;
	buffer = 0;
	while (bn == 0)
	{
		j = 0;
		get_read(fd, &bn, buffer);
		if(bn == 0)
		{
			while(j <= BUFFER_SIZE)
			{
				line[i] = buffer[j];
				i++;
				j++;
			}
		}
	}
}
char	*get_read(int fd, int *bn, char *buffer)
{
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	if (ft_strchr(buffer, '\n') == 0)
		bn = 0;
	else
		bn = 1;
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return(NULL);
	line = NULL;
	return(line);
}

/*
ft get next line : remplit les buffer grace a calloc et appele (ft get line);
ft get line : utilise strjoin pour concatener le buffer remplis et la dest qui ne range pas entre chaque appel, elle n'utilise que 3 char*;
ft read : remplis le buffer et utilise strchr pour verifier la presence de '\n' et affecte une valeur a bn en fonction de la veleur du strchr; 
*/