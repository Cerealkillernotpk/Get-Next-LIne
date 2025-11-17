/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:35:29 by adakhama          #+#    #+#             */
/*   Updated: 2025/11/17 13:37:52 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*res;

	i = 0;
	if (nmemb == 0 || size == 0)
	{
		res = malloc(0);
		if (!res)
			return (NULL);
		return (res);
	}
	if (size != 0 && nmemb > (size_t) - 1 / size)
		return (0);
	res = malloc (nmemb * size);
	if (!res)
		return (NULL);
	ft_bzero(res, size * nmemb);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s)
	{
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	str = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}