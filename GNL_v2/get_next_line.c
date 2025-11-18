/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:15:38 by adakhama          #+#    #+#             */
/*   Updated: 2025/11/18 15:03:50 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

char	*ft_before_bn(char *buffer)
{
	char	*before_n;
	int		j;

	before_n = 0;
	j = 0;
	while(buffer[j] != '\n' || buffer[j] != '\0' || j != BUFFER_SIZE)
	{
		before_n[j] = 
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int 		len;
	
	len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return(NULL);
	line = ft_strjoin(line, buffer);

	return(line);
}

/*
ft get next line : remplit les buffer grace a calloc et appele (ft get line);
ft get line : utilise strjoin pour concatener le buffer remplis et la dest qui ne range pas entre chaque appel, elle n'utilise que 3 char*;
ft read : remplis le buffer et utilise strchr pour verifier la presence de '\n' et affecte une valeur a bn en fonction de la veleur du strchr; 
*/