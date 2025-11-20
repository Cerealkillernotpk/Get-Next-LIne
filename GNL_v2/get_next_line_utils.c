/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:35:29 by adakhama          #+#    #+#             */
/*   Updated: 2025/11/20 17:57:23 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	unsigned char		*str2;

	str1 = src;
	str2 = dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		str2[i] = str1[i];
		i++;
	}
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (s1)
		i = ft_strlen(s1);
	j = 0;
	if (s2)
		j = ft_strlen(s1);
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return(NULL);
	ft_memcpy(str, s1, i);
	ft_memcpy(str + i, s2, j + 1);
	return (str);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		n;
	char	*dest;

	i = 0;
	n = 0;
	while (src[i])
		i++;
	dest = 0;
	dest = malloc ((i + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (src[n])
	{
		dest[n] = src[n];
		n ++;
	}
	dest[n] = '\0';
	return (dest);
}