/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:15:38 by adakhama          #+#    #+#             */
/*   Updated: 2025/11/18 14:45:06 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
fonction avant n(buffer)
	on a j valant chacun 0
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

int	get_line(char *line, int fd, int len)
{
	char		*buffer;
	static char	*tmp;
	int			bn;
	int			j;

	bn = 0;
	tmp = 0;
	buffer = 0;
	while (bn == 0)
	{
		j = 0;
		get_read(fd, &bn, buffer);
		while(j <= BUFFER_SIZE)
		{
			line[len] = buffer[j];
			len++;
			j++;
		}
	}
	line = strchr(line, '\n');
	tmp[j] = line[len]
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
	int 		len;
	
	len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return(NULL);
	line = NULL;
	line = malloc(sizeof(char) * (get_line(line, fd) + 1));
	return(line);
}

/*
ft get next line : remplit les buffer grace a calloc et appele (ft get line);
ft get line : utilise strjoin pour concatener le buffer remplis et la dest qui ne range pas entre chaque appel, elle n'utilise que 3 char*;
ft read : remplis le buffer et utilise strchr pour verifier la presence de '\n' et affecte une valeur a bn en fonction de la veleur du strchr; 
*/